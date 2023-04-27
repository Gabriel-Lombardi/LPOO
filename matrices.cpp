#include <stdio.h>

int main() {
    // Declaracion de variables (matrices)
    int m1[2][2];
    int m2[2][2];
    int producto[2][2];

//    printf("Esto es un programa que pida al usuario los datos de dos matrices de 2x2, calcula y muestra su producto.\n");
//    printf("¿Cómo se hace el producto entre dos matrices?:\n");
//    printf("Dadas dos matrices A y B de dimensiones m × n y n × p se define su producto A ⋅ B como la matriz de dimensión m × p tal que el elemento de la posición fila i y columna j es el resultado del producto de los vectores fila i de A y columna j de B.\n\n");

    // Primera matriz

    printf("Entonces...\nIngrese los elementos de la primera matriz (2x2): \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          printf("Ingrese el elemento [%d][%d]\n", i, j);
          scanf("%d", &m1[i][j]);
        }
    }

    // Segunda matriz
    printf("\nIngrese los elementos de la segunda matriz 2x2: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          printf("Ingrese el elemento [%d][%d]\n", i, j);
          scanf("%d", &m2[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 4; j++) {
        if(j < 2)  printf("%02d ", m1[i][j]);
        if(j >= 2) printf(" %02d", m2[i-1][j]);
        if(j == 3 && i == 0) printf("\n     X");
      }
      printf("\n");
    }
    // Calcular el producto de las dos matrices
    producto[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    producto[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
    producto[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    producto[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

    // Mostrar el producto de las dos matrices
    printf("\nEl producto de las dos matrices es: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%02d ", producto[i][j]);
        }
        printf("\n");
    }

    return 0;
}
