#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int xAxis, yAxis;
int direccion;
int Umbral = 100;
int comida_X;
int comida_Y;
int Fila;
int Columna;

bool Ha_muerto;
bool Ha_comido;

bool pantalla[8][32];


void Crecer_serpiente() {

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

bool Comprobar_comida() {

}

bool Comprobar_muerte() {
Snake_head = 
}
}

void Game_over() {
}

void updatePantalla() {
  for (int Fila = 0; Fila < 8; Fila++) {
    for (int Columna = 0; Columna < 32; Columna++) {
      cartel.setPoint(Fila, Columna, pantalla[Fila][Columna]);
    }
  }
}

void actualizar_snake() {

}

void Read_joystick() {
  // 0 = izquierda, 1 = decbar, 2 = arriba, 3= abajo
  // Si el joystick se mueve hacia la izquierda, gira el motor en sentido antihorario
  if (xAxis < (512 - Umbral)) {
    direccion = 0;
  }
  // Si el joystick no se mueve, detiene el motor
  if (xAxis > (512 + Umbral)) {
    direccion = 1;
  }

  if (yAxis < (512 - Umbral)) {
    direccion = 2;
  }
  // Si el joystick no se mueve, detiene el motor
  if (yAxis > (512 + Umbral)) {
    direccion = 3;
  }
}


void setup() {
  generarComida();

  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, true);
}

void loop() {
  Read_joystick();
  actualizar_snake();
  Ha_comido = Comprobar_comida();
  if (Ha_comido == true) {
    Crecer_serpiente();
    generarComida();
  }
  Ha_muerto = Comprobar_muerte();
  if (Ha_muerto == true) {
    Game_over();
  }
  updatePantalla();
}
