#include <MD_MAX72xx.h>
#define MAX_DEVICES 4
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#include <LinkedList.h>


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int snake_head[2];
int direccion;
int xAxis, yAxis;
int Umbral = 100;
int comida_X;
int comida_Y;
int Fila;
int Columna;

LinkedList<int> cola_X;  // Lista enlazada para la cola X de la serpiente
LinkedList<int> cola_Y;  // Lista enlazada para la cola Y de la serpiente

bool Ha_muerto;
bool Ha_comido;


bool pantalla[8][32];
////////////////////////////////////////////


void Init() {
  for (int Iterador = 0; Iterador < 8; Iterador++) {
    for (int Iterador2 = 0; Iterador2 < 32; Iterador2++) {
      pantalla[Iterador][Iterador2] = false;
    }
  }
  snake_head[0] = 3;
  snake_head[1] = 16;
  cola_X.clear();
  cola_Y.clear();
  cola_X.add(snake_head[0]);
  cola_Y.add(snake_head[1]);

  pantalla[snake_head[0]][snake_head[1]] = true;
  generarComida();
  Ha_muerto = false;
  Ha_comido = false;
}


void actualizar_snake() {
  // Agrega la posición actual de la cabeza a la cola

  // Mueve la serpiente
  if (direccion == 2) snake_head[0]--;       // Arriba
  else if (direccion == 3) snake_head[0]++;  // Abajo
  else if (direccion == 1) snake_head[1]--;  // Izquierda
  else if (direccion == 0) snake_head[1]++;  // Derecha
  cola_X.add(snake_head[0]);
  cola_Y.add(snake_head[1]);
  Ha_comido = Comprobar_comida();
  Ha_muerto = Comprobar_muerte();
  if (Ha_comido == false) {  // Si no ha comido, elimina el último segmento de la cola
    int tail_X = cola_X.remove(0);
    int tail_Y = cola_Y.remove(0);
    pantalla[tail_X][tail_Y] = false;
  }
  pantalla[snake_head[0]][snake_head[1]] = true;
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
bool Sonido_Comida(){   
  tone(zumbadorPin, notaDo); 
  delay(1000); 
  noTone(zumbadorPin);}
bool Comprobar_comida() {

  //Serial.println(snake_head[0]);
  //Serial.println(snake_head[1]);
  //Serial.println(comida_X);
  //Serial.println(comida_Y);
  //Serial.println("");
  if (snake_head[0] == comida_X && snake_head[1] == comida_Y) {
    Serial.println("comidabien");
    return true;
  }
  return false;
}

bool Comprobar_muerte() {
  if (snake_head[0] < 0) {
    return true;
  }
  if (snake_head[0] > 7) {
    return true;
  }
  if (snake_head[1] < 0) {
    return true;
  }
  if (snake_head[1] > 31) {
    return true;
  }
  if (pantalla[snake_head[0]][snake_head[1]] == true) {
    if (snake_head[0] == comida_X && snake_head[1] == comida_Y) {
      return false;
    } else {
      return true;
    }
  }
  return false;
}
 
void Game_over() {
  for (int Iterador = 0; Iterador < 8; Iterador++) {
    for (int Iterador2 = 0; Iterador2 < 32; Iterador2++) {
      pantalla[Iterador][Iterador2] = true;
    }
  }
  updatePantalla();
  delay(2000);
  Init();
}

void updatePantalla() {
  for (int Fila = 0; Fila < 8; Fila++) {
    for (int Columna = 0; Columna < 32; Columna++) {
      cartel.setPoint(Fila, Columna, pantalla[Fila][Columna]);
    }
  }
}



void Read_joystick() {
  xAxis = analogRead(A0);
  yAxis = analogRead(A1);
  // 0 = izquierda, 1 = decbar, 2 = arriba, 3= abajo
  // Si el joystick se mueve hacia la izquierda, gira el motor en sentido antihorario
  if (xAxis < (512 - Umbral)) {
     if (direccion != 1) {
      direccion = 0;
  }
  }
  // Si el joystick no se mueve, detiene el motor
  if (xAxis > (512 + Umbral)) {
     if (direccion != 0) {
      direccion = 1;
  }
  }
  if (yAxis < (512 - Umbral)) {
 if (direccion != 3) {
      direccion = 2;
  }
  }

  // Si el joystick no se mueve, detiene el motor
  if (yAxis > (512 + Umbral)) {
    if (direccion != 2) {
      direccion = 3;
    }
  }
}



void setup() {
  Serial.begin(9600);
  Init();
  pinMode(9, OUTPUT);
  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, true);
}

void loop() {
  Read_joystick();
  // 0 = izquierda, 1 = decbar, 2 = arriba, 3= abajo
  actualizar_snake();

  if (Ha_comido == true) {

    generarComida();
    Ha_comido = false;
  }
  //Ha_muerto = Comprobar_muerte();
  Serial.println(direccion);
  if (Ha_muerto == true) {
    Game_over();
  }

  updatePantalla();
  delay(300);
}
