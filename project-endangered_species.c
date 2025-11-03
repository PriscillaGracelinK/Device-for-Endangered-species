// === Device for Endangered Species ===
// PIR -> pin 2, Pulse Sensor -> A0, LED -> 13

#define PIR_PIN 2
#define PULSE_PIN A0
#define LED_PIN 13
#define PULSE_THRESHOLD 600  // adjust based on simulation value

void setup() {
    Serial.begin(9600);
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Simulation started...");
}

void loop() {
    int pulseRaw = analogRead(PULSE_PIN);
    int pirState = digitalRead(PIR_PIN);

    Serial.print("PulseRaw: ");
    Serial.print(pulseRaw);
    Serial.print("   PIR: ");
    if (pirState == HIGH) {
        Serial.println("MOTION");
    } else {
        Serial.println("NO MOTION");
    }

    if (pulseRaw > PULSE_THRESHOLD && pirState == HIGH) {
        Serial.println("⚠️ ALERT TRIGGERED ⚠️");
        Serial.println("SIMULATED GSM: Sending SMS...");
        Serial.println("Animal in danger! PulseRaw: ");
        Serial.println(pulseRaw);
        Serial.println("Location: [Simulated GPS Data]");
        digitalWrite(LED_PIN, HIGH);
        delay(2000);
        digitalWrite(LED_PIN, LOW);
    }

    delay(1000);
}
