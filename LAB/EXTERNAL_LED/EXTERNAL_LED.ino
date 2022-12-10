void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       // wait for a second
  digitalWrite(D5, LOW);    // turn the LED off by making the voltage LOW
  delay(600);                       // wait for a second

  digitalWrite(D6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       // wait for a second
  digitalWrite(D6, LOW);    // turn the LED off by making the voltage LOW
  delay(600);

  digitalWrite(D7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       // wait for a second
  digitalWrite(D7, LOW);    // turn the LED off by making the voltage LOW
  delay(600);

}
