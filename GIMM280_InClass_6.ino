//Declare variables
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() 
{
  Serial.begin(9600);
  Serial.println(" Calibrating Now: ");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;  
    }
  }
  
  //Display the sensor values after finsihed calibrating
  digitalWrite(ledPin, LOW);
  Serial.print("sensorLow: ");
  Serial.print(sensorLow);
  Serial.print(" sensorHigh: ");
  Serial.println(sensorHigh);
}

void loop() 
{
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  int toner = map(sensorValue, sensorLow, sensorHigh, 10, 300);
  tone(8,pitch);
  delay (toner);
  noTone(8);
  delay (toner * 0.1);
}
