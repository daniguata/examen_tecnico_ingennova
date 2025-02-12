#ifndef MOTOR_h
#define MOTOR_h

extern unsigned int BOTONES_nuevo[];
extern unsigned int BOTONES_viejo[];
extern int dis_aum;
extern int velocidad;
extern int frecuencia;
extern int tiem_frec;
//toda la parte logica que nesecita los dos botones de aumento y disminucion del PWM.
//imprime la velocidad en el monitor serial
void BOTONES_AUMENTO_DISMINUCION()
{
  if((BOTONES_nuevo[1] && BOTONES_nuevo[2])==1)
  {
    if(dis_aum==1)
    {
      if((millis()-tiem_frec)>=1000)
      {
        dis_aum=0;
        if(frecuencia==100)
        {
          frecuencia==100;
        }
        else
        {
          frecuencia=100;
        }
      }
    }
    else
    {
      dis_aum=1;
      tiem_frec=millis();
    }
  }
  else
  {
    dis_aum=0;
    if((BOTONES_nuevo[1] == 1) && (BOTONES_nuevo[1]!=BOTONES_viejo[1]))
    {
      if(velocidad < 100)
      {
        velocidad=velocidad+10;
      }
    }
    else
    {
      if((BOTONES_nuevo[2]==1) && (BOTONES_nuevo[2]!=BOTONES_viejo[2]))
      {
        if(velocidad > 0)
        {
          velocidad=velocidad-10;
        }
      }
    }
  }
  Serial.print("PWM: ");
  Serial.print(velocidad);
  Serial.println("%");
}
#endif