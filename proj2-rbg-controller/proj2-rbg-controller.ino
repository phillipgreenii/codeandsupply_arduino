#define RED_LED_PIN 3
#define BLUE_LED_PIN 5
#define GREEN_LED_PIN 7

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(RED_LED_PIN, 255);
  analogWrite(BLUE_LED_PIN, 255);
  analogWrite(GREEN_LED_PIN, 255);
  delay(1000);
  analogWrite(RED_LED_PIN, 255);
  analogWrite(BLUE_LED_PIN, 0);
  analogWrite(GREEN_LED_PIN, 0);
  delay(1000);
  analogWrite(RED_LED_PIN, 0);
  analogWrite(BLUE_LED_PIN, 255);
  analogWrite(GREEN_LED_PIN, 0);
  delay(1000);
  analogWrite(RED_LED_PIN, 0);
  analogWrite(BLUE_LED_PIN, 0);
  analogWrite(GREEN_LED_PIN, 255);
  delay(1000);
}
