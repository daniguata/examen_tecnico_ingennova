#ifndef maquinaEstados_h
#define maquinaEstados_h

#include "declaraciones.h"

/* Maquina de estados */
enum ESTADOS {
  START,
  TRABAJO,
  STOP
};

extern ESTADOS EXAMEN;

void asignar(ESTADOS eleccion);

#endif