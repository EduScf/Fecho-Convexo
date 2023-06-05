#include "../include/marchardejarvis.hpp"

FechoConvexo marchaDeJarvis(PontoCartesiano pontos[], int tamanho, FechoConvexo fecho){
    // There must be at least 3 pontos
    if (tamanho < 3) return fecho;
  
    //Inicializar um array para conter os pontos que o feco terá
    PontoCartesiano* PontosFecho =  (PontoCartesiano*)malloc(tamanho * sizeof(PontoCartesiano));
    int tamanhoFechoConvexo = 0;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < tamanho; i++)
        if (pontos[i].getX() < pontos[l].getX())
            l = i;
  
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of pontos in result or output.
    int p = l, q;
    do
    {
        // Redimensionar o array para adicionar o novo ponto
        PontosFecho[tamanhoFechoConvexo] = pontos[p];
        tamanhoFechoConvexo++;

        // Search for a point 'q' such that orientation(p, q,
        // x) is counterclockwise for all pontos 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%tamanho;
        for (int i = 0; i < tamanho; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientacao(pontos[p], pontos[i], pontos[q]) == 2)
               q = i;
        }
  
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
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