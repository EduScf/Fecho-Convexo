#ifndef POLIGONO_HPP
#define POLIGONO_HPP

#include "ponto.hpp"
#include "reta.hpp"

const int MAX_RETAS = 100;  // Número máximo de retas no fecho convexo

class FechoConvexo {
private:
    Reta retas[MAX_RETAS];
    int quantidadeRetas;

public:
    FechoConvexo();
    void adicionarReta(const Reta& reta);
    void removerReta();
    Reta* getRetas();
    int getQuantidadeRetas() const;
    void imprimirFechoConvexo() const;
};

#endif
