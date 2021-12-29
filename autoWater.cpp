const int pump = 10;
const int sensor = A3;
const int dry = 230; //this is the threshold for when watering will begin, this level is considered too dry.

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  digitalWrite(pump, HIGH);
  delay(5000);
}

void loop() {
  //checking current moisture levels
  int moistureLevel = analogRead(sensor);
  Serial.println(moistureLevel);
  delay(5000);
  
  if (moisture >= dry) {
    //too dry -> add water
    Serial.println("Watering starts now..moisture is " + String(moisture));
    digitalWrite(pump, LOW);

    //water for 10 second
    delay(10000);

    //stop watering
    digitalWrite(pump, HIGH);
    Serial.println("Done watering.");
  } else {
    Serial.println("Moisture is adequate. No watering needed " + String(moisture));
  }
}
