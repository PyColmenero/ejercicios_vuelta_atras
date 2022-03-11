#include <stdio.h>
#include <stdlib.h>
#define tam 8

int main (){
    int tablero [tam][tam];
    int columna = 0;
    int fila = 0;

    carga_tablero (tablero) ;

    int x = 0, y = 0;
    while(1){
        printf ("Dame la coordenada x (n entre 1 y 8): ") ;
        scanf ("%d", &x );
        printf ("Dame la coordenada y (n entre 1 y 8): ") ;
        scanf ("%d", &y );
        if(x < 1 || y < 1 || x > tam || y > tam){
            printf("ERROR\n");
        } else {
            columna = x-1;
            fila = y-1;
            break;
        }
    }

    tablero [columna] [fila]=1;
    recursivo (tablero, 2, columna, fila);


    printf ("\nSOLUCION \nColumna -> %d Fila -> %d \n\n", columna, fila);
    mostrar (tablero) ;
    return 0;

}

void carga_tablero (int [][tam] );
void carga_tablero (int arry[][tam] ){

    int j, i;
    for (j=0; j<tam; j++){
        for (i=0; i<tam; i++){
            arry[j][i] = 0;
        }
    }

}

void mostrar (int[] [tam] );
void mostrar (int arry [] [tam] ){
    int j, i;
    for (i=0; i<tam; i++){
        for (j=0; j<tam; j++){
            printf (" %2d |", arry[j] [i]);
        }
        printf ("\n\n") ;
    }
}
int final (int arry [] [tam] )
{
    int j, i;
    for (i=0; i<tam; i++){
        for (j=0; j<tam; j++){
            if (arry [j] [i] == 0){
                return 0;
            }
        }
    }
    return 1;

}

void recursivo (int tab[] [tam] , int numero, int x, int y){
    int arrx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int arry[] = { -2, -1, 1, 2, 2, 1,-1,-2 };
    int newx = 0;
    int newy = 0;
    int indice = 0;


    while (indice < 8 && final(tab) != 1){
        newx = arrx [indice] + x;
        newy = arry [indice] + y;
        if ((tab [newx] [newy] == 0) && (newx < tam && newx >= 0 && newy < tam && newy >= 0)){
            tab [newx] [newy] = numero;
            if (numero != tam*tam){



                recursivo (tab, numero+1, newx, newy) ;
            }
        }

        indice+=1;
    }

    if (final (tab) != 1){
        tab [x] [y]=0;
    }

}
