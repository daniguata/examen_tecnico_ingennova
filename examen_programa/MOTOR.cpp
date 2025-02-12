#include "declaraciones.h"

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

//revisa los botones nuevos y viejos para aumentar pwm o disminuir, cambiarfrecuencia, actualizar el motor y imprimir en el serial el pwm
void BOTONES_AUMENTO_DISMINUCION() {
  if ((BOTONES_nuevo[1] && BOTONES_nuevo[2]) == 1) {
    apagado = millis();
    if (dis_aum == 1) {
      if ((millis() - tiem_frec) >= 1000) {
        dis_aum = 0;
        if (frecuencia == 100) {
          frecuencia = 1000;
          cambiarFrecuenciaPWM(frecuencia);
        } else {
          frecuencia = 100;
          cambiarFrecuenciaPWM(frecuencia);
        }
      }
    } else {
      dis_aum = 1;
      tiem_frec = millis();
    }
  } else {
    dis_aum = 0;
    if ((BOTONES_nuevo[1] == 1) && (BOTONES_nuevo[1] != BOTONES_viejo[1])) {
      apagado = millis();
      if (velocidad < 100) {
        velocidad = velocidad + 10;
      }
    } else if ((BOTONES_nuevo[2] == 1) && (BOTONES_nuevo[2] != BOTONES_viejo[2])) {
      apagado = millis();
      if (velocidad > 0) {
        velocidad = velocidad - 10;
      }
    }
  }
  cambiarFrecuenciaPWM(frecuencia);
  Serial.print("PWM: ");
  Serial.print(velocidad);
  Serial.println("%");
  analogWrite(MOTOR, ((velocidad * 255) / 100));
}