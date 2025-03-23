#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include "estruct.h"
#include "puntos.h"


///////PUNTOS //////////

void calcularPuntMax(struct Jugador* listaJugadores) {
    struct Jugador* jugador = listaJugadores;

    while (jugador != NULL) {
        if (jugador->puntos.puntosActuales > jugador->puntos.puntMaxima) {
            jugador->puntos.puntMaxima = jugador->puntos.puntosActuales;
        }

        jugador = jugador->siguiente;
    }


    int hayEmpate = comprobarEmpate(listaJugadores);
    if (hayEmpate) {
        printf("EMPATARON!!!! Realicemos una pregunta desempate.\n");
        int ganadorDesempate = preguntaDesempate(listaJugadores);
        printf("\nEl jugador del DNI %d ha ganado.\n", ganadorDesempate);
    }
}



void mostrarPuntAct(struct Jugador* listaJugadores) {
    printf("---------Puntajes actuales:\n");
    struct Jugador* jugador = listaJugadores;

    while (jugador != NULL) {
        printf("%s: %d puntos\n", jugador->alias, jugador->puntos.puntosActuales);
        jugador = jugador->siguiente;
    }
}

void guardarPuntEnArchivo(struct Jugador* listaJugadores) {
    FILE* archivo = fopen("puntajes.txt", "a");

    if (archivo == NULL) {
        perror("Error al abrir");
        return;
    }

    struct Jugador* jugador = listaJugadores;

    while (jugador != NULL) {
        fprintf(archivo, "%d: %s - %d puntos\n", jugador->dni, jugador->alias, jugador->puntos.puntosActuales);
        jugador = jugador->siguiente;
    }

    fclose(archivo);
}








int preguntaDesempate(struct Jugador* listaJugadores) {
    int respuestaCorrecta = 195312;
    int jugadorGanador = -1;
    float distanciaMinima = FLT_MAX;

    struct Jugador* jugadorActual = listaJugadores;
    while (jugadorActual != NULL) {
        printf("SIN CALCULADORA, que resultado da 5^10/50?,  %s,tu respuesta(No colocar . o ,):", jugadorActual->alias);
        int respuestaJugador;
        scanf("%d", &respuestaJugador);

        float distancia = abs(respuestaJugador - respuestaCorrecta);

        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            jugadorGanador = jugadorActual->dni;
        }

        jugadorActual = jugadorActual->siguiente;
    }

    if (jugadorGanador != -1) {
        struct Jugador* jugador = listaJugadores;
        while (jugador != NULL) {
            if (jugador->dni == jugadorGanador) {
                jugador->puntos.puntosActuales++;
            }
            jugador = jugador->siguiente;
        }
    }

    return jugadorGanador;
}






int comprobarEmpate(struct Jugador* listaJugadores) {
    struct Jugador* jugador = listaJugadores;
    int puntajeEmpate = -1;
    int contadorEmpate = 0;

    while (jugador != NULL) {
        if (jugador->puntos.puntosActuales > puntajeEmpate) {
            puntajeEmpate = jugador->puntos.puntosActuales;
            contadorEmpate = 1;
        } else if (jugador->puntos.puntosActuales == puntajeEmpate) {
            contadorEmpate++;
        }

        jugador = jugador->siguiente;
    }

    return (contadorEmpate > 1);
}
////////PUNTOS///////




