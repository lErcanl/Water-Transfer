boolean state = false;
boolean state2 = false;
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define trigPin 10
#define echoPin 11

float deger;
float deger2;
int sound = 250;
void setup() {

  Serial.begin (9600);
  pinMode(13, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);


  Serial.begin(9600);
  lcd.begin(16, 4);

}

void loop() {

  float duration, distance, distance2;
  deger = analogRead(A0);
  deger2 = map(deger, 0, 1023, 0, 100);
  float deger3 = deger2/10.0;

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 28.5;
  Serial.print(distance);     // Mesafe degerini ekrana yazdırıyoruz
  Serial.println(" cm");
  distance2 = (33.3 - distance) / 3.;

  lcd.setCursor(0, 0);
  lcd.print("   SIVI SEViYESi");
  lcd.setCursor(0, 1);
  lcd.print("    ");

  lcd.print(distance2, 1);
  lcd.print(" Litre");
  delay(100);

  lcd.setCursor(4, 2);
  lcd.print("Girilen deger :");

  lcd.setCursor(4, 3);
  lcd.print(deger3, 1);
  lcd.print(" Litre");,

  if (!digitalRead(12)) {
    delay(200);
    state = !state;
  }
  if (state  && distance2 < deger3 ) {


    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  if (!digitalRead(13)) {
    delay(200);
    state2 = !state2;
  }
  if (state2 && distance2 > deger3) {
    digitalWrite(2, HIGH);
}
  else {
    digitalWrite(2, LOW);
  }

}
