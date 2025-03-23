#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED


Pregunta* cargarPreguntas(char* archivo, int* numPreguntas);
void liberarPreguntas(Pregunta* preguntas, int numPreguntas);
void cuestionario(Pregunta* preguntas, int numPreguntas, struct Jugador* listaJugadores);
void mezclarPreguntas(Pregunta* preguntas, int numPreguntas);

void jugar();
void mostrarPuntajes();
void menuPrincipal();

#endif // JUEGO_H_INCLUDED
