#include <Servo.h>

// --- CONFIGURATION ---
const int NUM_SERVOS = 3;             // Change this to 32 when you add more
const int servoPins[] = {22, 24, 50}; // Add your pins here (e.g., 22, 23, 24...)

// Wave Settings
const float WAVE_SPEED = 0.002;       // Higher is faster
const float PHASE_SHIFT = 0.5;        // Difference between adjacent servos
const int CENTER_ANGLE = 90;          // Middle of servo movement
const int AMPLITUDE = 60;             // How far it swings (90 +/- 60)

Servo myServos[NUM_SERVOS];

void setup() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    myServos[i].attach(servoPins[i]);
  }
}

void loop() {
  unsigned long currentTime = millis();
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    // 1. Calculate the phase for this specific servo
    // Formula: sin(time_factor + (servo_index * offset))
    float phase = (currentTime * WAVE_SPEED) + (i * PHASE_SHIFT);
    
    // 2. Generate sine value (-1.0 to 1.0)
    float sineValue = sin(phase);
    
    // 3. Map to servo angle (0 to 180)
    int angle = CENTER_ANGLE + (sineValue * AMPLITUDE);
    
    // 4. Update servo
    myServos[i].write(angle);
  }
  
  // Small delay to prevent CPU saturation, but keeps motion fluid
  delay(15); 
}