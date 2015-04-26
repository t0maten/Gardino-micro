int red = 2;
int green = 3;
int blue = 4;
int probe = 7;
int soil = 18;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(probe, OUTPUT);
}

void loop() {
  digitalWrite(probe, HIGH);
  delay(1000);
  int SoilValue = analogRead(soil);
  Serial.println(SoilValue);
  if (SoilValue >= 700 && SoilValue < 1200)
  {
    Serial.println(F("Dry"));
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
  else if (SoilValue >= 150 && SoilValue < 700)
  {
    Serial.println(F("Moist :)"));
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
  else if (SoilValue >= 0 && SoilValue < 150)
  {
    Serial.println(F("To mutch"));
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  digitalWrite(probe, LOW);
  delay(30000);
}
