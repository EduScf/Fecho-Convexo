#include "../include/insertionsort.hpp"

void trocarPontos(PontoCartesiano arr[], int i, int j)
{
    PontoCartesiano temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(PontoCartesiano arr[], int n, PontoCartesiano pontoInicial)
{   
    for (int i = 0; i < n; i++)
    {
        PontoCartesiano chave = arr[i];
        int j = i - 1;

        // Comparar os ângulos em relação ao ponto inicial
        while (j >= 0 && arr[j].calcularAngulo(pontoInicial) > chave.calcularAngulo(pontoInicial))
        {
            //arr[j + 1] = arr[j];
            trocarPontos(arr, j, j+1);
            j--;
        }

        // Lidar com pontos colineares
        while (j >= 0 && arr[j].calcularAngulo(pontoInicial) == chave.calcularAngulo(pontoInicial) && arr[j].calcularDistancia(pontoInicial) > chave.calcularDistancia(pontoInicial))
        {
            //arr[j + 1] = arr[j];
            trocarPontos(arr, j, j+1);
            j--;
        }
        if(j >= 0)
            arr[j + 1] = chave;
    }
}