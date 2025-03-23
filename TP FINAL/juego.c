#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include "estruct.h"
#include "juego.h"
#include "jugadores.h"
#include "puntos.h"

////MENUUUUU ///////

void menuPrincipal() {
    int opcion;
    do {
        printf("---------<MENU>----------\n");
        printf("1. Jugar\n");
        printf("2. Puntajes\n");
        printf("3. Salir\n");
        printf("\nElija una opcion :) : ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                mostrarPuntajes();
                break;
            case 3:
                printf("\n-------Gracias por jugar a FUTBOL MASTERS!! Hasta luego.-------\n");
                break;
            default:
                printf("Opcion incorrecta. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}




void jugar() {
    char* archivo = "preguntas.txt";
    int numPreguntas;
    Pregunta* preguntas = cargarPreguntas(archivo, &numPreguntas);
    mezclarPreguntas(preguntas, numPreguntas);

    struct Jugador* listaJugadores = NULL;
    int numJugadores;

    solicitarCantidadJugadores(&numJugadores, &listaJugadores);
    cuestionario(preguntas, numPreguntas, listaJugadores);
    calcularPuntMax(listaJugadores);
    mostrarPuntAct(listaJugadores);
    guardarPuntEnArchivo(listaJugadores);
    liberarPreguntas(preguntas, numPreguntas);

    liberarJugadores(listaJugadores);

    printf("\n\nJuego terminado. Volviendo al Menu Principal.\n\n");
}

void mostrarPuntajes() {
    FILE* archivo = fopen("puntajes.txt", "r");

    if (archivo == NULL) {
        printf("No se encontraron puntajes.\n");
    } else {

        struct PuntosJugador puntajes[100];
        int jugadorAux = 0;
        char linea[1024];

        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            char alias[50];
            int dni;
            int puntos;

            if (sscanf(linea, "%d: %[^-] - %d puntos", &dni, alias, &puntos) == 3) {
                puntajes[jugadorAux].dni = dni;
                strcpy(puntajes[jugadorAux].alias, alias);
                puntajes[jugadorAux].puntos = puntos;
                jugadorAux++;
            }
        }

        fclose(archivo);

        if (jugadorAux == 0) {
            printf("No hay puntajes registrados.\n\n");
        } else {
            /// ORDENAMIENTO
            int numJugadores = jugadorAux;
            for (int i = 0; i < numJugadores - 1; i++) {
                for (int j = i + 1; j < numJugadores; j++) {
                    if (puntajes[i].puntos < puntajes[j].puntos) {
                        struct PuntosJugador temp = puntajes[i];
                        puntajes[i] = puntajes[j];
                        puntajes[j] = temp;
                    }
                }
            }

            printf("Puntajes:\n");
            for (int i = 0; i < numJugadores; i++) {
                printf("DNI: %d, Alias: %s, Puntos: %d\n", puntajes[i].dni, puntajes[i].alias, puntajes[i].puntos);
            }
        }
    }
}
////MENUUUUU ///////










//////JUEGO PREGUNTAS///////
Pregunta* cargarPreguntas(char* archivo, int* numPreguntas) {
    FILE* file = fopen(archivo, "r");

    int capacidad = 10;
    *numPreguntas = 0;
    Pregunta* preguntas = (Pregunta*)malloc(capacidad * sizeof(Pregunta));

    if (preguntas == NULL) {
        perror("Error");
        fclose(file);
        return NULL;
    }

    char linea[1024];

    while (fgets(linea, sizeof(linea), file) != NULL) {
        if (*numPreguntas >= capacidad) {
            capacidad *= 2;
            preguntas = (Pregunta*)realloc(preguntas, capacidad * sizeof(Pregunta));

            if (preguntas == NULL) {
                perror("Error");
                fclose(file);
                free(preguntas);
                return NULL;
            }
        }

        char* token = strtok(linea, ";");

        preguntas[*numPreguntas].pregunta = strdup(token);

        for (int j = 0; j < 4; j++) {
            token = strtok(NULL, ";");
            preguntas[*numPreguntas].opciones[j] = strdup(token);
        }

        token = strtok(NULL, ";");
        preguntas[*numPreguntas].respuesta = atoi(token);

        (*numPreguntas)++;
    }

    fclose(file);
    return preguntas;
}




void liberarPreguntas(Pregunta* preguntas, int numPreguntas) {
    for (int i = 0; i < numPreguntas; i++) {
        free(preguntas[i].pregunta);
        for (int j = 0; j < 4; j++) {
            free(preguntas[i].opciones[j]);
        }
    }
    free(preguntas);
}




void cuestionario(Pregunta* preguntas, int numPreguntas, struct Jugador* listaJugadores) {
    int preguntaActual = 0;

    for (struct Jugador* jugadorActual = listaJugadores; jugadorActual != NULL; jugadorActual = jugadorActual->siguiente) {
        printf("\n%s, es tu turno:\n\n", jugadorActual->alias);

        while (preguntaActual < numPreguntas) {
            printf("Pregunta %d: %s\n", preguntaActual + 1, preguntas[preguntaActual].pregunta);
            for (int j = 0; j < 4; j++) {
                printf("%d. %s\n", j + 1, preguntas[preguntaActual].opciones[j]);
            }

            int respuesta;
            printf("Elije una opcion (1-4): ");
            scanf("%d", &respuesta);

            if (respuesta == preguntas[preguntaActual].respuesta) {
                printf("\nRespuesta correcta!\n\n");
                jugadorActual->puntos.puntosActuales++;
                preguntaActual++; ///avanza si la respuesta es correcta
            } else {
                printf("\nRespuesta incorrecta. Turno pasado al siguiente jugador.\n\n");
                break; ///PASA SIG JUGADOR si es incorrecto
            }
        }
    }

    struct Jugador* jugadorActual = listaJugadores;
    while (jugadorActual != NULL) {
        if (jugadorActual->puntos.puntosActuales > jugadorActual->puntos.puntMaxima) {
            jugadorActual->puntos.puntMaxima = jugadorActual->puntos.puntosActuales;
        }
        jugadorActual = jugadorActual->siguiente;
    }
}



void mezclarPreguntas(Pregunta* preguntas, int numPreguntas) {
    srand(time(0));

    for (int i = numPreguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Intercambia preguntas[i] y preguntas[j]
        Pregunta temp = preguntas[i];
        preguntas[i] = preguntas[j];
        preguntas[j] = temp;
    }
}
