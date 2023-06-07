#include "../include/leituraArquivo.hpp"
#include "../include/poligono.hpp"
#include "../include/mergesort.hpp"
#include "../include/insertionsort.hpp"
#include "../include/bucketsort.hpp"
#include "../include/scandegraham.hpp"
#include "../include/marchardejarvis.hpp"
#include <ctime>

char texto[100];
//array de PontoCartesiano
PontoCartesiano* pontos = NULL;
int tamanho = 0;

void LeituraArquivo(char *nomeArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while(fgets(texto, 10000, arquivo) != NULL){
        int posicaoX = atoi(strtok(texto, " "));
        int posicaoY = atoi(strtok(NULL, " "));
        PontoCartesiano ponto(posicaoX, posicaoY);
        // Redimensionar o array para armazenar o novo ponto
        tamanho++;
        pontos = (PontoCartesiano*)realloc(pontos, tamanho * sizeof(PontoCartesiano));
        pontos[tamanho - 1] = ponto;
    }
    fclose(arquivo);
}

void avaliaTempo(){
    PontoCartesiano* pontos1 = (PontoCartesiano*)malloc((tamanho) * sizeof(PontoCartesiano));
    PontoCartesiano* pontos2 = (PontoCartesiano*)malloc((tamanho) * sizeof(PontoCartesiano));
    PontoCartesiano* pontos3 = (PontoCartesiano*)malloc((tamanho) * sizeof(PontoCartesiano));
    PontoCartesiano* pontos4 = (PontoCartesiano*)malloc((tamanho) * sizeof(PontoCartesiano));
    FechoConvexo fechoConvexo;
    PontoCartesiano primeiroPonto = encontrarPrimeiroPonto(pontos1, tamanho);
    //Primeiro, copiar os pontos para 4 arrays separados
    for(int i = 0; i < tamanho; i++){
        //Cada array precisa ser alocado dinamicamente do mesmo tamanho do array pontos
        pontos1[i] = pontos[i];
        pontos2[i] = pontos[i];
        pontos3[i] = pontos[i];
        pontos4[i] = pontos[i];
    }

    //Para cada array, iremos usar um método diferente e calcular o seu tempo de execução

    //Mergesort com scan de graham
    long before1 = clock();
    mergeSort(pontos1, 0, tamanho -1, primeiroPonto);
    scanDeGraham(pontos1, tamanho, fechoConvexo);
    long after1 = clock();
    double elapsed1 = (double)(after1 - before1)/CLOCKS_PER_SEC;
    printf("GRAHAM + MERGESORT: %.3lfs\n", elapsed1); 

    //Insertionsort com scan de graham
    long before2 = clock();
    insertionSort(pontos2, tamanho, primeiroPonto);
    scanDeGraham(pontos2, tamanho, fechoConvexo);
    long after2 = clock();
    double elapsed2 = (double)(after2 - before2)/CLOCKS_PER_SEC;
    printf("GRAHAM + INSERTIONSORT: %.3lfs\n", elapsed2); 

    //Bucketsort com scan de graham
    long before3 = clock();
    bucketSort(pontos3, tamanho, primeiroPonto);
    scanDeGraham(pontos3, tamanho, fechoConvexo);
    long after3 = clock();
    double elapsed3 = (double)(after3 - before3)/CLOCKS_PER_SEC;
    printf("GRAHAM + BUCKETSORT: %.3lfs\n", elapsed3);

    //Marchar de jarvis
    long before4 = clock();
    marchaDeJarvis(pontos4, tamanho, fechoConvexo);
    long after4 = clock();
    double elapsed4 = (double)(after4 - before4)/CLOCKS_PER_SEC;
    printf("JARVIS: %.3lfs\n", elapsed4);

    free(pontos1);
    free(pontos2);
    free(pontos3);
    free(pontos4);
}

void executaOperacoes(int n){
    FechoConvexo fechoConvexo;
    PontoCartesiano primeiroPonto = encontrarPrimeiroPonto(pontos, tamanho);

    //Usar o mergesort para ordenar os pontos
    if(n == 1){
        mergeSort(pontos, 0, tamanho - 1, primeiroPonto);
        //PontoCartesiano::imprimePontos(pontos, tamanho);
    }

    //Usar o insertionsort para ordenar os pontos
    if(n == 2){
        insertionSort(pontos, tamanho, primeiroPonto);
        //PontoCartesiano::imprimePontos(pontos, tamanho);
        }

    //Usar o radixsort para ordenar os pontos
    if(n == 3){
        bucketSort(pontos, tamanho, primeiroPonto);
        //PontoCartesiano::imprimePontos(pontos, tamanho);
    }
    
    if(n == 4){
        fechoConvexo = marchaDeJarvis(pontos, tamanho, fechoConvexo);
        printf("\nFecho Convexo:\n");
        fechoConvexo.imprimirFechoConvexo();
    }

    //Após ter os pontos ordenados, executar o scan de graham
    if(n != 4){
        printf("\nFecho Convexo:\n");
        scanDeGraham(pontos, tamanho, fechoConvexo);
        fechoConvexo.imprimirFechoConvexo();
    }

    avaliaTempo();

    //Imprimir as retas matemáticas do fecho para ganhar ponto extra
    printf("\nRetas matemáticas do fecho para ponto extra:\n");
    fechoConvexo.imprimirRetasMatematicaDoFecho();

    free(pontos);
}