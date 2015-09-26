#define INC_LED_PIN 2
#define DEC_LED_PIN 4
#define SUBMIT_LED_PIN 3

#define CORRECT_LED_PIN 8
#define WRONG_LED_PIN 9

#define MIN_GUESS 0
#define MAX_GUESS 9

void setup() {

  Serial.begin(9600);
  
  pinMode(INC_LED_PIN, INPUT);
  pinMode(DEC_LED_PIN, INPUT);
  pinMode(SUBMIT_LED_PIN, INPUT);
  pinMode(CORRECT_LED_PIN, OUTPUT);
  pinMode(WRONG_LED_PIN, OUTPUT);
}

int reguess() {
  int newGuess = random(MIN_GUESS, MAX_GUESS);

  //Serial.print("New Guess: ");
  //Serial.println(newGuess); 

  return newGuess;
}

int currentValue = 5;
int guess = 5;
int changed = 1;
void loop() {
  if(changed) {
    Serial.print("Current Guess: ");
    Serial.println(currentValue);  
    changed = 0;
  }
  
  if(digitalRead(INC_LED_PIN) == HIGH) {
    currentValue++;
    changed = 1;
  }

  if(digitalRead(DEC_LED_PIN) == HIGH) {
    currentValue--;
    changed = 1;
  }

  currentValue = constrain(currentValue, MIN_GUESS, MAX_GUESS);

  if(digitalRead(SUBMIT_LED_PIN) == HIGH) {
    if(guess == currentValue) {
      Serial.println("You are correct");  
      changed = 1;
      guess = reguess();
      digitalWrite(CORRECT_LED_PIN, HIGH);
      digitalWrite(WRONG_LED_PIN, LOW);
    } else {
      Serial.println("You are wrong");  
      digitalWrite(CORRECT_LED_PIN, LOW);
      digitalWrite(WRONG_LED_PIN, HIGH);
    }
  }
  
  delay(100);
}
