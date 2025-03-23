#ifndef ESTRUCT_H_INCLUDED
#define ESTRUCT_H_INCLUDED


struct PuntosJugador {
    char alias[50];
     int dni;
    int puntos;
};

struct Puntos {
    int puntosActuales;
    int puntMaxima;
};



struct Jugador {
    char alias[50];
    int dni;
    struct Jugador* siguiente;
    struct Puntos puntos;
};



typedef struct {
    char* pregunta;
    char* opciones[4];
    int respuesta;
} Pregunta;




#endif // ESTRUCT_H_INCLUDED
