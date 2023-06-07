#include "../include/ponto.hpp"

PontoCartesiano::PontoCartesiano() {
    x = 0;
    y = 0;
}

PontoCartesiano::PontoCartesiano(int x, int y) {
    this->x = x;
    this->y = y;
}

int PontoCartesiano::getX() const {
    return x;
}

int PontoCartesiano::getY() const {
    LEMEMLOG((long int)(this->y),sizeof(int),1);
    return y;
}

void PontoCartesiano::setX(int x) {
    this->x = x;
}

void PontoCartesiano::setY(int y) {
    this->y = y;
}

double PontoCartesiano::calcularAngulo(const PontoCartesiano& pontoReferencia) const {
    // Calcular o ângulo em relação ao ponto de referência
    int deltaX = pontoReferencia.x - x;
    int deltaY = pontoReferencia.y - y;

    // Calcular o arco tangente e converter para graus
    double anguloRad = std::atan2(deltaY, deltaX);
    double anguloGraus = anguloRad * 180.0 / M_PI;

    // Ajustar o ângulo para estar no intervalo de 0 a 360 graus
    if (anguloGraus < 0) {
        anguloGraus += 360.0;
    }

/*    // Adicionar 180 graus para inverter a ordem (de modo que o ponto inicial seja o menor)
    anguloGraus += 180.0;

    // Ajustar novamente o ângulo para estar no intervalo de 0 a 360 graus
    if (anguloGraus >= 360.0) {
        anguloGraus -= 360.0;
    }
*/
    return anguloGraus;
}


void PontoCartesiano::imprimePontos(const PontoCartesiano arr[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        int x = arr[i].getX();
        int y = arr[i].getY();
        std::cout << "Ponto " << i + 1 << ": (" << x << ", " << y << ")" << std::endl;
    }
}

/*PontoCartesiano PontoCartesiano::encontrarPrimeiroPonto(PontoCartesiano arr[], int tamanho) {
    PontoCartesiano primeiroPonto = arr[0];

    for (int i = 1; i < tamanho; ++i) {
        int coordenadaYAtual = arr[i].getY();
        int coordenadaYMenor = primeiroPonto.getY();

        if (coordenadaYAtual < coordenadaYMenor) {
            primeiroPonto = arr[i];
        } else if (coordenadaYAtual == coordenadaYMenor) {
            int coordenadaXAtual = arr[i].getX();
            int coordenadaXMenor = primeiroPonto.getX();

            if (coordenadaXAtual < coordenadaXMenor) {
                primeiroPonto = arr[i];
            }
        }
    }
    return primeiroPonto;
}*/

double PontoCartesiano::calcularDistancia(const PontoCartesiano& pontoReferencia) const {
    // Calcular a distância entre dois pontos
    int deltaX = pontoReferencia.x - x;
    int deltaY = pontoReferencia.y - y;

    // Calcular a distância usando o teorema de Pitágoras
    double distancia = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    return distancia;
}

PontoCartesiano encontrarPrimeiroPonto(PontoCartesiano arr[], int tamanho) {
    PontoCartesiano primeiroPonto = arr[0];

    for (int i = 1; i < tamanho; ++i) {
        int coordenadaYAtual = arr[i].getY();

        int coordenadaYMenor = primeiroPonto.getY();

        if (coordenadaYAtual < coordenadaYMenor) {
            primeiroPonto = arr[i];
        } else if (coordenadaYAtual == coordenadaYMenor) {
            int coordenadaXAtual = arr[i].getX();
            int coordenadaXMenor = primeiroPonto.getX();

            if (coordenadaXAtual < coordenadaXMenor) {
                primeiroPonto = arr[i];
            }
        }
    }
    return primeiroPonto;
}
