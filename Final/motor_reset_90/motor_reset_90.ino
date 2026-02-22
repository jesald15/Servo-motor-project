#include <Servo.h>

#define NUM_SERVOS 32

Servo servos[NUM_SERVOS];

// Change these pins to match your wiring
int servoPins[NUM_SERVOS] = {
  22, 23, 24, 25, 26, 27, 28, 29,
  30, 31, 32, 33, 34, 35, 36, 37,
  38, 39, 40, 41, 42, 43, 44, 45,
  46, 47, 48, 49, 50, 51, 52, 53
};

void setup() {

  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(90);   // Reset to 90 degrees
    delay(20);             // Small delay to avoid power surge
  }

}

void loop() {
  // Nothing needed
}
