#include <stdio.h>
#include <stdlib.h>

int *crearVec (int t) ;
void llenarPositivo (int *v, int t) ;
void reinas (int i, int *vec, int *puesto, int *diag2_1, int *diag1_2) ;
void imp(int *vec) ;
int reina=0;
int N = 10;

int main (){
    int a;
    printf ("\nIntroduce N: ") ;
    scanf ("%d", &N) ;
    //N = a;


    int *vec=NULL, *puesto=NULL, *diag2_1=NULL, *diag1_2=NULL;
    vec = crearVec (N) ;
    puesto = crearVec (N) ;
    diag2_1 = crearVec (15) ;
    diag1_2 = crearVec (15) ;
    llenarPositivo (puesto, N) ;
    llenarPositivo (diag2_1, 15) ;
    llenarPositivo (diag1_2, 15) ;
    reinas (0, vec, puesto, diag2_1, diag1_2) ;
    imp (vec) ;
    return 0;
}

int *crearVec (int t){
    int *v=NULL;
    if( (v=malloc (sizeof (int) *t) )==NULL){
        printf ("Sin memoria suficiente\n") ;
        return NULL;
    }
    return v;

}


void llenarPositivo (int *v, int t){
    int i;
    for (i=0; i<t; i++){
        v[i] = 1;
    }


}
void reinas (int i, int *vec, int *puesto, int *diag2_1, int *diag1_2){
    int j;
    for (j=0;j<N;j++){
        if (puesto[j] && diag2_1[i+j] && diag1_2[i-j+N-1]){
            vec [i] = j;
            puesto [j ] = 0;
            diag2_1 [i+j] = 0;
            diag1_2 [i-j+N-1] = 0;
            reina++;
            if (i<N-1){
                reinas (i+1, vec, puesto, diag2_1, diag1_2) ;
                if (reina<N){
                    puesto [j ] = 1;
                    diag2_1[i+j] = 1;
                    diag1_2 [i-j+N-1] = 1;
                    reina--;
                }
            }

        }
    }
}




void imp (int *vec){
    int i, j;
    printf ("\n#######-Tablero-#######\n") ;
    for (i=0; i<N;i++){
        for (j=0;j<N;j++){
            if (j==vec [i]){
                printf(" * ") ;
            }else{
                printf(" 0 ") ;
            }
        }
        printf("\n");
    }


    printf ("\n") ;
    printf ("\nCoordenadas\n") ;
    for (i=0; i<N; i++){
        for (j=0; j<N;j++){
            if (j==vec [i]){
                printf ("%d,%d\n", i, j) ;
            }
        }
    }
}



