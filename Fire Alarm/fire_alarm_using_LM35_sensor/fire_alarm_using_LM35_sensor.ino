/*

This code uses the LM35 sensor to create a fire alarm

Connections:

5v in to 1st pin of LM35 ( facing the flat side )
connect the middle pin of LM35 to A0 pin in ardurino
Ground the 3rd pin of LM35

Connect + side of an active buzzer to digital pin 10
Ground the negative pin of the buzzer

The code is going to monitor the tempratour of surrounding and start the alarm
if a fire occurs
*/


// Analog pin of LM35 Temprature sensor
int LM35 = 0;

// Buzzer pin
int BUZ = 10;

// Alarm Temprature in celcius
float TEMP = 60;



void setup() {

  pinMode(BUZ,OUTPUT);
  Serial.begin(9600);

}

void loop() {

  float temp_input = analogRead(LM35) * (5.0/1023.0);
  //float temp_reading = ceil(temp_input *100);
  float temp_reading = temp_input *100; // removed ceil for precies measurement & testing


  if (temp_reading > TEMP){
    digitalWrite(BUZ,255);
  }
  else{
    digitalWrite(BUZ,0); // You can remove this else if you want the buzzer to beep continuesly if fire is detected
  }
  Serial.println(temp_reading);
  delay(100);
}
