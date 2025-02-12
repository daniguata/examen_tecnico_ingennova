#ifndef MOTOR_h
#define MOTOR_h

extern unsigned int BOTONES_nuevo[];
extern unsigned int BOTONES_viejo[];
extern int dis_aum;
extern int velocidad;
extern int frecuencia;
extern int tiem_frec;
extern int apagado;
extern const int MOTOR;


void cambiarFrecuenciaPWM(int frecuencia) {
  switch (frecuencia) {
    case 100:
      TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11); // Prescaler = 8
      ICR1 = 19999; // Frecuencia ≈ 100 Hz
      break;
    case 1000:
      TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10); // Prescaler = 1
      ICR1 = 999; // Frecuencia = 1 kHz
      break;
    default:
      // Manejar error: frecuencia no soportada
      break;
  }
  OCR1A = round((velocidad * ICR1) / 100);
}

//toda la parte logica que nesecita los dos botones de aumento y disminucion del PWM.
//imprime la velocidad en el monitor serial

#endif