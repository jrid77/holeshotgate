int receiver = 2;
int primeLight = LED_BUILTIN;
int gatePin = 1;
int randomTime;
int RANDOM_WAIT = 4;
int RANDOM_FIXED = 4;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(receiver, INPUT);
  pinMode(primeLight, OUTPUT);
  pinMode(gatePin, OUTPUT);
  randomSeed(analogRead(0));
}
void loop() {
  while (digitalRead(receiver) == 0) {
    // do nothing
  }
  dropGate();
}

void dropGate() {
  digitalWrite(primeLight, HIGH);
  randomTime = (RANDOM_FIXED + random(RANDOM_WAIT)) * 1000;
  delay(randomTime);
  digitalWrite(gatePin, HIGH);
  delay(1000);
  digitalWrite(gatePin, LOW);
  digitalWrite(primeLight, LOW);   
}

