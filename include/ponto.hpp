#ifndef PONTO_HPP
#define PONTO_HPP

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "memlog.h"

class PontoCartesiano {
private:
    int x;
    int y;

public:
    PontoCartesiano();
    PontoCartesiano(int xCoord, int yCoord);
    int getX() const;
    int getY() const;
    void setX(int xCoord);
    void setY(int yCoord);
    double calcularAngulo(const PontoCartesiano& pontoReferencia) const;
    static void imprimePontos(const PontoCartesiano arr[], int tamanho);
    double calcularDistancia(const PontoCartesiano& pontoReferencia) const;
};

PontoCartesiano encontrarPrimeiroPonto(PontoCartesiano arr[], int tamanho);

#endif  // PONTO_HPP
