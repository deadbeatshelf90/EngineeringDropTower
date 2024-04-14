#include <Servo.h>
#define LIMIT_SWITCH_TOP_PIN 2
#define LIMIT_SWITCH_BOTTOM_PIN 3
#define motor_1_Pin 8
#define motor_2_Pin 10
#define buttonPin 7
Servo servoMotor;  // create servo object to control a servo
void setup() {
  servoMotor.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(LIMIT_SWITCH_TOP_PIN,INPUT);  
  pinMode(LIMIT_SWITCH_BOTTOM_PIN,INPUT);
  pinMode(motor_1_Pin,OUTPUT);
  pinMode(motor_2_Pin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int switchStateBottom = digitalRead(LIMIT_SWITCH_BOTTOM_PIN);
  int switchStateTop = digitalRead(LIMIT_SWITCH_TOP_PIN);
  if (buttonState == HIGH) {
    if(switchStateBottom == HIGH) {
      rise();
    }
  }
  if (switchStateTop == HIGH) {
    fall();
    }
}
void fall(){
  // Turn servo 1 degrees
  servoMotor.write(2);
  // Turn off the motors
  analogWrite(motor_1_Pin, 0);
  analogWrite(motor_2_Pin, 0);
  delay(1000); // Wait for servo to reach its position
  servoMotor.write(0);
  
}
void rise(){
  // Turn on the motors
  // Write a value (0-255) to the pin for analog output
  analogWrite(motor_1_Pin, 122); // 122/255 * 5V = approx. 2.99V
  analogWrite(motor_2_Pin, 122);
}
