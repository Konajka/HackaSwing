#include <Arduino.h>
#include <Servo.h>

#define SERVO_PWM_PIN 9
#define SERVO_MIN_PULSE 500
#define SERVO_MAX_PULSE 2400

#define ANGLE_MID 90
#define ANGLE_RANGE_MAX 90
#define INTERVAL_INIT_VALUE 2500

Servo servo;

// Maximum swing angle from middle point in degrees
// Range 0 - 90
// 0 - stop in middle point
// 90 - swing 90 degrees on both sides, actually from 0 to 180
int angleRange = ANGLE_RANGE_MAX;

// Frequency control, delay between one degree step in microseconds
unsigned int interval = 2000;

void setup() {
	Serial.begin(115200);

	Serial.println("Initialize servo to middle position");
	servo.attach(SERVO_PWM_PIN, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
	servo.write(ANGLE_MID);
	delay(500);
}

void loop() {

	for (int angle = ANGLE_MID - angleRange; angle < (ANGLE_MID + angleRange); angle++) {
		servo.write(angle);
		delayMicroseconds(interval);
	}

	for (int angle = ANGLE_MID + angleRange; angle > (ANGLE_MID - angleRange); angle--) {
		servo.write(angle);
		delayMicroseconds(interval);
	}
}
