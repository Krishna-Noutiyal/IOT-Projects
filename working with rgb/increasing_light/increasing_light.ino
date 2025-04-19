
int R = 13;
int G = 12;
int B = 11;
int level = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (level < 255){
    level +=1;
  }
  else{
    level = 0;
  }
  analogWrite(R,level);
  delay(20);

}
