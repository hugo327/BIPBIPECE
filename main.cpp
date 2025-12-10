#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define PIN_POTENTIOMETRE 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);




void setup(){



  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3c)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.println("Hello ECE !");
  display.display();
}
void loop(){
  int VarPotentiometre = analogRead(PIN_POTENTIOMETRE) * 100 /1023;
    display.clearDisplay();
    display.setCursor(0,10);
    display.println(VarPotentiometre);
    display.display();
    delay(20);
}