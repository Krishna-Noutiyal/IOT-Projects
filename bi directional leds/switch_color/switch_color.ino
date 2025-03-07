/*

Connection Layout:

The First leg of LED is connected to digital pin 9
The Middel leg of LED is grounded with a resistence of 220ohm
The Last leg of LED is connected to digital pin 8
*/
int S1 = 9; // First leg of LED
int S2 = 8; // Last leg of LED
int DELAY = 1000; // Delay in color switching

void setup() {
  // put your setup code here, to run once:
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(S2,0);
  digitalWrite(S1,1);
  delay(DELAY);
  digitalWrite(S1,0);
  digitalWrite(S2,1);
  delay(DELAY);
}
