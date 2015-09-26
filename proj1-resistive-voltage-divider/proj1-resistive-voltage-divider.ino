#define FSR_PIN A0
#define LED_PIN 3

#define FSR_MIN 0
#define FSR_MAX 400

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(FSR_PIN, INPUT);
}

void loop() {
  int fsrReading = analogRead(FSR_PIN);

  Serial.print("Analog reading = ");
  Serial.print(fsrReading);
  Serial.print(" => ");

  fsrReading= constrain(fsrReading, FSR_MIN, FSR_MAX);

  int outputValue = map(fsrReading, FSR_MIN, FSR_MAX, 0, 255);
  analogWrite(LED_PIN, outputValue);

  Serial.println(outputValue);

  delay(100);
}
