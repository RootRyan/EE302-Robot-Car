
//Motor pins
//Motor pins. 1 is right motor, 2 is left motor
const int motor1a = 8;
const int motor1b = 9;

const int motor2a = 10;
const int motor2b = 11;

//Sensor pins
const int photoLeft = A0;
const int photoRight = A1;
const int photoCenter = A2;
const int irLeft = A3;
const int irRight = A4;
const int irFront= A5;

//State



//Motor states

int m1aState= LOW;
int m1bState = LOW;

int m2aState= LOW;
int m2bState= LOW;



//input values

const int photoThres= 2.5;


const int irClose= 1.5; //1.5 V threshold

//Initialization function
//void setup() {
  //Put each pin in the correct mode.
  //Motors are in OUTPUT mode

//Initialization function
void setup() {
  //Put each pin in the correct mode. 
  //Motor control pins are output

  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

int main() {
  delay(1000);
  forward();
  delay(500);
  turnCounterClockwise();
  delay(500);
  halt();
}
//Infinite loop called automatically by the Arduino board
void loop(){

  //Digital write writes a value, HIGH or LOW to the output port
  //test sequence
  forward();
  delay (1000);
  backward();
  delay(1000);
  turnCounterClockwise();
  delay(1000);
  turnClockwise();
  delay(1000);
  correctToRight();
  correctToLeft();
  
  
  //line following- in progress
  /*
   if (analogRead(photoCenter== photocRed)
     halt();
     delay(500);
   else */
   
   if (analogRead(irFront) >= irClose) {
     halt();
     delay(500);
   }else{
      if((analogRead(photoRight) > photoThres)&& (analogRead(photoLeft) > photoThres)){
        forward();
        delay(500);
      
      }
    
    if((analogRead(photoLeft)< photoThres)&&(analogRead(photoRight)< photoThres)){
      backward();
      delay(500);
      halt();
     
    }
     if((analogRead(photoLeft)> photoThres)&&(analogRead(photoRight)<photoThres)){
       correctToRight();
       delay(500);
       halt();
   
    }
    
    if ((analogRead(photoRight) > photoThres)&& (analogRead(photoLeft) < photoThres)){
     correctToLeft();
     delay(500);
     halt();
    }
    if (analogRead(irRight)>= irClose){
      correctToRight();
      delay(500);
      halt();
    }
    if (analogRead(irLeft)>=irClose){
      correctToLeft();
      delay(500);
      halt();
    }    
    
  
  }
}

void correctToRight(){
   turnClockwise();
   delay(500);
   forward();
   delay(500);
   turnCounterClockwise();
   delay(500);
   halt(); 
}

void correctToLeft(){
   turnCounterClockwise();
   delay(500);
   forward();
   delay(500);
   turnClockwise();
   delay(500);
   halt();
}

void turnCounterClockwise()
{
  //left motor backwards, right motor forward

  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;

  digitalWrite(motor2a, LOW);
  m2aState= LOW;
  digitalWrite(motor2b, HIGH);
  m2bState= LOW;
}

void turnClockwise(){
  //left motor forward, right motor backwards

  digitalWrite(motor1a, LOW);
  m1aState= HIGH;
  digitalWrite(motor1b, HIGH);
  m1bState= LOW;

  digitalWrite(motor2a, HIGH);
  m2aState= LOW;
  digitalWrite(motor2b, LOW);
  m2bState= HIGH;
}

void halt(){
  //stops motors by turning enables for both motors off
  digitalWrite(motor1a, LOW);
  m1aState= LOW;
  digitalWrite(motor1b, HIGH);
  m1bState= LOW;

  digitalWrite(motor2a, HIGH);
  m2aState= LOW;
  digitalWrite(motor2b, LOW);
  m2bState= LOW;
}

void forward() {
  //both motors forward

  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;

  digitalWrite(motor2a, HIGH);
  m2aState= HIGH;
  digitalWrite(motor2b, LOW);
  m2bState= LOW;
}

void backward() {
  //both motors back

  digitalWrite(motor1a, LOW);
  m1aState= LOW;
  digitalWrite(motor1b, HIGH);
  m1bState= HIGH;

  digitalWrite(motor2a, LOW);
  m2aState= LOW;
  digitalWrite(motor2b, HIGH);
  m2bState= HIGH;

}

void resume(){
  //restores states

 digitalWrite(motor1a, m1aState);
 digitalWrite(motor1b, m1bState);

 digitalWrite(motor2a, m2aState);
 digitalWrite(motor2b, m2bState);
}

  
