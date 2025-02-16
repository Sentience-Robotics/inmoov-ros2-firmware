#include "../include/Arm.hpp"

Arm::Arm(SideType side): _side(side), wrist(side), hand(side) {}

void
Arm::setup()
{
    wrist.setup();
    hand.setup();
}

/**
 * @brief Greet
 * @details Greet moving the wrist
 */
void Arm::greet()
{
    hand.thumb.setPosition(40);
    hand.index.setPosition(55);
    hand.middle.setPosition(40);
    hand.ring.setPosition(50);
    hand.pinky.setPosition(35);

    for (int i = 0; i < 5; i++)
    {
        wrist.setPosition(75);
        delay(SERVO_DELAY_PER_DEGREE * 90);
        wrist.setPosition(25);
        delay(SERVO_DELAY_PER_DEGREE * 90);
    }
    wrist.setPosition(50);
}
