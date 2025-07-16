int sensor = 0;

void setup() {
  pinMode(A4, INPUT);   // FSR connected to A4
  pinMode(9, OUTPUT);   // Buzzer connected to pin 9
  Serial.begin(9600);   // Start Serial Monitor
}

void loop() {
  sensor = analogRead(A4);  // Read sensor value

  if (sensor > 50) {  // Small threshold to ignore noise
    int frequency = map(sensor, 50, 1023, 200, 2000);  // Map pressure to tone
    tone(9, frequency);
    Serial.print("sensor = ");
    Serial.print(sensor);
    Serial.print(" | frequency = ");
    Serial.println(frequency);
  } else {
    noTone(9);  // No sound if no force
    Serial.println("sensor = 0 | no force");
  }

  delay(100);
}
