#include <Wire.h>

void setup() {
  Wire.begin(); 
  Wire.beginTransmission(8);
}

void pararmusica() {
 
  Wire.write("p"); // p para parar
 
}
void reproducirmusica() {
 
  Wire.write("r"); // r para reproducir
 
}