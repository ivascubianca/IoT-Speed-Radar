#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ir_s1 = 2;
int ir_s2 = 3;

int ledGreen = 8;
int ledRed = 9;

float timer1;
float timer2;
float Time;

int flag1 = 0;
int flag2 = 0;

const float ACTUAL_DISTANCE = 0.2;
const float SIMULATED_DISTANCE = 5.0;

float speed = 0;

void setup() {

  Serial.begin(9600);

  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10,10);
  display.println("Speed");
  display.setCursor(10,35);
  display.println("Radar");
  display.display();

  delay(2000);
}

void loop() {

  if (flag1 == 0 && digitalRead(ir_s1) == LOW) {

    timer1 = millis();
    flag1 = 1;

    Serial.println("Senzor 1 detectat");

    delay(100);
  }

  if (flag1 == 1 && flag2 == 0 && digitalRead(ir_s2) == LOW) {

    timer2 = millis();
    flag2 = 1;

    Serial.println("Senzor 2 detectat");

    delay(100);
  }

  if (flag1 && flag2) {

    Time = (timer2 - timer1) / 1000.0;

    if (Time > 0) {

      speed = (ACTUAL_DISTANCE / Time);
      speed *= (SIMULATED_DISTANCE / ACTUAL_DISTANCE);
      speed *= 3.6;

      Serial.print("Speed = ");
      Serial.println(speed);
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0,0);
    display.print("Speed Radar");

    display.setTextSize(2);
    display.setCursor(0,18);
    display.print(speed,1);
    display.print(" km/h");

    display.setTextSize(1);
    display.setCursor(0,50);

    if(speed > 50){

      display.print("OVER SPEED");

      digitalWrite(ledRed,HIGH);
      digitalWrite(ledGreen,LOW);

    }
    else{

      display.print("NORMAL SPEED");

      digitalWrite(ledGreen,HIGH);
      digitalWrite(ledRed,LOW);

    }

    display.display();

    delay(3000);

    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,LOW);

    while(digitalRead(ir_s1)==LOW || digitalRead(ir_s2)==LOW);

    delay(300);

    speed = 0;
    flag1 = 0;
    flag2 = 0;
  }
}