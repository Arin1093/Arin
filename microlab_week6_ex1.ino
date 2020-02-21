#include <ThreeWire.h>  
#include <RtcDS1302.h>
#define ledPin 8
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
void printDateTime(const RtcDateTime& dt)
{
  Serial.print(dt.Year(), DEC);
  Serial.print('/');
  Serial.print(dt.Month(), DEC);
  Serial.print('/');
  Serial.print(dt.Day(), DEC);
  Serial.print(' ');
  Serial.print(dt.Hour(), DEC);
  Serial.print(':');
  Serial.print(dt.Minute(), DEC);
  Serial.print(':');
  Serial.print(dt.Second(), DEC);
  Serial.println();
  Serial.print("Total Seconds since 1/1/2000 : ");
  Serial.print(dt.TotalSeconds());
  Serial.println();
  
}
void setup() 
{

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,20,16,0,10);// year, month, dayOfMonth, hour, minute, second
  printDateTime(setting_time);
  //Rtc.SetDateTime(setting_time);//Try to comment This line
}
void loop() 
{
  int timeDiff, lastRead = 0;
  RtcDateTime now = Rtc.GetDateTime();
  Serial.println("START");
  printDateTime(now);

  if(now.TotalSeconds()%2){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
  Serial.print("STOP\n");
}
