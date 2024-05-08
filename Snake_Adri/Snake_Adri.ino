#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;
int snake_head[2]; //posicion 0=x, posicion y=1
 
int movimiento_snake; // 0 arriba, 1 abajo, 2 izquierda, 3 derecha

void actualizar_snake(){
  if (movimiento_snake == 2){
    snake_head[1] = snake_head[1]-1;   //Esto mueve la luz de la cabeza a la izquierda
  }
 if (movimiento_snake == 3){
    snake_head[1] = snake_head[1]+1;   //Esto mueve la luz de la cabeza a la derecha
  }
  if (movimiento_snake == 1){
    snake_head[0] = snake_head[0]-1;   //Esto mueve la luz de la cabeza abajo
  }
 if (movimiento_snake == 0){
    snake_head[0] = snake_head[0]+1;   //Esto mueve la luz de la cabeza arriba
  }
 
}
pantalla[snake_head[1]][snake_head[0]] = true;

bool pantalla[8][32];

void updatePantalla()
{
  for(int Fila = 0; Fila < 8; Fila++){
  for(int Columna = 0; Columna < 32; Columna++){
 cartel.setPoint(Fila,Columna, pantalla[Fila][Columna]);
  }
}
}

void generarComida()
{
comida_X = random(8);
comida_Y = random(32);
pantalla[comida_X][comida_Y] = true;
}

void setup() {

snake_head[0] = (2, 3);
snake_head[1] = (3, 4);
comida_X = random(8);
comida_Y = random(32);

  // inicializar el objeto mx
  cartel.begin();


snake_head[0] = 4;
snake_head[1] = 12;
pantalla[snake_head[0], snake_head[1]] = true;
snake_head[1] = snake_head[1] + 1;
pantalla[snake_head[0], snake_head[1]] = true;



  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control( MD_MAX72XX::UPDATE, true );
}

void loop() {

movimiento_snake = 1;
actualizar_snake();


  
updatePantalla();
delay(200);
}

