#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(int *op, char nombre[][50], int id[], char tipo[][50], int edad[], char nombred[][50], float precio[], char s[][50], int indice) {
    switch (*op) {
        case 1:
            IngresarNombreM(nombre, indice);
            ID(id, indice);
            Tipo(tipo, indice);
            IngresarEdad(edad, indice);
            NombreDueno(nombred, indice);
            break;
        case 2:
            IngresarServicio(precio, s, indice);
            break;
        case 3:
            for (int i = 0; i < indice; i++) {
                facturacion(nombre, id, tipo, edad, nombred, precio, s, i);
            }
            break;
        case 4:
            printf("Los servicios disponibles son:\n Consulta 8.50$\n Peluqueria 10$\n Rayos X 300$");
            break;
        case 5:
            mostrarFacturas();
            break;
        default:
            return *op;
    }
    return *op;
}

void IngresarNombreM(char nombre[][50], int indice) {
    printf("Ingresar el nombre de la mascota %d:\n", indice + 1);
    scanf("%s", nombre[indice]);
}

void ID(int id[], int indice) {
    printf("Ingresar el id de la mascota %d:\n", indice + 1);
    scanf("%d", &id[indice]);
}

void IngresarEdad(int edad[], int indice) {
    printf("Ingresar la edad de la mascota %d:\n", indice + 1);
    scanf("%d", &edad[indice]);
}

void NombreDueno(char nombred[][50], int indice) {
    printf("Ingresar el nombre del dueno de la mascota %d:\n", indice + 1);
    scanf("%s", nombred[indice]);
}

void Tipo(char tipo[][50], int indice) {
    int op2;
    printf("Seleccionar qué tipo de mascota es la mascota %d:\n 1. Perro\n 2. Gato\n", indice + 1);
    scanf("%d", &op2);
    switch (op2) {
        case 1:
            strcpy(tipo[indice], "Perro");
            break;
        case 2:
            strcpy(tipo[indice], "Gato");
            break;
    }
}

void IngresarServicio(float precio[], char s[][50], int indice) {
    printf("Ingresar servicio para la mascota %d:\n 1. Consulta\n 2. Peluqueria\n 3. Rayos X\n", indice + 1);
    int op3;
    scanf("%d", &op3);
    switch (op3) {
        case 1:
            precio[indice-1] = 8.50;
            strcpy(s[indice-1], "Consulta");
            break;
        case 2:
            precio[indice-1] = 10;
            strcpy(s[indice-1], "Peluqueria");
            break;
        case 3:
            precio[indice-1] = 300;
            strcpy(s[indice-1], "Rayos x");
            break;
    }
}

void facturacion(char nombre[][50], int id[], char tipo[][50], int edad[], char nombred[][50], float precio[], char s[][50], int indice) {
    
    FILE *archivo;
    archivo = fopen("Facturas.txt", "a");
    
     if (archivo == NULL) {
        printf("Error al abrir el archivo de facturas.\n");
        return;
    }
    
    fprintf(archivo, "----------------------FACTURA CLINICA HUELLITAS-----------------------------\n");
    fprintf(archivo, "Nombre del dueno de la mascota %d: %s\n", indice + 1, nombred[indice]);
    fprintf(archivo, "Nombre de la mascota %d: %s\n", indice + 1, nombre[indice]);
    fprintf(archivo, "ID de la mascota %d: %d\n", indice + 1, id[indice]);
    fprintf(archivo, "Tipo de mascota %d: %s\n", indice + 1, tipo[indice]);
    fprintf(archivo, "Servicio para la mascota %d: %s\n", indice + 1, s[indice]);
    fprintf(archivo, "Precio para la mascota %d: %.2f\n", indice + 1, precio[indice]);
    fprintf(archivo, "\n");
    
    fclose(archivo);
}

void mostrarFacturas() {
      FILE *archivo;
    archivo = fopen("Facturas.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo de facturas.\n");
        return;
    }

    char caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    fclose(archivo);
}

int main(int argc, char *argv[]) {
    char nombre[100][50], tipo[100][50], nombred[100][50], s[100][50];
    int id[100], edad[100];
    float precio[100];
    int op, n;
    int indice = 0;

    printf("---------------------------------Bienvenido a la clinica Huellitas------------------------------------\n");
    printf("Por favor decida qué desea realizar:\n");
    do {
        printf("\n 1. Ingresar mascota\n 2. Ingresar servicio\n 3. Facturacion\n 4. Servicios disponibles\n 5. Mostrar facturas\n 6. Salir\n");
        scanf("%d", &op);
        n = menu(&op, nombre, id, tipo, edad, nombred, precio, s, indice);
        if (op == 1) {
            indice++;
        }
    } while (n != 6);
    printf("\nMuchas gracias por usar nuestros servicios.\n");
    return 0;
}
