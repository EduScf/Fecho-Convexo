#include "../include/marchardejarvis.hpp"

FechoConvexo marchaDeJarvis(PontoCartesiano pontos[], int tamanho, FechoConvexo fecho){
    // There must be at least 3 pontos
    if (tamanho < 3) return fecho;
  
    //Inicializar um array para conter os pontos que o feco terá
    PontoCartesiano* PontosFecho =  (PontoCartesiano*)malloc(tamanho * sizeof(PontoCartesiano));
    int tamanhoFechoConvexo = 0;

    // Achar o ponto mais a esquerda
    int l = 0;
    for (int i = 1; i < tamanho; i++)
        if (pontos[i].getX() < pontos[l].getX())
            l = i;
  
    //Começar do ponto mais a esquerda, continuar no sentido anti-horário
    //Enquanto não chegar no ponto inicial novamente. Este loop roda O(h)
    // vezes onde h é o numero de pontos de resultado ou saída
    int p = l, q;
    do
    {
        // Redimensionar o array para adicionar o novo ponto
        PontosFecho[tamanhoFechoConvexo] = pontos[p];
        tamanhoFechoConvexo++;

        // Procuar por um ponto 'q' tal que a orientação(p, q,
        // x) é anti-horária para todos os pontos 'x'. A ideia
        // é continuar buscando o ultimo ponto visitado mais no sentido
        // anti-horário possivel em q. Se qualquer ponto 'i' é mais
        // anti-horario que o q, atualizar o q.
        q = (p+1)%tamanho;
        for (int i = 0; i < tamanho; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientacao(pontos[p], pontos[i], pontos[q]) == 2)
               q = i;
        }
  
        // Agora o q é o ponto mais anti-horário que respeita o p
        // Setar p como q para a próxima iteração, para que o q seja
        // adicionada ao PontosFecho.
        p = q;
  
    } while (p != l);  // While we don't come to first point

    //Agora, iremos adicionar as retas ao fecho convexo
    for(int i = 0; i < tamanhoFechoConvexo - 1; i++)
    {
        Reta reta(PontosFecho[i], PontosFecho[i + 1]);
        fecho.adicionarReta(reta);
    }

    //Conectar o último ponto com o primeiro
    Reta reta(PontosFecho[tamanhoFechoConvexo - 1], PontosFecho[0]);
    fecho.adicionarReta(reta);
    
    free(PontosFecho);
    return fecho;
}