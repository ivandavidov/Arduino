/*
Morse code SOS signal via LED on pin #13.
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  morseS();
  morseO();
  morseS();
}

void morseS() {
  morseDot();
  morsePauseSignal();
  morseDot();
  morsePauseSignal();
  morseDot();
  morsePauseChar();
}

void morseO() {
  morseDash();
  morsePauseSignal();
  morseDash();
  morsePauseSignal();
  morseDash();
  morsePauseChar();
}

void morseDash() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void morseDot() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
}

void morsePauseSignal() {
  digitalWrite(13, LOW);
  delay(200);
}

void morsePauseChar() {
  digitalWrite(13, LOW);
  delay(1000);
}
