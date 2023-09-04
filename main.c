#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"

int main(){
    double **a, **a2, *b, *b2, *x;
    int tam;
    void (*metodo[3]) (double **, double *, int);
    metodo[0] = gaussComMult;
    metodo[1] = gaussSemMult;
    metodo[2] = semPivo;
    scanf ("%d", &tam);
    a = malloc (tam * sizeof (double *));
    a2 = malloc (tam * sizeof (double *));
    for (int i = 0; i < tam; i++){
        a[i] = malloc (tam * sizeof (double));
        a2[i] = malloc (tam * sizeof (double));
    }
    b = malloc (tam * sizeof (double));
    b2 = malloc (tam * sizeof (double));
    x = malloc (tam * sizeof (double));
    leMatriz (a, b, tam);
    copiaMatriz (a, a2, b, b2, tam);
    for (int i = 0; i<3;i++){
        switch (i){
            case 0:
                printf ("Gauss com multiplicador\n\n");
                break;
            case 1:
                printf ("Gauss sem multiplicador\n\n");
                break;
            case 2:
                printf ("Sem pivoteamento\n\n");
                break;
        }
        metodo[i](a, b, tam);
        imprimeMatriz (a, b, tam);
        retroSub (a, b, x, tam);
        printf ("\nSolução:\n\n");
        for (int i = 0; i < tam; i++){
            printf ("%lf ", x[i]);
        }
        printf ("\n\nResíduo:\n\n");
        calculaResiduo (a, b, x, tam);
        printf ("\n\n\n");
        copiaMatriz (a2, a, b2, b, tam);
    }    
    free (b);
    free (b2);
    free (x);
    for (int i = 0; i < tam; i++){
        free (a[i]);
        free (a2[i]);
    }
    free (a);
    free (a2);
    return 0;
}