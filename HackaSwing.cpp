#include <Arduino.h>
#include <Servo.h>

#define SERVO_PWM_PIN 9
#define SERVO_MIN_PULSE 500
#define SERVO_MAX_PULSE 2400

Servo servo;

void setup() {
	Serial.begin(115200);

	Serial.println("Initialize servo to middle position");
	servo.attach(SERVO_PWM_PIN, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
	servo.write(90);
	delay(500);
	servo.detach();
}

void loop() {

}
