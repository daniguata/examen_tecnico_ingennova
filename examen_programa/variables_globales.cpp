#include "declaraciones.h"
#include "maquinaEstados.h"

//para saber que tiempo lleva sin cambios de botones
/*requerido por "BOTONES.h"*/
unsigned long apagado = 0;
//para contar tiempo faltante para cambio de frecuencia
/*requerido por "MOTOR.h"*/
unsigned long tiem_frec = 0;
//la velocidad del PWM que se tiene en el sistema (duty cycle)
/*requerido por "MOTOR.h"*/
int velocidad = 50;
//es el valor de la frecuencia que se tiene en el sistema
/*requerido por "MOTOR.h"*/
int frecuencia = 0;
/*variable sirve para refrescar el contador "tiem_frec" para arrancar a contar el segundo correspondiente a el cambio de frecuencia*/
/*dis_aum=0-->no se a actualizado el contador*/
/*dis_aum=1-->se actualizo el contador*/
/*requerido por "MOTOR.h"*/
int dis_aum = 0;
//para indicar el caso que tiene que tener el juego de leds
/*modo=1-->modo normal*/
/*modo=2-->modo escalado por parejas*/
/*modo=3-->modo normal invertido*/
/*modo=4-->modo escalado por parejas invertido*/
/*requerido por "LEDS.h"*/
int modo = 1;
//tiempo que debe tardarse el led en encender
/*requerido por "LEDS.h"*/
int duracion_led = 500;
//pines de los leds guardados en orden
/*requerido por "LEDS.h"*/
int leds[4] = {LED_1, LED_2, LED_3, LED_4};
//valores de los leds guardados
/*requerido por "LEDS.h"*/
int valor_leds[4] = {0, 0, 0, 0};
//para saber la posicion en el orden correspondiente de los leds
/*requerido por "LEDS.h"*/
int led_actual = 0;
//para saber si estan prendiendo o apagando los leds
/*requerido por "LEDS.h"*/
int low_high = 0;
/*posicion en que guarda la informacion de botones*/
/*[0]B_STAR*/
/*[1]B_PWM_MAS*/
/*[2]B_PWM_MENOS*/
/*[3]B_STOP*/
/*[4]B_VELO_CAMB*/
/*[5]B_MODO_CAMB*/
/*[6]B_INV*/
/*requerido por "MOTOR.h"*/
/*requerido por "LEDS.h"*/
//requerido por "BOTONES.h" pociciones de guardado:
unsigned int BOTONES_nuevo[] = {0, 0, 0, 0, 0, 0, 0};
/*posicion en que guarda la informacion de botones*/
/*[0]B_STAR*/
/*[1]B_PWM_MAS*/
/*[2]B_PWM_MENOS*/
/*[3]B_STOP*/
/*[4]B_VELO_CAMB*/
/*[5]B_MODO_CAMB*/
/*[6]B_INV*/
/*pociciones de guardado:*/
/*requerido por "BOTONES.h"*/
/*requerido por "LEDS.h"*/
/*requerido por "MOTOR.h"*/
unsigned int BOTONES_viejo[] = {0, 0, 0, 0, 0, 0, 0};
//creacion de la varieble examen que me cambia los estados
ESTADOS EXAMEN = START;