
int buz=  9;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(buz,50);
  delay(100);
  analogWrite(buz,0);
  delay(200);
}
