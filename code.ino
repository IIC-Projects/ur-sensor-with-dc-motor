ur sensor with dc motor        
BY DEBANKAR SHUBHRAM

#define trigPin 11   //defining digital pin
#define echoPin 10    //defining digital pin
int motor1 = 5;       //defining digital pin
int motor2 = 6;       //defining digital pin
void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);      
  pinMode(echoPin, INPUT);
  pinMode(motor1,OUTPUT);         //about the input and output of the system
  pinMode(motor2,OUTPUT);
}
void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        //starting the the pin by first making it low
  delayMicroseconds(3);              
  digitalWrite(trigPin, HIGH);        
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  distance = (duration/2) / 29.1;     //formula
  if (distance >= 15 || distance <= 0)        //making the dc motor run clockwise depending on the condition statement
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");           //making the dc motor run anticlockwise depending on the condition statement
    digitalWrite(motor1,LOW); 
    digitalWrite(motor2,HIGH);
    delay(500);               
  }
  delay(500);
}
