#include <Arduino.h>
#include "../include/Arm.hpp"

// Arm rightArm(SideType::RIGHT);
// Servo elbow;
Servo test;
Servo test2;
Servo test3;
Servo test4;
Servo test5;
Servo test6;
Servo test7;
/**
 * @brief Setup function
 */
void setup()
{
    // rightArm.setup();

    // elbow.attach(RIGHT_ELBOW_SERVO_PIN);
    // elbow.write(RIGHT_ELBOW_DEFAULT_ANGLE);
    test.attach(2);
    test2.attach(3);
    test3.attach(4);
    test4.attach(5);
    test5.attach(6);
    test6.attach(7);
    test7.attach(8);
    test.write(0);
    test2.write(90);
    test3.write(135);
    test4.write(150);
    test5.write(180);
    test6.write(270);
    test7.write(300);


    // Wait for servos setup
    delay(1250);
}

/**
 * @brief Loop function
 */
void loop()
{

    Serial.println("---------------------------- DEMO STARTED ! ----------------------------");

    test.write(135);
    // elbow.write(RIGHT_ELBOW_MIN_ANGLE);
    // rightArm.wrist.setPosition(0);
    // delay(3000);

    // elbow.write(RIGHT_ELBOW_MAX_ANGLE);
    // rightArm.wrist.setPosition(20);
    // delay(3000);

    // elbow.write(55);
    // delay(1500);

    // rightArm.hand.thumb.setPosition(100);
    // delay(1000);
    // rightArm.hand.thumb.setPosition(0);
    // delay(500);
    // rightArm.hand.index.setPosition(100);
    // delay(1000);
    // rightArm.hand.index.setPosition(0);
    // delay(500);
    // rightArm.hand.middle.setPosition(100);
    // rightArm.hand.middle.setPosition(0);
    // rightArm.hand.ring.setPosition(100);
    // delay(1000);
    // rightArm.hand.ring.setPosition(0);
    // delay(500);
    // rightArm.hand.pinky.setPosition(100);
    // delay(1000);
    // rightArm.hand.pinky.setPosition(0);
    // delay(1000);

    // Serial.println("DEMO 1: close and reopen the hand");
    // rightArm.hand.close();
    // rightArm.hand.open();

    // Serial.println("DEMO 3: count");
    // rightArm.hand.count();

    // Serial.println("DEMO 4: hold");
    // rightArm.hand.hold();

    // elbow.write(RIGHT_ELBOW_MIN_ANGLE);
    // delay(3000);

    // elbow.write(RIGHT_ELBOW_MAX_ANGLE);
    // rightArm.wrist.setPosition(100);
    // delay(3000);

    Serial.println("---------------------------- DEMO FINISHED ! ----------------------------");
    while(1);
}
