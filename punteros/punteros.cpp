#include <stdio.h>

#define N 10

// Prototipos de funciones
void cargarMatriz(int matriz[N][N], int filas, int columnas);
void escribirMatriz(int matriz[N][N], int filas, int columnas);
void sumarMatrices(int matrizA[N][N], int matrizB[N][N], int resultado[N][N], int filas, int columnas);
void multiplicarMatrices(int matrizA[N][N], int matrizB[N][N], int resultado[N][N], int filasA, int columnasA, int columnasB);
int  calcularDeterminante(int matriz[N][N], int orden);
void calcularTranspuesta(int matriz[N][N], int transpuesta[N][N], int filas, int columnas);

int main()
{
    int opcion;
    int filas, columnas;
    int matrizA[N][N], matrizB[N][N], resultado[N][N];
    int transpuesta[N][N];
    int determinante;

    do
    {
        // mostrar menú
        printf("\n---- Menú de opciones ----\n");
        printf("1. Cargar matrices\n");
        printf("2. Escribir matrices\n");
        printf("3. Sumar matrices\n");
        printf("4. Multiplicar matrices\n");
        printf("5. Calcular determinante\n");
        printf("6. Calcular transpuesta\n");
        printf("0. Salir\n");
        printf("--------------------------\n");
        printf("Ingrese la opción: ");
        scanf("%d", &opcion);

        // casos para el menu
        switch (opcion)
        {
            case 1:
                // cargar matrices
                printf("\nIngrese las dimensiones de la matriz A (filas columnas): ");
                scanf("%d %d", &filas, &columnas);
                cargarMatriz(matrizA, filas, columnas);

                printf("\nIngrese las dimensiones de la matriz B (filas columnas): ");
                scanf("%d %d", &filas, &columnas);
                cargarMatriz(matrizB, filas, columnas);

                break;

            case 2:
                // escribir matrices
                printf("\nMatriz A:\n\n");
                escribirMatriz(matrizA, filas, columnas);

                printf("\nMatriz B:\n\n");
                escribirMatriz(matrizB, filas, columnas);

                break;

            case 3:
                // sumar matrices
                sumarMatrices(matrizA, matrizB, resultado, filas, columnas);
                printf("\nLa suma de las matrices A y B es:\n");
                escribirMatriz(resultado, filas, columnas);

                break;

            case 4:
                // multiplicar matrices
                printf("\nIngrese las dimensiones de la matriz A (filas columnas): ");
                scanf("%d %d", &filas, &columnas);

                printf("\nIngrese las dimensiones de la matriz B (filas columnas): ");
                scanf("%d %d", &columnas, &filas); // Se intercambian las dimensiones para la multiplicación

                multiplicarMatrices(matrizA, matrizB, resultado, filas, columnas, filas);
                printf("\nEl resultado de la multiplicación de las matrices A y B es:\n");
                escribirMatriz(resultado, filas, filas);

                break;

            case 5:
                // calcular determinante
                printf("\nIngrese la dimensión de la matriz cuadrada: ");
                scanf("%d", &filas);
                cargarMatriz(matrizA, filas, filas);

                determinante = calcularDeterminante(matrizA, filas);
                printf("\nEl determinante de la matriz es: %d\n", determinante);

                break;

            case 6:
                // calcular transpuesta
                printf("\nIngrese las dimensiones de la matriz (filas columnas): ");
                scanf("%d %d", &filas, &columnas);
                cargarMatriz(matrizA, filas, columnas);

                calcularTranspuesta(matrizA, transpuesta, filas, columnas);
                printf("\nLa transpuesta de la matriz es:\n");
                escribirMatriz(transpuesta, columnas, filas);

                break;

            case 0:
                // salir del programa
                printf("\n¡Chau chau!\n");
                break;

            default:
                printf("\nOpcion inválida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

void cargarMatriz(int matriz[N][N], int filas, int columnas)
{
    int i, j;

    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese el elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void escribirMatriz(int matriz[N][N], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatrices(int matrizA[N][N], int matrizB[N][N], int resultado[N][N], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void multiplicarMatrices(int matrizA[N][N], int matrizB[N][N], int resultado[N][N], int filasA, int columnasA, int columnasB)
{
    int i, j, k;

    for (i = 0; i < filasA; i++)
    {
        for (j = 0; j < columnasB; j++)
        {
            resultado[i][j] = 0;
            for (k = 0; k < columnasA; k++)
            {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int calcularDeterminante(int matriz[N][N], int orden)
{
    int i, j, k;
    int det = 0;
    int submatriz[N][N];

    if (orden == 1)
    {
        return matriz[0][0];
    }
    else if (orden == 2)
    {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }
    else
    {
        for (k = 0; k < orden; k++)
        {
            int subi = 0;
            for (i = 1; i < orden; i++)
            {
                int subj = 0;
                for (j = 0; j < orden; j++)
                {
                    if (j == k)
                    {
                        continue;
                    }
                    submatriz[subi][subj] = matriz[i][j];
                    subj++;
                }
                subi++;
            }
            det += (k % 2 == 0 ? 1 : -1) * matriz[0][k] * calcularDeterminante(submatriz, orden - 1);
        }
        return det;
    }
}

void calcularTranspuesta(int matriz[N][N], int transpuesta[N][N], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}
