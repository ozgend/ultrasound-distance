// denolk
// distance measure & trigger / toggler
// HC-SR04 ultrasound

#define pinTransistor   6
#define pinEcho         7
#define pinTrigger      8
#define speedOfSound    58.2   // mach
#define rangeMax        20     // cm
#define rangeMin        0      // cm

long duration, distance;
bool isTransistorOn = false;

void setup() {
  Serial.begin (9600);
  pinMode(pinTransistor, OUTPUT);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void switchTransistor(bool isOn) {
  if (isOn) {
    digitalWrite(pinTransistor, HIGH);
  }
  else {
    digitalWrite(pinTransistor, LOW);
  }
}

void toggleTransistor() {
  switchTransistor(isTransistorOn);
  isTransistorOn = !isTransistorOn;
}

void loop() {
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);

  duration = pulseIn(pinEcho, HIGH);
  distance = duration / speedOfSound;

  if (distance >= rangeMin && distance <= rangeMax) {
    Serial.print(distance);
    Serial.println(" cm");
    toggleTransistor();    
    //switchTransistor(true);
  }
  else {    
    //switchTransistor(false);
  }

  delay(500);
}
