#include <SPI.h>

#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9

int num ;

int digi1 ;
int digi2 ;

int map7seg[10] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111,
};


void spi_write_1(unsigned char cData){
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST,cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);
}  

void spi_write_2(unsigned char cData){
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST,cData);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);
}  

void show_num(int x)
{
  digi1 = num/10;
  digi2 = num%10;
  spi_write_1(map7seg[digi1]);
  spi_write_2(map7seg[digi2]);
}

void setup()
{
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  for(num = 0;num<=99;num++){
     show_num(num);
     delay(200);
  }
}
