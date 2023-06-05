#include "../include/mergesort.hpp"


// Função auxiliar para mesclar dois subarrays ordenados em ordem crescente do ângulo
void merge(PontoCartesiano arr[], int Esquerda, int Meio, int Direita, const PontoCartesiano& pontoInicial)
{
    int size1 = Meio - Esquerda + 1;
    int size2 = Direita - Meio;

    // Criar arrays temporários
    PontoCartesiano* tempEsquerda = new PontoCartesiano[size1];
    PontoCartesiano* tempDireita = new PontoCartesiano[size2];

    // Copiar os dados para os arrays temporários
    for (int i = 0; i < size1; ++i) {
        tempEsquerda[i] = arr[Esquerda + i];
    }
    for (int j = 0; j < size2; ++j) {
        tempDireita[j] = arr[Meio + 1 + j];
    }

    // Índices iniciais dos subarrays temporários
    int indexEsquerda = 0;
    int indexDireita = 0;

    // Índice inicial do subarray mesclado
    int indexMerged = Esquerda;

    // Comparar os pontos com base nas coordenadas Y e X
    while (indexEsquerda < size1 && indexDireita < size2) {
        if (tempEsquerda[indexEsquerda].getY() < tempDireita[indexDireita].getY()) {
            arr[indexMerged] = tempEsquerda[indexEsquerda];
            ++indexEsquerda;
        } else if (tempEsquerda[indexEsquerda].getY() == tempDireita[indexDireita].getY()) {
            if (tempEsquerda[indexEsquerda].getX() < tempDireita[indexDireita].getX()) {
                arr[indexMerged] = tempEsquerda[indexEsquerda];
                ++indexEsquerda;
            } else {
                arr[indexMerged] = tempDireita[indexDireita];
                ++indexDireita;
            }
        } else {
            arr[indexMerged] = tempDireita[indexDireita];
            ++indexDireita;
        }
        ++indexMerged;
    }

    // Copiar os elementos restantes do subarray temporário esquerdo
    while (indexEsquerda < size1) {
        arr[indexMerged] = tempEsquerda[indexEsquerda];
        ++indexEsquerda;
        ++indexMerged;
    }

    // Copiar os elementos restantes do subarray temporário direito
    while (indexDireita < size2) {
        arr[indexMerged] = tempDireita[indexDireita];
        ++indexDireita;
        ++indexMerged;
    }

    // Liberar a memória alocada pelos arrays temporários
    delete[] tempEsquerda;
    delete[] tempDireita;

    // Ordenar os pontos além do primeiro com base no ângulo em relação ao ponto inicial
    for (int i = Esquerda + 1; i <= Direita; ++i) {
        for (int j = i + 1; j <= Direita; ++j) {
            double angulo1 = arr[Esquerda].calcularAngulo(arr[i]);
            double angulo2 = arr[Esquerda].calcularAngulo(arr[j]);
            if (angulo1 > angulo2) {
                PontoCartesiano temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Função principal do algoritmo Merge Sort
void mergeSort(PontoCartesiano arr[], int Esquerda, int Direita, const PontoCartesiano& pontoInicial)
{
    if (Esquerda < Direita) {
        int Meio = Esquerda + (Direita - Esquerda) / 2;

        // Ordenar a metade esquerda
        mergeSort(arr, Esquerda, Meio, pontoInicial);

        // Ordenar a metade direita
        mergeSort(arr, Meio + 1, Direita, pontoInicial);

        // Mesclar as duas metades ordenadas
        merge(arr, Esquerda, Meio, Direita, pontoInicial);
    }
}
