#include <Stepper.h>
#include <Servo.h>

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
  if (joyX-20 < 307){ //327 is joyX at medium //JOYUP
    stepperMotor.step(5); 
  }else if (joyX+20 > 357){ //JOYDOWN
    stepperMotor.step(-5);
  }


  if (joyY-20 < 305){//JOYRIGHT //325 is middle 
    // Serial.println("HI");
    // servo.write(map(joyY, 0, 325, 0, 180));
    servoPos +=1; 
  }else if (joyY+20 > 345){ //JOYLEFT
    servoPos -=1; 
  }

  if (servoPos>180){servoPos = 180;}
  if (servoPos<0){servoPos = 0;}

  // Serial.println(servoPos);
  servo.write(servoPos);

}
