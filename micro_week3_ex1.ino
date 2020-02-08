int clk_pin=13;//SHCP
int latch_pin=10;//STCP
int data_pin=11;//DS

void setLed(uint8_t _state){
digitalWrite(latch_pin,LOW);
 for(int i=0;i<8;i++){
digitalWrite(data_pin,(_state>>(7-i))&0x01);
digitalWrite(clk_pin,HIGH);
digitalWrite(clk_pin,LOW);
}
digitalWrite(latch_pin,HIGH);
}
int map7seg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111,};

void setup()
{
//putyoursetupcodehere,torunonce:
pinMode(clk_pin,OUTPUT);
pinMode(latch_pin,OUTPUT);
pinMode(data_pin,OUTPUT);

setLed(0x3F);
}
void loop(){
setLed(map7seg[0]);
delay(1000);
setLed(map7seg[1]);
delay(1000);
setLed(map7seg[2]);
delay(1000);
setLed(map7seg[3]);
delay(1000);
 setLed(map7seg[4]);
delay(1000);
setLed(map7seg[5]);
delay(1000);
setLed(map7seg[6]);
delay(1000);
setLed(map7seg[7]);
delay(1000);
setLed(map7seg[8]);
delay(1000);
setLed(map7seg[9]);
delay(1000);
}
