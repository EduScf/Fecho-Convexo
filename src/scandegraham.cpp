#include "../include/scandegraham.hpp"

int orientacao(PontoCartesiano a, PontoCartesiano b, PontoCartesiano c){

    int val = (b.getY() - a.getY()) * (c.getX() - b.getX()) - (b.getX() - a.getX()) * (c.getY() - b.getY());
    if (val == 0)
    {
        return 0; // colinear
    }
    else
    {
        if(val > 0) 
        {
            return 1; //horário
        }
        else
        {
            return 2; //anti-horário
        }
    }
}
    

FechoConvexo scanDeGraham(PontoCartesiano arr[], int tamanho, FechoConvexo& fechoConvexo) {
    //Primeiro, iremos criar um array com todos os pontos que vão formar as retas do Fecho Convexo
    //O primeiro ponto do fecho convexo é o ponto inicial, como o array ja esta ordenado, é o arr[0]
    PontoCartesiano* pontosFechoConvexo = (PontoCartesiano*)malloc(tamanho * sizeof(PontoCartesiano));
    pontosFechoConvexo[0] = arr[0];
    pontosFechoConvexo[1] = arr[1];
    pontosFechoConvexo[2] = arr[2];
    int tamanhoFechoConvexo = 3;
    //Agora, iremos percorrer o array de pontos ordenados, quando a orientação de um ponto para o próximo for anti-horário, iremos adicionar o ponto ao fecho convexo
    //Se o ponto for horário, iremos remover os pontos até que a orientação seja anti-horário
    for(int i = 3; i < tamanho; i++)
    {
        while(tamanhoFechoConvexo >=2 && orientacao(pontosFechoConvexo[tamanhoFechoConvexo - 2], pontosFechoConvexo[tamanhoFechoConvexo - 1], arr[i]) != 2)
        {
            tamanhoFechoConvexo--;
        }
        pontosFechoConvexo[tamanhoFechoConvexo] = arr[i];
        tamanhoFechoConvexo++;
    }
    //Agora, iremos adicionar as retas ao fecho convexo
    for(int i = 0; i < tamanhoFechoConvexo - 1; i++)
    {
        Reta reta(pontosFechoConvexo[i], pontosFechoConvexo[i + 1]);
        fechoConvexo.adicionarReta(reta);
    }
    //Conectar o último ponto com o primeiro
    Reta reta(pontosFechoConvexo[tamanhoFechoConvexo - 1], pontosFechoConvexo[0]);
    fechoConvexo.adicionarReta(reta);
    free(pontosFechoConvexo);
    return fechoConvexo;
}