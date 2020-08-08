#include <Arduino.h>

//initializing constants for for the ultrasonic sensor pins

#define trigPin 3 // pin for emitter
#define echoPin 2  // pin for reciever
  
  //class for setting up motors on an L298 H-Bridge motor driver
class Motor{
  
public:
  int pin1,pin2;
 

  Motor(int p1,int p2){

    /*t
    his constructor takes the motor pins as arguments and initializes them as outputs
    make sure that p1 and p2 are control pins of the same motor
     */

    this->pin1 = p1;
    this->pin2 = p2;
    pinMode(this->pin1, OUTPUT);
    pinMode(this->pin2, OUTPUT);
  }

  Motor(){}

  //the following functions represent the possible movements of the motor

  void stop(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
  }

  void forward(){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
  }

  void backward(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
  }

  
};

//declaring motor objects in global scope

Motor frontLeftMotor,frontRightMotor,backLeftMotor,backRightMotor;


void setup() {
  
//setting up motor pins, please change the pin values accordingly
  frontLeftMotor = Motor(5,6);
  frontRightMotor = Motor(7,8);
  backLeftMotor = Motor(9,10);
  backRightMotor = Motor(11,12);
  


  Serial.begin(9600); // serial for debugging

  // ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);





}

double ultrasonicDistanceRead(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  double duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  double distance= duration*0.034/2;
  return distance;
}


//functions for basic car movements

void moveForward(){

}

void movebackward(){

}


void stopMoving(){

}

void moveLeft(){

}

void moveRight(){

}

void steerLeft(){

}

void steerRight(){

}


//the following function is executed when the car detects an obstacle

void avoidObstacle(double dist,double min){
 
}
  


//the main loop function executed by the arduino
void loop() {
 
  double distance = ultrasonicDistanceRead();
  Serial.print("Distance: ");
  Serial.println(distance);
}

