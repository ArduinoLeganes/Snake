#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;
int Fila;
int Columna;
bool pantalla[8][32];

void updatePantalla() {
  for (int Fila = 0; Fila < 8; Fila++) {
    for (int Columna = 0; Columna < 32; Columna++) {
      cartel.setPoint(Fila, Columna, pantalla[Fila][Columna]);
    }
  }
}

void generarComida() {
  comida_X = random(8);
  comida_Y = random(32);
  while (pantalla[comida_X][comida_Y] == true) {
    comida_X = random(8);
    comida_Y = random(32);
  }
  pantalla[comida_X][comida_Y] = true;
}

void setup() {

  comida_X = random(8);
  comida_Y = random(32);

  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, true);
}

void loop() {

  generarComida();

  updatePantalla();
  delay(200);
}
