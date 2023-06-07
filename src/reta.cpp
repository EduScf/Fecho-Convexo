#include "../include/reta.hpp"
#include <cmath>

Reta::Reta() {
    ponto1 = PontoCartesiano();
    ponto2 = PontoCartesiano();
}

Reta::Reta(const PontoCartesiano& p1, const PontoCartesiano& p2) {
    ponto1 = p1;
    ponto2 = p2;
}

PontoCartesiano Reta::getPonto1() const {
    return ponto1;
}

PontoCartesiano Reta::getPonto2() const {
    return ponto2;
}

void Reta::setPonto1(const PontoCartesiano& p1) {
    ponto1 = p1;
}

void Reta::setPonto2(const PontoCartesiano& p2) {
    ponto2 = p2;
}

double Reta::calcularComprimento() const {
    double x1 = ponto1.getX();
    double y1 = ponto1.getY();
    double x2 = ponto2.getX();
    double y2 = ponto2.getY();

    double comprimento = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return comprimento;
}

double Reta::calcularCoeficienteAngular() const {
    double x1 = ponto1.getX();
    double y1 = ponto1.getY();
    double x2 = ponto2.getX();
    double y2 = ponto2.getY();

    double coeficienteAngular = (y2 - y1) / (x2 - x1);
    return coeficienteAngular;
}

double Reta::calcularCoeficienteLinear() const {
    double x1 = ponto1.getX();
    double y1 = ponto1.getY();

    double coeficienteAngular = calcularCoeficienteAngular();
    double coeficienteLinear = y1 - coeficienteAngular * x1;
    return coeficienteLinear;
}

void Reta::imprimirReta() const {
    printf("Reta: (%d, %d) -> (%d, %d)\n", ponto1.getX(), ponto1.getY(), ponto2.getX(), ponto2.getY());
}

void Reta::imprimirRetaMatematica() const{
    double coeficienteAngular = calcularCoeficienteAngular();
    double coeficienteLinear = calcularCoeficienteLinear();
    printf("Reta: y = %.2lfx + %.2lf\n", coeficienteAngular, coeficienteLinear);
}