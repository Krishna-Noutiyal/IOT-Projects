

int DELAY = 1000; // Initail delay
int RESET = DELAY; // Variable to reset to default delay
int DECREMENT = 500; // value to be decresed each time


int n = 0;

int RED = 10; // PINOUT for RED LED
int YELLOW = 9; // PINOUT for YELLOW LED
int GREEN = 6; // PINOUT for GREEN LED

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*
  if (n >=DECREMENT*0.1){
    DELAY = RESET;
    n = 0;
  }
  */
  if (DELAY <=100 ){
    DELAY = 0;
    n++;
  }
  else if (DELAY <= DECREMENT){
    DELAY = DECREMENT;
    DECREMENT = DECREMENT*0.1;
  }
  digitalWrite(RED,1);
  delay(DELAY);

  digitalWrite(YELLOW,1);
  digitalWrite(RED,0);
  delay(DELAY);

  digitalWrite(YELLOW,0);
  digitalWrite(GREEN,1);
  delay(DELAY);
  digitalWrite(GREEN,0);

  DELAY -= DECREMENT;


}
