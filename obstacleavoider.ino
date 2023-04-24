int trigPin = 5;      // trig pin of HC-SR04
int echoPin = 4;     // Echo pin of HC-SR04

int LMP1 = 8;       //REVerse motion of Left motor
int LMN2 = 9;       //ForWarD motion of Left motor
int RMP3 = 10;      //REVerse motion of Right motor
int RMN4 = 11;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(LMP1, OUTPUT);      // set Motor pins as output
  pinMode(LMN2, OUTPUT);
  pinMode(RMP3, OUTPUT);
  pinMode(RMN4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 19)            
  {
    digitalWrite(RMN4, HIGH);                    // move forward
    digitalWrite(RMP3, LOW);
    digitalWrite(LMN2, HIGH);                                
    digitalWrite(LMP1, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(RMN4, LOW);  //Stop                
    digitalWrite(RMP3, LOW);
    digitalWrite(LMN2, LOW);                                
    digitalWrite(LMP1, LOW);
    delay(500);
    digitalWrite(RMN4, LOW);      //movebackword         
    digitalWrite(RMP3, HIGH);
    digitalWrite(LMN2, LOW);                                
    digitalWrite(LMP1, HIGH);
    delay(500);
    digitalWrite(RMN4, LOW);  //Stop                
    digitalWrite(RMP3, LOW);
    digitalWrite(LMN2, LOW);                                
    digitalWrite(LMP1, LOW);  
    delay(100);  
    digitalWrite(RMN4, HIGH);       
    digitalWrite(RMP3, LOW);   
    digitalWrite(LMN2, LOW);                                 
    digitalWrite(LMP1, LOW);  
    delay(500);
  }

}
