#include <stdio.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Este es un programa que verifica la Conjentura de Collatz.\nPara esto, por favor, ingrese un numero entero: ");
  scanf("%d", &num);
  while(num != 1) {
    if(num % 2 == 0) {
      num = num / 2;
      printf("%d -> ", num);
    } else {
      num = 3 * num + 1;
      printf("%d -> ", num);
    }
  }
  printf("\nFin del programa!\n");
  return 0;
}
