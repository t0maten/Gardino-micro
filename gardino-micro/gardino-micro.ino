
int red = 2;
int green = 3;
int blue = 4;
int probe = 5;
int soil = 18;
int relay1 = 10;
int relay2 = 16;
int relay3 = 14;
int relay4 = 15;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(probe, OUTPUT);
  pinMode(relay1, OUTPUT);
}

void loop() {
  lcd.print("hejhopp");
  delay(5000);
  Serial.println(F("Gardino Micro start"));
  Serial.println(F("Activating the Soil probe"));
  digitalWrite(probe, HIGH);
  delay(1000);
  int SoilValue = analogRead(soil);
  Serial.println(F("Start reading soil moisture"));
  if (SoilValue >= 700 && SoilValue < 1200)
  {
    Serial.println(F("The soil is dry please water"));
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    Serial.println(F("Start Watering for 30 Sec"));
    delay(1000);
    digitalWrite(relay1, 0);
    delay(30000);
    Serial.println(F("Water complete"));
    delay(1000);
    digitalWrite(relay1, 1);
  }
  else if (SoilValue >= 150 && SoilValue < 700)
  {
    Serial.println(F("Check if it's moist"));
    delay(100);
    Serial.println(F("Moist :)"));
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
  else if (SoilValue >= 0 && SoilValue < 150)
  {
    Serial.println(F("Check if its to moist"));
    delay(100);
    Serial.println(F("To mutch"));
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  Serial.println(F("Deactivating Soil probe"));
  digitalWrite(probe, LOW);
  Serial.println(F("End of Garduino micro repeats after 30 Sec"));
  delay(30000);
}
