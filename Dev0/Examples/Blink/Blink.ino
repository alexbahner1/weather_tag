/*
 * This is a Dev test is tosee if Mcu is working but make a LED blink 
 */


 //int var 
 int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);

}
