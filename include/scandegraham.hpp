#ifndef SCANDEGRAHAM_HPP
#define SCANDEGRAHAM_HPP

#include "poligono.hpp"

int orientacao(PontoCartesiano a, PontoCartesiano b, PontoCartesiano c);
FechoConvexo scanDeGraham(PontoCartesiano arr[], int n, FechoConvexo& fechoConvexo);

#endif