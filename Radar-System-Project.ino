int redPin = 3;
int greenPin = 5;
int bluePin = 4;
int trigPin = A1;
int echoPin = 6;
int lightPin = A0;
int baudRate = 115200;
int lightValue;
int delayTime = 2000;
int value;
float timeTaken;
float distance;
void setup() {
  pinMode(lightPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(baudRate);
 
}


  

void loop() {
  // put your main code here, to run repeatedly:
  lightValue = analogRead(lightPin);
  Serial.println("The light value is "+String(lightValue));
  delay(delayTime);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  timeTaken = pulseIn(echoPin,HIGH);
  distance = timeTaken *(0.000001)*(330)*(100);
  if(lightValue <= 100){
    Serial.println("The object is "+String(distance)+ " cm far ");
    delay(delayTime);
    }
  else{    
    Serial.println("The object is "+String(distance)+ " cm far ");


  }



  
   if (distance >= 30 && distance < 40){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
  }
  else if(distance >= 20 && distance < 30){
      digitalWrite(redPin,HIGH);
      digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,LOW);



  }
  else if (distance < 20){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);

  }
  else{
     digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);

  }


}
