#include <SPI.h>

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>



boolean buttonstate ;



#define SCREEN_WIDTH 128 // OLED display width, in pixels

#define SCREEN_HEIGHT 64 // OLED display height, in pixels



#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



int but1 = 7 ;

int but2 = 8 ;



void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c

  display.clearDisplay(); // clears the screen and buffer

  display.drawPixel(127, 63, WHITE);



  pinMode(but1,INPUT);

  digitalRead(but1);

  pinMode(but2,INPUT);

  digitalRead(but2);

  Serial.begin(9600);

}



void loop() {

  

  display.drawCircle(55,21,10, WHITE);

  display.drawCircle(55,45,10, WHITE);

  display.setTextSize(2);

  display.setTextColor(WHITE);

  display.setCursor(2,13);

  display.println("SW1");

  display.setCursor(2,38);

  display.println("SW2");

  display.display();

  

  if(digitalRead(but1) == 0 ){

    display.fillCircle(55,21,10, WHITE);

  }

  else if (digitalRead(but2) == 0 ){

    display.fillCircle(55,45,10, WHITE);

  }

  else{

    display.clearDisplay();

  }

}
