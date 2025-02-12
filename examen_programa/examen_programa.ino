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

//la velocidad del PWM que se tiene en el sistema
/*requerido por "MOTOR.h"*/
int velocidad=0;
//es el valor de la frecuencia que se tiene en el sistema
/*requerido por "MOTOR.h"*/
int frecuencia=0;
/*variable sirve para refrescar el contador "tiem_frec" para arrancar a contar el segundo correspondiente a el cambio de frecuencia*/
/*dis_aum=0-->no se a actualizado el contador*/
/*dis_aum=1-->se actualizo el contador*/
/*requerido por "MOTOR.h"*/
int dis_aum=0;

/*contadores de tiempo transcurrido*/

  //para contar tiempo faltante para cambio de frecuencia
  /*requerido por "MOTOR.h"*/
  int tiem_frec=0;
  //conteo para encendido y apagado de leds
  int tiem_modo=0;
  //para saber que tiempo lleva sin cambios de botones
  int apagado=0;

//para indicar el caso que tiene que tener el juego de leds
/*modo=1-->modo normal*/
/*modo=2-->modo escalado por parejas*/
/*modo=3-->modo normal invertido*/
/*modo=4-->modo escalado por parejas invertido*/
/*requerido por "LEDS.h"*/
int modo=1;
//tiempo que debe tardarse el led en encender
/*requerido por "LEDS.h"*/
int duracion_led=500;

//pines de los leds guardados en orden
/*requerido por "LEDS.h"*/
int leds[4]=
{
LED_1,
LED_2,
LED_3,
LED_4
};

//valores de los leds guardados
/*requerido por "LEDS.h"*/
int valor_leds[4]={0,0,0,0};

//para saber la posicion en el orden correspondiente de los leds
/*requerido por "LEDS.h"*/
int led_actual=0;
//para saber si estan prendiendo o apagando los leds
/*requerido por "LEDS.h"*/
int low_high=0;

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
unsigned int BOTONES_nuevo[]={0,0,0,0,0,0,0};
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
        digitalWrite(LED_INDICADOR, HIGH);
      }

    break;

    case TRABAJO:
      barrido_botones();
      //caso en que se seleccione STOP
      if(BOTONES_nuevo[3]==1)
      {
        asignar(STOP);
      }
      BOTONES_AUMENTO_DISMINUCION();
      SELECCION_MODOS_leds();
      if((millis()-tiem_modo)>=duracion_led)
      {
        tiem_modo=millis();
        switch(modo)
        {
          case 1:
            MODO_NORMAL_LEDS();
          break;
          case 2:
            MODO_PARES_LEDS();
          break;
          case 3:
            MODO_NORMAL_LEDS_INVERTIDOS();
          break;
          case 4:
            MODO_PARES_LEDS_INVERTIDOS();
          break;
        }
      }
      //lleva la cuenta de los 7 botones para saber si alguno cambio o para apagar
      int revicion=0;
      for (int i = 0; i <= 6; i++)
      {
        if(BOTONES_viejo[i] == BOTONES_nuevo[i])
        {
          revicion=revicion+1;
        }
        else
        {
          apagado=millis();
        }
        if(revicion==7)
        {
          if((millis()-apagado)>=30000)
          {
            apagado_leds();
            digitalWrite(LED_INDICADOR, LOW);
            analogWrite(MOTOR, LOW);
            asignar(START);
          }
        }
      }
    break;

    case STOP:
      //PWM=0
      //tiempo para renaudar las funciones
      int STOP_T=millis();
      apagado_leds();
      analogWrite(MOTOR, LOW);
      int valor_T_stop = millis()-STOP_T;
      while((millis()-STOP_T)==10000)
      {
        Serial.print("STOP: ");
        Serial.println(valor_T_stop);
      }
      asignar(START);
    break;
  }

}
