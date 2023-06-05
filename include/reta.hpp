#ifndef RETA_HPP
#define RETA_HPP

#include "../include/ponto.hpp"

class Reta {
private:
    PontoCartesiano ponto1;
    PontoCartesiano ponto2;
    double coeficienteAngular;
    double coeficienteLinear;

public:
    Reta();
    Reta(const PontoCartesiano& p1, const PontoCartesiano& p2);
    PontoCartesiano getPonto1() const;
    PontoCartesiano getPonto2() const;
    void setPonto1(const PontoCartesiano& p1);
    void setPonto2(const PontoCartesiano& p2);
    double calcularComprimento() const;
    double calcularCoeficienteAngular() const;
    double calcularCoeficienteLinear() const;
    void imprimirReta() const;
};

#endif  // RETA_HPP