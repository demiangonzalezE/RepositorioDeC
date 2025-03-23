#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED

struct Jugador* crearJugador(struct Jugador* listaJugadores);
void agregarJugador(struct Jugador** listaJugadores, struct Jugador* nuevoJugador);
void liberarJugadores(struct Jugador* listaJugadores);
int dniExistente(struct Jugador* listaJugadores, int dni);
void solicitarCantidadJugadores(int* numJugadores, struct Jugador** listaJugadores);



#endif // JUGADORES_H_INCLUDED
