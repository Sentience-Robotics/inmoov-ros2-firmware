#include <Arduino.h>
#include <Servo.h>

Servo servo;
byte incomingByte;
int angle = 90;     // Start at 90° (you can change this)
int servoSpeed = 1; // Speed of servo movement

void setup()
{
  servo.attach(1);
  Serial.begin(9600);
  Serial.println("Servo test!");
  servo.write(angle); // Set initial position
}

void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();

    if (incomingByte == 'd')
    {
      angle += servoSpeed; // Increase angle
    }
    else if (incomingByte == 'g')
    {
      angle -= servoSpeed; // Decrease angle
    }

    // Ensure angle stays within valid range
    angle = constrain(angle, 0, 180);

    servo.write(angle);
    Serial.print("Servo angle: ");
    Serial.println(angle);
  }
}
