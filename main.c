#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"

int main(){
    double **a, *b, *x;
    int tam;
    scanf ("%d", &tam);
    a = malloc (tam * sizeof (double *));
    for (int i = 0; i < tam; i++){
        a[i] = malloc (tam * sizeof (double));
    }
    b = malloc (tam * sizeof (double));
    x = malloc (tam * sizeof (double));
    leMatriz (a, b, tam);
    //gaussComMult (a, b, tam);
    //semPivo (a, b, tam);
    gaussSemMult (a, b, tam);
    imprimeMatriz (a, b, tam);
    retroSub (a, b, x, tam);
    for (int i = 0; i < tam; i++){
        printf ("%lf\n", x[i]);
    }
    calculaResiduo (a, b, x, tam);
    free (b);
    free (x);
    for (int i = 0; i < tam; i++){
        free (a[i]);
    }
    free (a);
    return 0;
}