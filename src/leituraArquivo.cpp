#include "../include/leituraArquivo.hpp"
#include "../include/poligono.hpp"
#include "../include/mergesort.hpp"
#include "../include/insertionsort.hpp"
#include "../include/bucketsort.hpp"
#include "../include/scandegraham.hpp"
#include "../include/marchardejarvis.hpp"

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

    free(pontos);
}