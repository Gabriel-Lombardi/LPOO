#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int eleccion;
    int rondasJugador = 0;
    int rondasMaquina = 0;
    int totalJugador  = 0;
    int totalMaquina  = 0;
    bool ganadorRonda = false;
    bool ganador      = false;
    const char *ppp[] = {"Piedra","Papel","Tijera"};

    system("cls");
    printf("PIEDRA, PAPEL O TIJERA!!!\n");
    printf("En este juego, vas a jugar contra la computadora un piedra, papel o tijera. Las reglas son simples:\n");
    printf("1 -- Tenes tres opciones para elegir: Piedra (1), Papel (2) o Tijera (3)\n");
    printf("2 -- La Piedra le gana a la Tijera\n");
    printf("3 -- El Papel le gana a la Piedra\n");
    printf("4 -- La Tijera le gana a la Papel\n");
    printf("\nEmpecemos!\n");
    sleep(1);

    for (int i = 0; i < 5; i++) {
        printf("\nRONDA %d\n\n", i+1);
        totalJugador = 0;
        totalMaquina = 0;

        for (int j = 0; j < 3; j++) {
            int maquina = rand() % 3 + 1;
            int jugador;

            eleccion:
            printf("Ingrese 1 (piedra), 2 (papel) o 3 (tijera): ");
            scanf(" %d", &jugador);
            printf("\n");
            if (jugador > 3 || jugador < 1) {
                printf("\nNumero invalido.\n\n");
                sleep(1);
                goto eleccion;
            }

            sleep(1);

            printf("Jugador: %s!\n\n", ppp[jugador-1]);
            printf("Maquina: %s!\n\n", ppp[maquina-1]);


            if (jugador == maquina) {
                printf("Empate!!\n\n");
                j--;
            }

            else if (jugador == 1 && maquina == 3 || jugador == 2 && maquina == 1 || jugador == 3 && maquina == 2) {
                printf("+1 para usted!\n\n");
                totalJugador++;
            }

            else {
                printf("+1 para la maquina!\n\n");
                totalMaquina++;
            }

            printf("Jugador  |   Maquina\n");
            printf("---------------------\n");
            printf("  %.2d \t |\t%.2d\n", totalJugador, totalMaquina);
            printf(" \t |\n\n");
            if (totalJugador == 2) {
                ganadorRonda = true;
                rondasJugador++;
                j++;
                sleep(1);
            }
            if (totalMaquina == 2) {
                rondasMaquina++;
                j++;
                sleep(1);
            }
        }

        printf("---------------------\n\n");
        if (ganadorRonda == true) printf("Ganaste la ronda! +1\n\n");
        if (ganadorRonda == false) printf("La maquina ha ganado la ronda! +1 (maquina)\n\n");

        printf("Jugador  |   Maquina\n");
        printf("---------------------\n");
        printf("  %.2d \t |\t%.2d\n", rondasJugador, rondasMaquina);
        printf(" \t |\n\n");

        if (rondasJugador == 3) {
            ganador = true;
            i++;
        }

        if (rondasMaquina == 3) {
            i++;
        }
        
        printf("\n");
    }
    
    if (ganador == true) {
        for (int k = 0; k > 3; k++) {
            system("cls");
            printf("Usted ha ganado el torneo!\n");
            sleep(2);
        }
    }

    else if (ganador == false) {
        for (int k = 0; k > 3; k++) {
            system("cls");
            printf("La maquina ha ganado el torneo!\n");
            sleep(1);
        }            
    }

    return 0;
}