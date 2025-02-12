#ifndef declaraciones_h
#define declaraciones_h

#include <Arduino.h>

// Pines
extern const int MOTOR;
extern const int B_STAR;
extern const int B_PWM_MAS;
extern const int B_PWM_MENOS;
extern const int B_STOP;
extern const int B_VELO_CAMB;
extern const int B_MODO_CAMB;
extern const int B_INV;
extern const int LED_1;
extern const int LED_2;
extern const int LED_3;
extern const int LED_4;
extern const int LED_INDICADOR;

// Variables globales
extern unsigned long apagado;
extern unsigned long tiem_frec;
extern int velocidad;
extern int frecuencia;
extern int dis_aum;
extern int modo;
extern int duracion_led;
extern int leds[4];
extern int valor_leds[4];
extern int led_actual;
extern int low_high;
extern unsigned int BOTONES_nuevo[];
extern unsigned int BOTONES_viejo[];

// Funciones
void declaracion();
void cambiarFrecuenciaPWM(int frecuencia);
void barrido_botones();
void BOTONES_AUMENTO_DISMINUCION();
void SELECCION_MODOS_leds();
void apagado_leds();
void MODO_NORMAL_LEDS();
void MODO_PARES_LEDS();
void MODO_NORMAL_LEDS_INVERTIDOS();
void MODO_PARES_LEDS_INVERTIDOS();

#endif