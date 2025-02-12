#include "declaraciones.h"

//hace un barrido por todos los botones para guardar sus valores en arreglos
void barrido_botones() {
  BOTONES_viejo[0] = BOTONES_nuevo[0];
  BOTONES_viejo[1] = BOTONES_nuevo[1];
  BOTONES_viejo[2] = BOTONES_nuevo[2];
  BOTONES_viejo[3] = BOTONES_nuevo[3];
  BOTONES_viejo[4] = BOTONES_nuevo[4];
  BOTONES_viejo[5] = BOTONES_nuevo[5];
  BOTONES_viejo[6] = BOTONES_nuevo[6];

  BOTONES_nuevo[0] = digitalRead(B_STAR);
  BOTONES_nuevo[1] = digitalRead(B_PWM_MAS);
  BOTONES_nuevo[2] = digitalRead(B_PWM_MENOS);
  BOTONES_nuevo[3] = digitalRead(B_STOP);
  BOTONES_nuevo[4] = digitalRead(B_VELO_CAMB);
  BOTONES_nuevo[5] = digitalRead(B_MODO_CAMB);
  BOTONES_nuevo[6] = digitalRead(B_INV);
}