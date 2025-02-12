#ifndef LEDS_h
#define LEDS_h

extern int duracion_led;
extern int modo;
extern unsigned int BOTONES_nuevo[];
extern unsigned int BOTONES_viejo[];
extern int leds[];
extern int valor_leds[];
extern int low_high;
extern int led_actual;

//apaga todos los leds, menos el indicador
void apagado_leds()
{
  for (int i = 0; i <= 3; i++)
  {
    digitalWrite(leds[i], LOW);
    valor_leds[i]=0;
  }
}

//todo lo relacionado con la seleccion de los modos de encendido y apagado
void SELECCION_MODOS_leds()
{
  //tiempo de encendido
  if((BOTONES_nuevo[4]==1) && (BOTONES_nuevo[4]!=BOTONES_viejo[4]))
  {
    if(duracion_led==500)
    {
      duracion_led=250;
    }
    else
    {
      duracion_led=500;
    }
  }
  //cambio de modo
  if((BOTONES_nuevo[5]==1) && (BOTONES_nuevo[5]!=BOTONES_viejo[5]))
  {
    switch(modo)
    {
      case 1:
        modo=2;
      break;

      case 2:
        modo=1;
      break;

      case 3:
        modo=4;
      break;

      case 4:
        modo=3;
      break;
    } 
    apagado_leds();
    low_high=0;
  }
  //invertido
  if((BOTONES_nuevo[6]==1) && (BOTONES_nuevo[6]!=BOTONES_viejo[6]))
  {
    if(modo<3)
    {
      modo=modo+2;
    }
    else
    {
      modo=modo-2;
    }
    apagado_leds();
    low_high=0;
  }
}

//secuencia de encendidos de led de 4 asta 1 y apagado de 1 asta 4
void MODO_NORMAL_LEDS()
{
  if((valor_leds[0] && valor_leds[3]) == low_high)
  {
    if(low_high==0)
    {
      low_high=1;
      led_actual=3;
    }
    else
    {
      low_high=0;
      led_actual=0;
    }
    valor_leds[led_actual]=low_high;
    digitalWrite(valor_leds[led_actual], low_high);
  }
  else
  {
    if(low_high==0)
    {
      led_actual=led_actual-1;
    }
    else
    {
      led_actual=led_actual+1;
    }
    valor_leds[led_actual]=low_high;
    digitalWrite(valor_leds[led_actual], low_high);
  }
}

//encendido de leds en pares de 1y4, 2y3. asi mismo de los apagados
void MODO_PARES_LEDS()
{
  if((valor_leds[0]&&valor_leds[1])==low_high)
  {
    if(low_high==0)
    {
      low_high=1;
      digitalWrite(leds[0], low_high);
      valor_leds[0]=low_high;
      digitalWrite(leds[3], low_high);
      valor_leds[0]=low_high;
    }
    else
    {
      low_high=0;
      digitalWrite(leds[2], low_high);
      valor_leds[2]=low_high;
      digitalWrite(leds[1], low_high);
      valor_leds[1]=low_high;
    }
  }
  if(low_high==0)
  {
    digitalWrite(leds[3], low_high);
    valor_leds[3]=low_high;
    digitalWrite(leds[0], low_high);
    valor_leds[0]=low_high;
  }
  else
  {
    digitalWrite(leds[1], low_high);
    valor_leds[1]=low_high;
    digitalWrite(leds[2], low_high);
    valor_leds[2]=low_high;
  }
}
//secuencia de encendidos de led de 1 asta 4 y apagado de 4 asta 1
void MODO_NORMAL_LEDS_INVERTIDOS()
{
  if((valor_leds[0]&&valor_leds[3])==low_high)
  {
    if(low_high==0)
    {
      low_high=1;
      led_actual=0;
    }
    else
    {
      low_high=0;
      led_actual=3;
    }
    digitalWrite(valor_leds[led_actual], low_high);
    valor_leds[led_actual]=low_high;
  }
  else
  {
    if(low_high==0)
    {
      led_actual=led_actual+1;
    }
    else
    {
      led_actual=led_actual-1;
    }
    digitalWrite(valor_leds[led_actual], low_high);
    valor_leds[led_actual]=low_high;
  }
}

//encendido de leds en pares de 2y3, 1y4. asi mismo de los apagados
void MODO_PARES_LEDS_INVERTIDOS()
{
  if((valor_leds[0]&&valor_leds[1])==low_high)
  {
    if(low_high==0)
    {
      low_high=1;
      digitalWrite(leds[1], low_high);
      digitalWrite(leds[2], low_high);
      valor_leds[1]=low_high;
      valor_leds[2]=low_high;
    }
    else
    {
      low_high=0;
      digitalWrite(leds[3], low_high);
      digitalWrite(leds[0], low_high);
      valor_leds[3]=low_high;
      valor_leds[0]=low_high;
    }
  }
  if(low_high==0)
  {
    digitalWrite(leds[1], low_high);
    digitalWrite(leds[2], low_high);
    valor_leds[1]=low_high;
    valor_leds[2]=low_high;
  }
  else
  {
    digitalWrite(leds[3], low_high);
    digitalWrite(leds[0], low_high);
    valor_leds[3]=low_high;
    valor_leds[0]=low_high;
  }
}
#endif