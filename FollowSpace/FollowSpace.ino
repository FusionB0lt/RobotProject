const int IN1 = 9;
const int IN2 = 10;
const int IN3 = 5;
const int IN4 = 3;
int trigPin = 12;    // connect TRIG pin to Arduino pin 12
int echoPin = 11;    // connect ECHO pin to Arduino pin 11

float distance_cm;
float distances[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

float pulseDistance(){
  float duration_us, distance_cm;
  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;// Speed of sound wave, 0.034m/us divided by 2
  return(distance_cm);
}

void loop() {
  distance_cm = pulseDistance();
  
  digitalWrite(IN4, HIGH);
  digitalWrite(IN1, HIGH);

  if (distance_cm = 50) {
    //stops foward motion
    digitalWrite(IN4, LOW);
    digitalWrite(IN1, LOW);

    //turns
    digitalWrite(IN4, HIGH);
    for (int i = 1; i < 5; i++) {
      distance_cm = pulseDistance();
      distances[i] = distance_cm;
      delay(100);
    }

    //after testing, if the distance of the object is different from when it starts turning to where the test is, it changes direction
    if(distances[1] > distances[4]) {
      digitalWrite(IN4, LOW);
      digitalWrite(IN1, HIGH);
    }
    
    while (distance_cm < 100){ //here so it keeps turning
      distance_cm = pulseDistance();
      
    }
    digitalWrite(IN4, LOW); //stops
    digitalWrite(IN1, LOW);
  }

  
  //digitalWrite(IN1, LOW);
  //digitalWrite(IN4, LOW);
  //digitalWrite(IN2, HIGH);
  //delay(1555);
  //digitalWrite(IN2, LOW);
  //delay(3000);
  //digitalWrite(IN4, HIGH);
  //digitalWrite(IN1, HIGH);
  //delay(6000);
  //digitalWrite(IN3, LOW);
  //digitalWrite(IN4, HIGH);
  //delay(6000);
}
