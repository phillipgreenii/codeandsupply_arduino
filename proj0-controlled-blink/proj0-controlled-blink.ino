// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  
  pinMode(7, INPUT);
}

int nextValue = HIGH;

int opposite(int val) {
  if (val == LOW) {
    return HIGH;
  } else {
    return LOW;
  }
}

// the loop function runs over and over again forever
void loop() {

  if(digitalRead(7) == HIGH) {
    // same
    digitalWrite(13, nextValue);
    digitalWrite(12, nextValue); 
  } else {
    // different
    digitalWrite(13, nextValue);
    digitalWrite(12, opposite(nextValue)); 
  }
  nextValue = opposite(nextValue);
  delay(250);
}
