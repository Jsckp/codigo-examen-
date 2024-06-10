#include <stdio.h>
#include "funciones.h"
#include <string.h>

void verPersonas(char personas[][4][20]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Nombre: %s %s, Cedula: %s, Estado Civil: ", personas[i][0], personas[i][1], personas[i][2]);
        if (strcmp(personas[i][3], "soltero") == 0) {
            printf("La persona seleccionada esta soltera\n");
        } else {
            printf("La persona seleccionada esta casada\n");
        }
    }
}
void registrarMatrimonio(char personas[][4][20]) {
    char cedula1[20], cedula2[20];
    printf("Ingrese la cedula de la primera persona que desea registrar: ");
    scanf("%s", cedula1);
    printf("Ingrese la cedula de la segunda persona que desee registrar: ");
    scanf("%s", cedula2);
    int idx1 = buscarPersonaXCedula(personas, cedula1);
    int idx2 = buscarPersonaXCedula(personas, cedula2);
    if (idx1!= -1 && idx2!= -1) {
        strcpy(personas[idx1][3], cedula2);
        strcpy(personas[idx2][3], cedula1);
        printf("El matrimonio fue registrado\n");
    } else {
        printf("Una de las cedulas es incorrecta\n");
    }
}
void verificarPersona(char personas[][4][20]) {
    char cedula[20];
    printf("Ingrese la cedula de la persona que desee buscar: ");
    scanf("%s", cedula);
    int idx = buscarPersonaXCedula(personas, cedula);
    if (idx!= -1) {
        if (strcmp(personas[idx][3], "soltero") == 0) {
            printf("La persona seleccionada esta soltera\n");
        } else {
            int idx_conyugue = buscarPersonaXCedula(personas, personas[idx][3]);
            if (idx_conyugue!= -1) {
                printf("La persona seleccionada esta casada con %s %s\n", personas[idx_conyugue][0], personas[idx_conyugue][1]);
            } else {
                printf("La persona esta casada, pero no se encontro a su pareja\n");
            }
        }
    } else {
        printf("Cedula inexistente\n");
    }
}
int buscarPersonaXCedula(char personas[][4][20], char cedula[20]) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(personas[i][2], cedula) == 0) {
            return i;
        }
    }
    return -1;
}
