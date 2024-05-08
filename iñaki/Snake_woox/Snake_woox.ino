#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;
int snake_head[2];     // posicion 0=x, posicion y=1
bool pantalla[8][32];  // Pantalla de juego. Las posiciones con false están vacías.

int movimiento_snake;  // 0 arriba, 1 abajo, 2 izquierda, 3 derecha

void actualizar_snake() {
  if (movimiento_snake == 2) {
    snake_head[1] = snake_head[1] - 1;  //Esto mueve la luz de la cabeza a la izquierda
  }
  if (movimiento_snake == 3) {
    snake_head[1] = snake_head[1] + 1;  //Esto mueve la luz de la cabeza a la derecha
  }
  if (movimiento_snake == 1) {
    snake_head[0] = snake_head[0] - 1;  //Esto mueve la luz de la cabeza abajo
  }
  if (movimiento_snake == 0) {
    snake_head[0] = snake_head[0] + 1;  //Esto mueve la luz de la cabeza arriba
  }

  pantalla[snake_head[1]][snake_head[0]] = true;
}


void updatePantalla() {
  for (int Fila = 0; Fila < 8; Fila++) {
    for (int Columna = 0; Columna < 32; Columna++) {
      cartel.setPoint(Fila, Columna, pantalla[Fila][Columna]);
    }
  }
}

void setup() {
  snake_head[0] = 4; // Establecemos las coordenadas iniciales de la cabeza de la serpiente
  snake_head[1] = 16;
  pantalla[snake_head[0], snake_head[1]] = true;

  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Activamos auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, true);
}

void loop() {
  movimiento_snake = 1; // Esta línea es sólo para probar
  actualizar_snake();

  updatePantalla();
  delay(1000);
}

/*
TODO:
- Conseguir que la serpiente desde un punto inicial se mueva a cada dirección
  Esto serán 4 ejecucuciones del mismo código pero cambiaremos el valos de movimiento_snake para indicar hacia donde queremos que avance.

- Conseguir que la serpiente se mueva en circulos.
  Para esto será necesario cambiar la dirección de movimiento cada x ciclos

- Conseguir que la serpiente mantenga cierta longitud
  Esto se hace en la función actualizar_snake. Además de mover la cabeza hay que apagar el led de la cola.
    Para saber cual es la cola necesitaremos guardar las posiciones donde están las partes de la serpiente,
    necesitaremos un array bidimensional, que se actualice al moverse.
*/
