int fsrAnalogPin = A0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
//int LEDbrightness
int counter = 0;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  //pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  if (fsrReading > 0){
    counter = counter + 1;
  }
  if (counter > 100 && fsrReading == 0){
    counter = 0;
    analogWrite(LEDpin, LOW);
  }
  if (counter > 100){
    Serial.print("Lift your hand");
    analogWrite(LEDpin, HIGH); 
    delay(1000);
  }
  
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  //LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  //analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}
