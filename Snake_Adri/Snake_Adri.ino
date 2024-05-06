#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;



void setup() {
 
comida_X = random(8);
comida_Y = random(32);

  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control( MD_MAX72XX::UPDATE, true );
}

 int rr = 0;
void loop() {

comida_X = random(8);
comida_Y = random(32);
  cartel.setPoint(comida_X,comida_Y, true);
for(int Fila = 0; Fila < 8; Fila++){
  
}
  //cartel.update();
  delay(1000);
  cartel.clear();
  //cartel.update();
  delay(1000);
  
}

