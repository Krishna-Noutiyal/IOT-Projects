// This code uses photoresistor to detect the excess emission of light
// from fire to start a fire alarm
// The connection is as follows

/*
Connect a photoresistor to 5v output of arduino
connect the other end of the photoresistor to A0
and an active buzzer on pin 10,connect the other terminal of the buzzer to GND


The code will continue to monitor the intensity of light and start the alarm
if the intensity of light increases above a specific threshold

*/

// You can change the buzzer pin to whatever you want
int buz = 10;

// Set the senstivity of circuit a normal range is in between 500-800
// but it can vary depending upon the environment lighting
int THRESHOLD = 600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buz,OUTPUT);
}

void loop() {

  int a = analogRead(A0);

  if (a>THRESHOLD){
    digitalWrite(buz,255);
  }
  else{
    digitalWrite(buz,0);
  }
  Serial.println(a);
  delay(100);
}
