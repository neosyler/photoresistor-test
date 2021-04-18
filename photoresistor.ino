int ldr = A0; //Set A0(Analog Input) for LDR.
int value = 0;
// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
}

void loop() {
  value = analogRead(ldr); //Reads the Value of LDR(light).
  Serial.println("LDR value is : "); //Prints the value of LDR to Serial Monitor.
  Serial.println(value);
  Serial.println("Sensor high is: ");
  Serial.println(sensorHigh);
  Serial.println("Sensor low is: ");
  Serial.println(sensorLow);

  if (value == 0 || value < sensorLow) 
  {
    digitalWrite(3, HIGH); //Makes the LED glow in Dark.
  }
  else
  {
    digitalWrite(3, LOW); //Turns the LED OFF in Light.
  }
}
