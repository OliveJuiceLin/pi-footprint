#include <Servo.h>
int ardublockUltrasonicSensorCodeAutoGeneratedReturnCM(int trigPin, int echoPin)
{
  long duration;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration / 59;
  //if ((duration < 2) || (duration > 300)) return false;
  return duration;
}


void stop(int lSpeed,int rSpeed);
void forward(int lSpeed,int rSpeed);
void back(int lSpeed,int rSpeed);
void left(int lSpeed,int rSpeed);
void right(int lSpeed,int rSpeed);
int LEFT_GRAY_PIN = 16;
int RIGHT_GRAY_PIN = 17;
Servo myservo;
void setup()
{
  Serial.begin(9600);
  //myservo.attach(7);
  digitalWrite( 15 , LOW );
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(LEFT_GRAY_PIN,INPUT);
  pinMode(RIGHT_GRAY_PIN,INPUT);

}

void loop()
{
  int distance = ( 	ardublockUltrasonicSensorCodeAutoGeneratedReturnCM( 15 , 14 ) );
  int grayLeft = analogRead(LEFT_GRAY_PIN);
  int grayRight = analogRead(RIGHT_GRAY_PIN);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" Left Gray: ");
  Serial.print(grayLeft);
  Serial.print(" Right Gray: ");
  Serial.println(grayRight);
  if (( distance < ( 30 ) ))
  {
    stop(0,0);
    delay( 1000 );
    back(180,180);
    delay( 100 );
    Serial.println("back!!!");
    /*left();
    delay( 1000 );*/
  }
  else
  {
    if ((grayLeft > 200) && (grayRight > 200)){
      forward(150,110);
      Serial.println("forward");
      delay(100);
    }
    else if ((grayLeft > 200) && (grayRight < 200)){
      right(180,0);
      Serial.println("right");
      delay(100);
    }
    else if ((grayLeft < 200) && (grayRight > 200))
    {
      left(0,180);
      Serial.println("left");
      delay(100);
    }
    else if ((grayLeft < 200) && (grayRight < 200)) {
      stop(0,0);
      Serial.println("stop");
      spin();
      delay(3000);
    //  continue;
      forward(150,110);
      delay(1000);
    }
  }
}
void back(int lSpeed = 0,int rSpeed = 0)
{
  analogWrite(6,lSpeed);
  analogWrite(5,0);
  analogWrite(10,rSpeed);
  analogWrite(9,0);
}

void stop(int lSpeed = 0,int rSpeed = 0)
{  
  analogWrite(5,lSpeed);
  analogWrite(6,0);
  analogWrite(9,rSpeed);
  analogWrite(10,0);
}

void forward(int lSpeed = 0,int rSpeed = 0)
{
  analogWrite(5,lSpeed);
  analogWrite(6,0);
  analogWrite(9,rSpeed);
  analogWrite(10,0);
}
void left(int lSpeed = 0,int rSpeed = 0)
{
  analogWrite(5,lSpeed);
  analogWrite(6,0);
  analogWrite(9,rSpeed);
  analogWrite(10,0);
}
void right(int lSpeed = 0,int rSpeed = 0)
{
  analogWrite(5,lSpeed);
  analogWrite(6,0);
  analogWrite(9,rSpeed);
  analogWrite(10,0);
}
void spin() {
  for (int angle = 90; angle <= 150; angle ++) {
    myservo.write(angle);
    delay(15);
  }
  for (int angle = 150; angle >= 90; angle --) {
    myservo.write(angle);
    delay(15);
  }
}

