// Declara variables para almacenar el estado del joystick
int xAxis, yAxis;
int direccion;
int Umbral = 100;
void setup() {
// Inicializa el motor en el pin digital 9
pinMode(9, OUTPUT);
Serial.begin(9600);
}

void loop() {
// Lee la posición del eje X del joystick y asigna el valor a la variable xAxis
xAxis = analogRead(A0);
// Lee la posición del eje Y del joystick y asigna el valor a la variable yAxis
yAxis = analogRead(A1);
Serial.print("xAxis: ");
Serial.println(xAxis);
Serial.print("yAxis: ");
Serial.println(yAxis);
delay(400);
if (xAxis > 512) {
digitalWrite(9, HIGH);
}
// 0 = izquierda, 1 = decbar, 2 = arriba, 3= abajo
// Si el joystick se mueve hacia la izquierda, gira el motor en sentido antihorario
if (xAxis < (512-Umbral)) {
  direccion = 0;
}
// Si el joystick no se mueve, detiene el motor
if (xAxis > (512+Umbral)) {
  direccion = 1;
}

if (yAxis < (512-Umbral)) {
  direccion = 2;
}
// Si el joystick no se mueve, detiene el motor
if (yAxis > (512+Umbral)){
  direccion = 3;
}
Serial.println(direccion);
}