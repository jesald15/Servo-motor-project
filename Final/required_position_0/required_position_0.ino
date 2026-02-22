#include <Servo.h>

#define NUM_SERVOS 32

Servo myServo[NUM_SERVOS];

void setup() {

  // Attach servos to pins 22–53
  for (int i = 0; i < NUM_SERVOS; i++) {
    myServo[i].attach(i + 22);
  }

  // Move all servos to 0 degrees
  for (int i = 0; i < NUM_SERVOS; i++) {
    myServo[i].write(0);
  }

}

void loop() {
  // Do nothing — hold position
}