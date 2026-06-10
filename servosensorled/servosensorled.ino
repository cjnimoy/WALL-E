#include <Servo.h>

Servo servo;

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Servo pin
const int servoPin = 13;

// LED pins
const int leftled = 5;
const int middleled = 6;
const int rightled = 7;

long duration;

void setup() {
  servo.attach(servoPin)

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(leftled, OUTPUT);
  pinMode(middleled, OUTPUT);
  pinMode(rightled, OUTPUT);

  Serial.begin(9600);

  //make the lights go green
}

void loop() {

  // LEFT (90° left of center)
  servo.write(20);
  delay(800);  // allow servo to reach position
  Serial.print("Left (0°): ");
  Serial.print(getDistance(leftled));
  Serial.println(" cm");

  // FORWARD
  servo.write(90);
  delay(800);
  Serial.print("Forward (90°): ");
  Serial.print(getDistance(middleled));
  Serial.println(" cm");

  // RIGHT (90° right of center)
  servo.write(160);
  delay(800);
  Serial.print("Right (180°): ");
  Serial.print(getDistance(rightled));
  Serial.println(" cm");

  // FORWARD
  servo.write(90);
  delay(800);
  Serial.print("Forward (90°): ");
  Serial.print(getDistance(middleled));
  Serial.println(" cm");
}

// Function to read ultrasonic distance
int getDistance(int pinnum) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout

  if (duration == 0) {
    return -1; // no echo received
  }

  if ((duration * 0.034 / 2) < 10) {
    Serial.print("light on?");
    digitalWrite(pinnum, LOW);
  } else {
    Serial.print("light off?");
    digitalWrite(pinnum, HIGH);
  }

  return duration * 0.034 / 2;
}

