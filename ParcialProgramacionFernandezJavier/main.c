#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], char caracter);

typedef struct
{
    int id;
    char procesador[30];
    char marca[30];
    float precio;
}eNotebook;


void ordenarNotebooks(eNotebook notes[], int tamnotes);

int main()
{
    float precio = aplicarDescuento(100);
    printf("El precio con descuento es %.2f\n", precio);
    system("pause");

    int cantidadCaracteres = contarCaracteres("ornitorrinco", 'o');
    printf("la cantidad del caracter 'o' es %d\n", cantidadCaracteres);
    system("pause");

    eNotebook notebooks[10] = { {10, "amd ryzen 7", "lenovo", 99999} , {11, "amd athlon ii", "lenovo", 20000} ,
                                {12, "amd ryzen 7", "asus", 70000} , {13, "intel i7 2gen", "bangho", 92000 } ,
                                {14, "intel pentium 4", "asus", 26500} ,{15, "intel i5", "bangho", 58500},
                                {16, "amd ryzen 7", "hp", 105000} ,{17, "amd athlon ii", "asus", 18500 },
                                {18, "intel i5", "hp", 25000}, {19, "intel i5", "lenovo", 75000} };


    ordenarNotebooks(notebooks, 10);

    printf("\n\n  ID          PROCESADOR                 MARCA            PRECIO\n");

    for(int i=0; i<10; i++)
    {
        printf("\n%4d     %15s       %15s        %10.2f   ", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }
    return 0;
}

float aplicarDescuento(float precio)
{
    return  precio * 0.95;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;

    for(int i=0; i< strlen(cadena); i++)
    {
        if (cadena[i] == caracter)
        {
            contador++;
        }
    }
    return contador;
}

void ordenarNotebooks(eNotebook notes[], int tamnotes)
{
    eNotebook auxNote;
    for(int i=0; i<tamnotes-1; i++)
    {
        for(int j = i+1; j<tamnotes; j++ )
        {
            if(strcmp(notes[i].marca , notes[j].marca)>0)
            {
                auxNote = notes[i];
                notes[i] = notes[j];
                notes[j] = auxNote;
            }
            if(strcmp(notes[i].marca , notes[j].marca)==0)
            {
                if(notes[i].precio > notes[j].precio)
                {
                    auxNote = notes[i];
                    notes[i] = notes[j];
                    notes[j] = auxNote;
                }
            }
        }
    }
}
