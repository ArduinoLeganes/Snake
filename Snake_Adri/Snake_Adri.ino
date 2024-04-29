#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW


MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, 11, 13, 10, 4);

int comida_X;
int comida_Y;







void setup() {
  // inicializar el objeto mx
  cartel.begin();

  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control( MD_MAX72XX::UPDATE, true );
}

 int rr = 0;
void loop() {
  cartel.setPoint(5,12, true);
  cartel.setPoint(5,20, true);
  cartel.setPoint(7,31, true);
  cartel.setPoint(1,26, true);
  //cartel.update();
  delay(1000);
  cartel.clear();
  //cartel.update();
  delay(1000);

}

