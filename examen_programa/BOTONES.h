#ifndef BOTONES_h
#define BOTONES_h

extern const int B_STAR;
extern const int B_PWM_MAS;
extern const int B_PWM_MENOS;
extern const int B_STOP;
extern const int B_VELO_CAMB;
extern const int B_MODO_CAMB;
extern const int B_INV;
extern unsigned int BOTONES_nuevo[];
extern unsigned int BOTONES_viejo[];

//hace un barrido por todos los botones para guardar sus valores en arreglos
void barrido_botones()
{
  //guarda los valores de viejos para actualizar
  for (int i = 0; i <= 6; i++) {
    BOTONES_viejo[i] = BOTONES_nuevo[i];
  }
  
  //guarda los valores nuevos
  BOTONES_nuevo[0] = digitalRead(B_STAR);
  BOTONES_nuevo[1] = digitalRead(B_PWM_MAS);
  BOTONES_nuevo[2] = digitalRead(B_PWM_MENOS);
  BOTONES_nuevo[3] = digitalRead(B_STOP);
  BOTONES_nuevo[4] = digitalRead(B_VELO_CAMB);
  BOTONES_nuevo[5] = digitalRead(B_MODO_CAMB);
  BOTONES_nuevo[6] = digitalRead(B_INV);
}

#endif