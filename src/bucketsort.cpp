#include "../include/bucketsort.hpp"

// Função auxiliar para calcular o ângulo em relação ao ponto inicial
double calcularAnguloBucket(const PontoCartesiano& ponto1, const PontoCartesiano& ponto2) {
    int deltaX = ponto2.getX() - ponto1.getX();
    int deltaY = ponto2.getY() - ponto1.getY();
    return std::atan2(deltaY, deltaX);
}

void bucketSort(PontoCartesiano arr[], int tamanho, const PontoCartesiano& pontoInicial) {
    // Definir o número de buckets igual ao tamanho do array
    int numBuckets = tamanho;

    // Criar os buckets
    PontoCartesiano** buckets = new PontoCartesiano*[numBuckets];
    int* bucketSizes = new int[numBuckets];

    // Inicializar os tamanhos dos buckets como 0
    for (int i = 0; i < numBuckets; ++i) {
        bucketSizes[i] = 0;
        buckets[i] = nullptr;
    }

    // Colocar cada ponto no bucket correspondente
    for (int i = 0; i < tamanho; ++i) {
        double angulo = calcularAnguloBucket(pontoInicial, arr[i]);
        int bucketIndex = (int)(angulo * numBuckets / 360.0);

        // Aumentar o tamanho do bucket e adicionar o ponto
        int newSize = bucketSizes[bucketIndex] + 1;
        PontoCartesiano* newBucket = new PontoCartesiano[newSize];

        // Copiar os pontos anteriores para o novo bucket
        for (int j = 0; j < bucketSizes[bucketIndex]; ++j) {
            newBucket[j] = buckets[bucketIndex][j];
        }

        // Adicionar o novo ponto ao final do novo bucket
        newBucket[newSize - 1] = arr[i];

        // Atualizar o tamanho e o bucket
        bucketSizes[bucketIndex] = newSize;
        delete[] buckets[bucketIndex];
        buckets[bucketIndex] = newBucket;
    }

    // Ordenar cada bucket individualmente (usando qualquer algoritmo de ordenação)
    for (int i = 0; i < numBuckets; ++i) {
        int bucketSize = bucketSizes[i];
        PontoCartesiano* bucket = buckets[i];

        if (bucketSize > 1) {
            // Ordenar pontos colineares usando bubble sort
            for (int j = 0; j < bucketSize - 1; ++j) {
                for (int k = 0; k < bucketSize - j - 1; ++k) {
                    double angulo1 = calcularAnguloBucket(pontoInicial, bucket[k]);
                    double angulo2 = calcularAnguloBucket(pontoInicial, bucket[k + 1]);

                    if (angulo1 > angulo2 || (angulo1 == angulo2 && bucket[k].calcularDistancia(pontoInicial) > bucket[k + 1].calcularDistancia(pontoInicial))) {
                        // Trocar os pontos
                        PontoCartesiano temp = bucket[k];
                        bucket[k] = bucket[k + 1];
                        bucket[k + 1] = temp;
                    }
                }
            }
        }
    }

    // Concatenar os pontos ordenados em um novo array
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        int bucketSize = bucketSizes[i];
        PontoCartesiano* bucket = buckets[i];

        for (int j = 0; j < bucketSize; ++j) {
            arr[index++] = bucket[j];
        }

        delete[] bucket;
    }

    // Liberar a memória alocada
    delete[] buckets;
    delete[] bucketSizes;
}
