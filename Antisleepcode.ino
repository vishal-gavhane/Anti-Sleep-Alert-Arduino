const int irSensorPin = 2;
const int buzzerPin = 9;
const int motorPin = 13;
const int LEDPin = 8;

unsigned long eyeClosedTime = 0;
unsigned long eyeOpenTime = 0;
bool eyesClosed = false;
bool motorStopped = false;
bool buzzerStarted = false;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(LEDPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(motorPin, HIGH); // Motor starts ON

  Serial.begin(9600);
  Serial.println("System ready. Monitoring eyes...");
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == LOW) { // Eyes closed
    if (!eyesClosed) {
      eyesClosed = true;
      eyeClosedTime = millis();
      Serial.println("Eyes closed. Watching...");
    } else {
      unsigned long elapsed = millis() - eyeClosedTime;

      if (!buzzerStarted && elapsed >= 1700) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(LEDPin, HIGH);
        buzzerStarted = true;
        Serial.println("Alert! Eyes closed too long. Buzzer ON.");
      }

      if (!motorStopped && elapsed >= 2700) {
        digitalWrite(motorPin, LOW);
        motorStopped = true;
        Serial.println("Danger! Driver may be asleep. Motor OFF");
      }
    }
    eyeOpenTime = millis(); // Reset open timer
  } else { // Eyes open
    if (millis() - eyeOpenTime >= 1000) {
      eyesClosed = false;
      motorStopped = false;
      buzzerStarted = false;
      digitalWrite(buzzerPin, LOW);
      digitalWrite(LEDPin, LOW);
      digitalWrite(motorPin, HIGH); // Motor back ON
      Serial.println("Eyes open, All Clear");
    }
  }
}
