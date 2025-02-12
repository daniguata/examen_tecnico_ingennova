#include "declaraciones.h"

void declaracion() {
  pinMode(MOTOR, OUTPUT);
  analogWrite(MOTOR, LOW);

  pinMode(B_STAR, INPUT);
  pinMode(B_PWM_MAS, INPUT);
  pinMode(B_PWM_MENOS, INPUT);
  pinMode(B_STOP, INPUT);
  pinMode(B_VELO_CAMB, INPUT);
  pinMode(B_MODO_CAMB, INPUT);
  pinMode(B_INV, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_INDICADOR, OUTPUT);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_INDICADOR, LOW);
}