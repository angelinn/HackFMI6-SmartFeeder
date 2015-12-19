#include <Servo.h>

//static const uint8_t D0   = 16;
//static const uint8_t D1   = 5;
//static const uint8_t D2   = 4;
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1;

short int motor_op = 16;
short int distance_senstor_ip = 5;
short int speaker_op = 4;
// twelve servo objects can be created on most boards

Servo myservo;  // create servo object to control a servo
int pos = 0;  
void setup() 
{
  Serial.begin(9600);
  myservo.attach(motor_op);
    // attaches the servo on pin 9 to the servo object
  pinMode(distance_senstor_ip, INPUT);
  pinMode(speaker_op, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() 
{
  // distnace motor tests
  Serial.print((int)is_bowl_full());
  Serial.print("\n");
  
  // motort tests 1 oborot

  //run_motor();
  
  delay(1);

  
}

void run_motor()
{
  //for (pos = 0; pos <= 180; pos += 1) 
  //{ // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  //for (pos = 0; pos <= 90; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(750);                       // waits 15ms for the servo to reach the position
  }  
  myservo.write(93.5);
  delay(2000);
}

void hello_kitty()
{
  // sing a sing a song
}

bool is_bowl_full()
{
  int kupichka = 0;
  kupichka = analogRead(distance_senstor_ip);
  Serial.print(kupichka);
  Serial.print("  ");
  if(kupichka > 500)
  {
    return false; 
  }
  return true;
}
