void setup() {
    // Corrected line to include the missing semicolon
    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);

    // Additional setup code, if any
}