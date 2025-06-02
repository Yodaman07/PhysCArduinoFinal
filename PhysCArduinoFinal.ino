#include <Stepper.h> //https://docs.arduino.cc/libraries/stepper/
#include <Servo.h> //https://docs.arduino.cc/libraries/servo/
//Author: Ayaan Irshad
Servo servo;
Stepper stepperMotor(2048, 7, 5, 6, 4); // PINs 1, 3, 2, 4 IN THAT ORDER
int servoPos = 0; //Sevro pos to hold

void setup() {
  Serial.begin(9600);

  //Servo
  servo.attach(3);

  //Joystick
  pinMode(A0, INPUT); // y axis
  pinMode(A1, INPUT); //x axis

  // Stepper Motor
  stepperMotor.setSpeed(10);
}

void loop() {

  int joyX = analogRead(A1);
  int joyY = analogRead(A0);
  
  Serial.println(joyX);
  if (joyX < 307){ //327 is joyX at medium //JOYUP
    stepperMotor.step(5); 
  }else if (joyX > 357){ //JOYDOWN
    stepperMotor.step(-5);
  }


  if (joyY < 305){//JOYRIGHT //325 is middle 
    servoPos +=1; 
  }else if (joyY > 345){ //JOYLEFT
    servoPos -=1; 
  }

  if (servoPos>180){servoPos = 180;} //prevents the servo pos from going negative or past 180
  if (servoPos<0){servoPos = 0;}

  servo.write(servoPos);
}
