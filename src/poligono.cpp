#include "../include/poligono.hpp"
#include <iostream>

FechoConvexo::FechoConvexo() : quantidadeRetas(0) {}

void FechoConvexo::adicionarReta(const Reta& reta) {
    if (quantidadeRetas < MAX_RETAS) {
        retas[quantidadeRetas] = reta;
        quantidadeRetas++;
    }
}

void FechoConvexo::removerReta() {
    if (quantidadeRetas > 0) {
        quantidadeRetas--;
    }
}

Reta* FechoConvexo::getRetas() {
    return retas;
}

int FechoConvexo::getQuantidadeRetas() const {
    return quantidadeRetas;
}

void FechoConvexo::imprimirFechoConvexo() const {
    for (int i = 0; i < quantidadeRetas; i++) {
        const Reta& reta = retas[i];
        const PontoCartesiano& ponto1 = reta.getPonto1();
        std::cout << "(" << ponto1.getX() << ", " << ponto1.getY() << ")" << std::endl;
    }
}
