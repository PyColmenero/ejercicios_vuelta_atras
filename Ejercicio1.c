#include <stdio.h>
#define TAM 9
#define FILENAME "data.dat"

int main(){

    int matriz[TAM][TAM];

    for(int x = 0; x < TAM; x++){
        for(int y = 0; y < TAM; y++){
            matriz[x][y] = 0;
        }
    }

    remove(FILENAME);
    int num;
    for(int x = 0; x < TAM; x++){
        for(int y = 0; y < TAM; y++){

            show_matriz(matriz);
            printf ("Dame el elemento de la coordenada %d/%d: ", x, y) ;
            scanf ("%d", &num );

            system("cls");
            if(num >= 1 && num <= 9){
                matriz[x][y] = num;

            } else {
                printf("ERROR: Numero entre 1 y 9 por favor.\n");
                y--;
            }

        }
    }

    show_matriz(matriz);
    create_file(matriz);


    return 0;
}

void create_file(int[TAM][TAM]);
void create_file(int matriz[TAM][TAM]){
    // MATRIZ A TXT
    char txt[TAM+1];

    // ESCRIBIMOS EN EL ARCHIVO BINARIO
    FILE *fileW;
    fileW = fopen(FILENAME, "a");
    if(fileW != NULL){

        for(int x = 0; x < TAM; x++){
            for(int y = 0; y < TAM; y++){
                int index = (x*TAM)+y;
                txt[y]= matriz[x][y] + '0';
            }
            txt[TAM] = '\n';
            fwrite(txt, sizeof txt, 1, fileW);
            free(txt);
        }




        fclose(fileW);


        printf("\nArchivo creado correctamente.\n");

    } else {
        printf("Error al abrir el archivo.");
    }
}

void show_matriz(int[TAM][TAM]);
void show_matriz(int matriz[TAM][TAM]){
    int index = 0;
    for(int x = 0; x < TAM+4; x++){
        for(int y = 0; y < TAM+4; y++){
            if(x == 0 || x == TAM+3 || x == 4 || x == 8){
                // conseguir cuadrado perfecto
                if(y < 9){
                    printf("%c%c%c", 219, 219, 219);
                } else {
                    printf("%c", 219, 219);
                }
            } else if(y == 0 || y == TAM+3 || y == 4 || y == 8){
                printf("%c", 219);
            } else {

                int rx,ry;
                ry = index%TAM;
                rx = index/TAM;
                printf(" %d ", matriz[rx][ry]);
                index++;
            }

        }
        printf("\n");
    }
}
