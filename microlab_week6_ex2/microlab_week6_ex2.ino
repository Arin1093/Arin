#include <ThreeWire.h>
#include <RtcDS1302.h>
#define ledPin 8  
ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire); 

void printDateTime(const RtcDateTime& dt){ 
 
 Serial.print(dt.Minute(), DEC); 
 Serial.print(':'); 
 Serial.print(dt.Second(), DEC); 
 Serial.println(); 
 
}

void setup() { 
 pinMode(ledPin, OUTPUT); 
 Serial.begin(9600); 
 Rtc.Begin(); 
 RtcDateTime setting_time(0,0,0,0,0,0); 
 // year, month, dayOfMonth, hour, minute, second 
 printDateTime(setting_time); 
 //Try to comment This line 
 Rtc.SetDateTime(setting_time); 
 Serial.println("START");

} 

void loop() { 
  RtcDateTime now = Rtc.GetDateTime(); 
  int sec = now.Second();
  int i = sec;

  //Serial.println(sec);
  if(i < 6){
    Serial.println(sec);
    digitalWrite(ledPin, HIGH);
  } 
  if(i%2==0){
     digitalWrite(ledPin, LOW);
  }
  i++ ;
  if(i == 6){
    Serial.println("STOP");
  }
  if(i >= 6){
    digitalWrite(ledPin, LOW);
  }
  //printDateTime(now);
  delay(1000); 
}
