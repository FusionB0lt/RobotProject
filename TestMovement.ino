const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 5;
const int IN4 = 3;
//const int IN5 = 11;

//int rightmotorPin = 11, 10
//left motor  5, 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IN4, HIGH);
  digitalWrite(IN1, HIGH);
  delay(12000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2, HIGH);
  delay(1555);
  digitalWrite(IN2, LOW);
  delay(3000);
  //digitalWrite(IN4, HIGH);
  //digitalWrite(IN1, HIGH);
  //delay(6000);
  //digitalWrite(IN3, LOW);
  //digitalWrite(IN4, HIGH);
  //delay(6000);
}
