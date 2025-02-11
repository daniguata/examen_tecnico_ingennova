#ifndef maquinaEstados_h
#define maquinaEstados_h
/*Maquina de estados*/
  //las diferentes posiciones que tiene
    enum ESTADOS{
      START,
      TRABAJO,
      STOP
    };

/*variable del estado*/
  //creacion de la varieble examen que me cambia los estados
  ESTADOS EXAMEN;

/*funcion para asignar un nuevo estado para la maquina de estados*/
  void asignar(ESTADOS eleccion) {
  EXAMEN = eleccion;
  }
#endif