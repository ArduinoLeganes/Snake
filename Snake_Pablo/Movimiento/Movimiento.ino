#include <MD_MAX72xx.h>
#include <LinkedList.h>  // Necesitarás una biblioteca de listas enlazadas para manejar la cola de la serpiente
#define MAX_DEVICES 4
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;
int snake_head[2];     // posición 0=x, posición y=1
bool pantalla[8][32];  // Pantalla de juego. Las posiciones con false están vacías.

LinkedList<int> cola_X;  // Lista enlazada para la cola X de la serpiente
LinkedList<int> cola_Y;  // Lista enlazada para la cola Y de la serpiente

int movimiento_snake;  // 0 arriba, 1 abajo, 2 izquierda, 3 derecha

void actualizar_snake() {
  // Agrega la posición actual de la cabeza a la cola
  cola_X.add(snake_head[0]);
  cola_Y.add(snake_head[1]);

  // Mueve la serpiente
  if (movimiento_snake == 0) snake_head[0]--;       // Arriba
  else if (movimiento_snake == 1) snake_head[0]++;  // Abajo
  else if (movimiento_snake == 2) snake_head[1]--;  // Izquierda
  else if (movimiento_snake == 3) snake_head[1]++;  // Derecha
Serial.println(snake_head[0]);
  // Si no ha comido, elimina el último segmento de la cola
  int tail_X = cola_X.remove(0);
  int tail_Y = cola_Y.remove(0);
  pantalla[tail_Y][tail_X] = false;
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
  Serial.begin(9600);
  snake_head[0] = 0; // Establecemos las coordenadas iniciales de la cabeza de la serpiente
  snake_head[1] = 0;
  pantalla[snake_head[0]] [snake_head[1]] = true;

  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Activamos auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, true);
}

