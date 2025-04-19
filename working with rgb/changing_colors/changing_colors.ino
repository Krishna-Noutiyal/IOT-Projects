int R = 13;
int G = 12;
int B = 11;

int AC = 10;

int RB = A3;
int GB = A4;
int BB = A5;
int PNB = A2;  // Positive Negetive Button

int color[3] = { 0, 0, 0 };
int DIFF = 3;

void setup() {
  pinMode(RB, INPUT);
  pinMode(GB, INPUT);
  pinMode(BB, INPUT);
  pinMode(PNB, INPUT);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(AC, OUTPUT);

  digitalWrite(AC, HIGH);

  Serial.begin(9600);
}

void rgb(int r, int g, int b) {
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;

  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}

void getcolor() {
  // Check button input and decrease color values if pressed
  int pnb = analogRead(PNB);
  // Increase RGB values if 5v is given
  if (pnb == 1023) {
    if (analogRead(RB) == 0) {
      color[0] = max(color[0] + DIFF, 0);
    }
    if (analogRead(GB) == 0) {
      color[1] = max(color[1] + DIFF, 0);
    }
    if (analogRead(BB) == 0) {
      color[2] = max(color[2] + DIFF, 0);
    }
  } 
  // Decrease RGB values if vcc is not given
  else {
    if (analogRead(RB) == 0) {
      color[0] = max(color[0] - DIFF, 0);
    }
    if (analogRead(GB) == 0) {
      color[1] = max(color[1] - DIFF, 0);
    }
    if (analogRead(BB) == 0) {
      color[2] = max(color[2] - DIFF, 0);
    }
  }


  rgb(color[0], color[1], color[2]);
}
void loop() {
  getcolor();  // update color based on button press

  int r = analogRead(RB);
  int g = analogRead(GB);
  int b = analogRead(BB);
  int pnb = analogRead(PNB);

  // Print color values in r,g,b format
  Serial.print(r);
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.print(pnb);
  Serial.println("");


  delay(100);  // debounce and smoother dimming
}
