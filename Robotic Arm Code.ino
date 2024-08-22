#include  <Servo.h>
// Create servo objects 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;// Create names to the analog input pins 
Servo servo5;
Servo servo6;
Servo servo7;

int pin0 = A0;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;// Setup of angle variables we have to use further down in the program 
int pin4 = A4;
int pin5 = A5;

const int g1 = 1;
const int g2 = 3;
int pos = 0;

int angle1;
int angle2;
int angle3;
int angle4;// Setup of value variables we have to use further down in the program 
int angle5;
int angle6;
int angle7;

int value1;
int value2;
int value3;
int value4;// Setup of limit values 
int value5;
int value6;
int value7;

long int forservo1 = 20000;
long int forservo2 = 20000;
long int forservo3 = 20000;
long int forservo4 = 20000;
long int forservo5 = 20000;
long int forservo6 = 20000;
long int forservo7 = 20000;

void setup() 
{ 
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);
  servo7.attach(11);

  pinMode (g1, INPUT_PULLUP);
  pinMode (g2, INPUT_PULLUP);

} 
 
void loop() 
{ 
  // read analog values from joysticks 
  value1 = analogRead(pin0);
  value2 = analogRead(pin1);
  value3 = analogRead(pin2);
  value4 = analogRead(pin3);
  value5 = analogRead(pin4);
  value6 = analogRead(pin5);

  
  // 10 bit value is too big, so we change the scale from 0 - 1023 proportionately to 1 - 29 
  value1 = map(value1, 0, 1023, 1, 29);
  value2 = map(value2, 0, 1023, 1, 29);
  value3 = map(value3, 0, 1023, 1, 29);
  value4 = map(value4, 0, 1023, 1, 29);
  value5 = map(value5, 0, 1023, 1, 29);
  value6 = map(value6, 0, 1023, 1, 29);
  
  // it needs correction of positions, because joysticks are not very precise to stay exactly in the center  
  if(value1  <= 17 && value1 >= 13) // if value1 if between 13-17, then it's equal to 15 */
      value1 = 15;
  if(value2  <= 17 && value2 >= 13)
      value2 = 15;
  if(value3  <= 17 && value3 >= 13)
      value3 = 15;
  if(value4  <= 17 && value4 >= 13)
      value4 = 15;
  if(value5  <= 17 && value5 >= 13)
      value5 = 15;
  if(value6  <= 17 && value6 >= 13)
      value6 = 15;
    
  // Change initial value 'forservo' which is used to turn servo slower. This value has got very big scale.
  // We add or substract (depends on turning direction) difference between analog value and center from 'forservo'  
  forservo1 = forservo1 - (value1 - 15);
  forservo2 = forservo2 - (value2 - 15);
  forservo3 = forservo3 + (value3 - 15);
  forservo4 = forservo4 + (value4 - 15);
  forservo5 = forservo5 + (value5 - 15);
  forservo6 = forservo6 + (value6 - 15);
  
  // this part do not let variables 'forservo' go out of the limits 
  if(forservo1  < 1) // if forservo1 is less than 1, then it's equal to 1 
      forservo1 = 1;
  if(forservo1  > 20000) // if forservo1 is greater than 20000, then it's equal to 20000 
      forservo1 = 20000;
  if(forservo2  < 1) 
      forservo2 = 1;
  if(forservo2  > 20000)
      forservo2 = 20000;
  if(forservo3  < 1) 
      forservo3 = 1;
  if(forservo3  > 20000)
      forservo3 = 20000;
  if(forservo4  < 1)
      forservo4 = 1;
  if(forservo4  > 20000)
      forservo4 = 20000;
  if(forservo5  < 1) 
      forservo5 = 1;
  if(forservo5  > 20000)
      forservo5 = 20000;
  if(forservo6  < 1)
      forservo6 = 1;
  if(forservo6  > 20000)
      forservo6 = 20000;
  
  // change used value to angle of servo. Angles are adjusted during testing 
  angle1 = map(forservo1, 1, 20000, 10, 180);
  angle2 = map(forservo2, 1, 20000, 10, 180);
  angle3 = map(forservo3, 1, 20000, 10, 180);
  angle4 = map(forservo4, 1, 20000, 10, 180);
  angle5 = map(forservo5, 1, 20000, 10, 180);
  angle6 = map(forservo6, 1, 20000, 10, 180);
  
  // send angles to servos 
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);  // activates the magnet
  servo5.write(angle5);
  servo6.write(angle6);

  grip();
  }

void grip(){
if (digitalRead(g1) == LOW) { //if Value read of the button ==LOW:
    pos++;  //increases the value of the "pos" variable each time the push button of the left is pressed
    delay(5); //5 milliseconds of delay
    servo7.write(pos); //servo goes to variable pos
  }
  if (digitalRead(g2) == LOW) { //if Value read of the button ==LOW:
    pos--;  //decreases the value of the "pos" variable each time the push button of the right is pressed
    delay(5); //5 milliseconds of delay
    servo7.write(pos); //servo goes to variable pos
  }
}

