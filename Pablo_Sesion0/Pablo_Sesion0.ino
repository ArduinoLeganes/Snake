
int intensidad[][3] = {{148,0,121},{75,0,130},{0,0,255},{0,255,0},{255,255,0},{255,127,0},{255,0,0}};
const int PIN_RED  = 6;
const int PIN_GREEN = 5;
const int PIN_BLUE  = 3;


void setup() {
  // put your setup code here, to run once:
pinMode(PIN_RED,   OUTPUT);
pinMode(PIN_GREEN, OUTPUT);
pinMode(PIN_BLUE,  OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int y = 0;y <= 6;y += 1){
analogWrite(PIN_RED, intensidad[y][1]);
analogWrite(PIN_GREEN, intensidad[y][2]);
analogWrite(PIN_BLUE,  intensidad[y][3]);
delay(1000);
}
}
   