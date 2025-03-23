#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include "estruct.h"
#include "jugadores.h"

//////JUGADORES/////////

struct Jugador* crearJugador(struct Jugador* listaJugadores) {
    struct Jugador* nuevoJugador = (struct Jugador*)malloc(sizeof(struct Jugador));

    if (nuevoJugador == NULL) {
        exit(1);
    }

    printf("Ingrese su alias: ");
    scanf("%s", nuevoJugador->alias);

    char dniStr[20];
    int dni;
    int valido = 0;

    while (!valido) {
        printf("Ingrese su DNI: ");
        scanf("%s", dniStr);

        valido = 1;
        for (int i = 0; i < strlen(dniStr); i++) {
            if (!isdigit(dniStr[i])) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            dni = atoi(dniStr);


            struct Jugador* temp = listaJugadores;
            int dniRepetido = 0;
            while (temp != NULL) {
                if (temp->dni == dni) {
                    dniRepetido = 1;
                    break;
                }
                temp = temp->siguiente;
            }

            if (dniRepetido) {
                printf("DNI repetido. Ingrese otra vez su DNI.\n");
                valido = 0;
            } else {
                nuevoJugador->dni = dni;
            }
        } else {
            printf("DNI incorrecto. Ingrese solo numeros.\n");
        }
    }
    nuevoJugador->puntos.puntosActuales = 0;
    nuevoJugador->puntos.puntMaxima = 0;

    nuevoJugador->siguiente = NULL;

    return nuevoJugador;
}



void agregarJugador(struct Jugador** listaJugadores, struct Jugador* nuevoJugador) {
    if (*listaJugadores == NULL) {
        // Si la lista est� vac�a, el nuevo jugador se convierte en el primer elemento
        *listaJugadores = nuevoJugador;
    } else {
        // Si la lista no est� vac�a, agregamos el nuevo jugador al final
        struct Jugador* temp = *listaJugadores;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoJugador;
    }
}




void liberarJugadores(struct Jugador* listaJugadores) {
    // Recorrer la lista y liberar cada nodo jugador
    while (listaJugadores != NULL) {
        struct Jugador* temp = listaJugadores;
        listaJugadores = listaJugadores->siguiente;
        free(temp);
    }
}


int dniExistente(struct Jugador* listaJugadores, int dni) {
    struct Jugador* temp = listaJugadores;
    while (temp != NULL) {
        if (temp->dni == dni) {
            return 1; ///DNI EXISTE
        }
        temp = temp->siguiente;
    }
    return 0; ///DNI NO EXISTE
}


void solicitarCantidadJugadores(int* numJugadores, struct Jugador** listaJugadores) {
    int input;
    do {
        printf("Ingrese la cantidad de jugadores (entre 2 y 4): ");
        if (scanf("%d", &input) != 1 || input < 2 || input > 4) {
            printf("Opcion invalida!! ingrese de nuevo.\n\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            *numJugadores = input;
        }
    } while (*numJugadores < 2 || *numJugadores > 4);

    for (int i = 0; i < *numJugadores; i++) {
        struct Jugador* nuevoJugador = crearJugador(*listaJugadores);
        agregarJugador(listaJugadores, nuevoJugador);
    }
}
//////JUGADORES//////////
