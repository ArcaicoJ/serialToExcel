int sensorPin = A2;
int ledPin = 13;
int sensorValue = 0;
const int AirValue = 1023;   //you need to replace this value with Value_1
const int WaterValue = 895;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent = 0;
void setup() {
  Serial.begin(115200);

  pinMode(A2, INPUT);
  pinMode(7, OUTPUT);
}

int i = 0;
void loop() {

  sensorValue = analogRead(sensorPin);
  soilmoisturepercent = map(sensorValue, AirValue, WaterValue, 0, 100);

  Serial.print(i);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.println(";");


  delay(100);
  if (sensorValue > 988) {
    i = i + 1;
    sensorValue = analogRead(sensorPin);
    digitalWrite(7, HIGH);
    Serial.print(i);
    Serial.print(",");
    Serial.print("bomba activa");
    Serial.println(";");
    delay(100);
  }
  else {
    digitalWrite(7, LOW);
  }
  i = i + 1;
}
