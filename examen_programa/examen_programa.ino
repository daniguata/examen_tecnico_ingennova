#include "declaraciones.h"
#include "maquinaEstados.h"
#include "BOTONES.h"
#include "MOTOR.h"
#include "LEDS.h"

void setup() {
  Serial.begin(9600);
  declaracion();

  // Configura el Timer1 para generar una señal PWM de 1 kHz
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1 = 999; // Frecuencia = 16 MHz / (1 * (999 + 1)) = 1 kHz
  OCR1A = round((velocidad * ICR1) / 100); // Ciclo de trabajo = 50%
  DDRB |= _BV(PB3); // Pin 11 como salida
}

void loop() {
  static unsigned long tiem_modo = 0; // Declaración static dentro de loop()
  static unsigned long STOP_T = 0;    // Declaración static dentro de loop()

  switch (EXAMEN) {
    case START:
      barrido_botones();
      if (BOTONES_nuevo[0] == 1) {
        apagado = millis();
        tiem_modo = millis();
        tiem_frec = millis();
        asignar(TRABAJO);
        digitalWrite(LED_INDICADOR, HIGH);
      }
      break;

    case TRABAJO:
      barrido_botones();

      if (BOTONES_nuevo[3] == 1) {
        STOP_T = millis();
        asignar(STOP);
      }

      BOTONES_AUMENTO_DISMINUCION();
      SELECCION_MODOS_leds();

      if ((millis() - tiem_modo) >= duracion_led) {
        tiem_modo = millis();
        switch (modo) {
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

      if ((millis() - apagado) >= 30000) {
        apagado_leds();
        digitalWrite(LED_INDICADOR, LOW);
        analogWrite(MOTOR, LOW);
        asignar(START);
      }
      break;

    case STOP:
      apagado_leds();
      analogWrite(MOTOR, LOW);
      int valor_T_stop = millis() - STOP_T;

      if ((millis() - STOP_T) >= 10000) {
        asignar(START);
      }

      Serial.print("STOP: ");
      Serial.print(valor_T_stop / 1000);
      Serial.println("s");
      break;
  }
}