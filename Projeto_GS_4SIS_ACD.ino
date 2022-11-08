#include <LiquidCrystal.h>
#define trigPin1 6
#define trigPin2 7
#define trigPin3 8
#define echoPin1 6
#define echoPin2 7
#define echoPin3 8
#define led1 9
#define led2 10
#define led3 13
#define led4 A0
#define led5 A1
#define led6 A2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int ledsVermelhos = 0;
int ledsVerdes = 0;
  
  long readUltrasonicDistance(int triggerPin, int echoPin){
    pinMode(triggerPin, OUTPUT);  
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
  }

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  lcd.begin(16,2);
  
}
void loop() {
  float distance1;
  float distance2;
  float distance3;
  ledsVermelhos = 0;
  ledsVerdes = 0;
  lcd.setCursor(0,0);
  
   distance1 = (readUltrasonicDistance(6, 6) * 0.034)/2;
   Serial.println(distance1);
   if (distance1 <= 200){
    digitalWrite(led1, HIGH);
  digitalWrite(led4, LOW);
     ledsVermelhos += 1;
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led4, HIGH);
  ledsVerdes += 1;
  }
    distance2 = (readUltrasonicDistance(7, 7) * 0.034)/2;
   if (distance2 <= 200){
    digitalWrite(led2, HIGH);
    digitalWrite(led5, LOW);
  ledsVermelhos += 1;

  }
  else {
    digitalWrite(led2, LOW);
  digitalWrite(led5, HIGH);
  ledsVerdes += 1;
  }
    distance3 = (readUltrasonicDistance(8, 8) * 0.034)/2;
   if (distance3 <= 200){
    digitalWrite(led3, HIGH);
     digitalWrite(led6, LOW);
     ledsVermelhos += 1;

  }
  else {
    digitalWrite(led3, LOW);
    digitalWrite(led6, HIGH);
    ledsVerdes += 1;

  }
  lcd.clear();
  
   lcd.setCursor(0, 0);
   lcd.print("VAGAS LIVRES   ");
   lcd.print(ledsVerdes);
   lcd.setCursor(0,1);
   lcd.print("VAGAS OCUPADAS ");
  lcd.print(ledsVermelhos);
  
  delay(500);

lcd.clear();

}
