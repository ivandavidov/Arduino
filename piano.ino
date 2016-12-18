/*

  Based on project 06 from the starter kit.
  
  Set PIANO to false in order to get the default project behavior
  which is thermin-like sound effect.
  
  Set PIANO to true in order to get 8-tone piano simulation.
  
  LED #13 will blink if the device is not calibrated. Calibration is
  done in the first 5 seconds while the LED is constantly bright. Just
  cover the photo resistor and then move your hand away. That's enough
  for the calibration to take effect.
  
*/

const int LED_PIN = 13;
const int MIN_PITCH = 50;
const int MAX_PITCH = 6000;
const int INTERVAL = (MAX_PITCH - MIN_PITCH) / 9;
const int CALIBRATION_OFFSET = 50;

const bool PIANO = true;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

bool calibrated = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  while(millis() < 5000) {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  if(sensorHigh - sensorLow > CALIBRATION_OFFSET) {
    calibrated = true;
    digitalWrite(LED_PIN, LOW);
  }
}

void loop() {
  if(!calibrated) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    
    return;
  }
  
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, MIN_PITCH, MAX_PITCH);
    
  if(PIANO) {
    int pos = pitch / INTERVAL;
    
    switch (pos) {
      case 0: {
        // do+
        pitch = 523;
        break;
      }
      case 1: {
        // si
        pitch = 494;
        break;
      }
      case 2: {
        // la
        pitch = 440;
        break;
      }
      case 3: {
        // sol
        pitch = 392;
        break;
      }
      case 4: {
        // fa
        pitch = 349;
        break;
      }
      case 5: {
        // mi
        pitch = 330;
        break;
      }
      case 6: {
        // re
        pitch = 294;
        break;
      }
      case 7: {
        // do
        pitch = 262;
        break;
      }
      case 8:
      default: {
        pitch = 0;
        break;
      }
    }
  }
  
  if(pitch >= MIN_PITCH) {
    tone(8, pitch, 20);  
    digitalWrite(LED_PIN, HIGH);
    delay(10);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
