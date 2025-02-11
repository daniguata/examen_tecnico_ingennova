#include "BOTONES.h"
#include "MOTOR.h"
#include "LEDS.h"
#include "maquinaEstados.h"
#include "declaraciones.h"

/*Pine Motor*/
  //requerido por "declaraciones.h"
  const int MOTOR=11;

/* Pines BOTONES B*/
  //1 presionado y 0 no presionado
  //requerido por "BOTONES.h" y "declaraciones.h"
  const int B_STAR=5;
  const int B_PWM_MAS=4;
  const int B_PWM_MENOS=2;
  const int B_STOP=3;
  const int B_VELO_CAMB=6;
  const int B_MODO_CAMB=12;
  const int B_INV=13;

/* Pines Leds*/
  //requerido por "declaraciones.h"
  const int LED_1=10;
  const int LED_2=9;
  const int LED_3=8;
  const int LED_4=7;
  const int LED_INDICADOR=1;

//
int velocidad=0;
//
int frecuencia=0;
//
int dis_aum=0;
//
int tiem_frec=0;
//
int modo=1;
//
int duracion_led=500;
//
int tiem_modo=0;
//
int leds[4]=
{
LED_1,
LED_2,
LED_3,
LED_4
};
//
int led_actual=0;
//
int low_high=0;
//
int apagado=0;
//requerido por "BOTONES.h" pociciones de guardado:
  /*posicion en que guarda la informacion de botones
  *[0]B_STAR
  *[1]B_PWM_MAS
  *[2]B_PWM_MENOS
  *[3]B_STOP
  *[4]B_VELO_CAMB
  *[5]B_MODO_CAMB
  *[6]B_INV
  */
  unsigned int BOTONES_nuevo[]={0,0,0,0,0,0,0};
  /*posicion en que guarda la informacion de botones
  *[0]B_STAR
  *[1]B_PWM_MAS
  *[2]B_PWM_MENOS
  *[3]B_STOP
  *[4]B_VELO_CAMB
  *[5]B_MODO_CAMB
  *[6]B_INV
  */
  unsigned int BOTONES_viejo[]={0,0,0,0,0,0,0};

void setup() {
  Serial.begin(9600);
  millis();
  declaracion();
}

void loop() {

  //EXAMEN proviene de "maquinaEstados.h". asigna el caso que corresponda
  switch(EXAMEN)
  {
    case START:
      barrido_botones();
      //atrapa el valor de 
      if (BOTONES_nuevo[0] == 1)
      {
        //inicializacion del tiempo inicial
        apagado, tiem_modo, tiem_frec = millis();
        asignar(TRABAJO);
      }
    break;
    case TRABAJO:
      barrido_botones();
      
    break;
    case STOP:

    break;
  }

}
