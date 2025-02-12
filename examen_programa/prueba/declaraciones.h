#ifndef declaraciones_h
#define declaraciones_h
/*solo para declarar las variables y ver el .ino mas vacio*/

/*Pine Motor*/
  extern const int MOTOR;

/* Pines BOTONES B*/
  //1 presionado y 0 no presionado
  extern const int B_STAR;
  extern const int B_PWM_MAS;
  extern const int B_PWM_MENOS;
  extern const int B_STOP;
  extern const int B_VELO_CAMB;
  extern const int B_MODO_CAMB;
  extern const int B_INV;

/* Pines Leds*/
  extern const int LED_1;
  extern const int LED_2;
  extern const int LED_3;
  extern const int LED_4;
  extern const int LED_INDICADOR;

void declaracion(){
  /* declaracion de pin de motor y sus valor inicial*/
    pinMode(MOTOR, OUTPUT);
    analogWrite(MOTOR, LOW);
  
  /*declaracion de BOTONES*/
    pinMode(B_STAR, INPUT);
    pinMode(B_PWM_MAS, INPUT);
    pinMode(B_PWM_MENOS, INPUT);
    pinMode(B_STOP, INPUT);
    pinMode(B_VELO_CAMB, INPUT);
    pinMode(B_MODO_CAMB, INPUT);
    pinMode(B_INV, INPUT);

  /*declaracion de leds y inicializacion*/
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
#endif