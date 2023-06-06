#include "../include/insertionsort.hpp"
#include "../include/leituraArquivo.hpp"
#include "../include/reta.hpp"
#include "../include/ponto.hpp"
#include "../include/mergesort.hpp"
#include "../include/scandegraham.hpp"

int main(int argc, char *argv[]){ 
    if (argc != 2){
        printf("Use: %s <nome do arquivo>\n", argv[0]);
        exit(1);
    }
    LeituraArquivo(argv[1]);
    /*
    Para usar o executaOperacoes:
    1- Mergesort
    2- Insertionsort
    3- BucketSort
    4- Marcha de Jarvis
    */
    executaOperacoes(4);
    return 0;
}