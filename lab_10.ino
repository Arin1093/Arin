#define MOTOR_PIN1 7
#define MOTOR_PIN2 8
#define MOTOR_PWM 6
int interruptChannelApin = 2;
int interruptChannelBpin = 3;
int dir ;
int toggle = 1;
volatile int Acount ;


void setup(){
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(interruptChannelApin, INPUT_PULLUP);
  pinMode(interruptChannelBpin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(interruptChannelApin),
                  ChannelA_callback, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptChannelBpin),
                  ChannelB_callback, RISING);
  Serial.begin(9600);
}

void loop(){
  
  moveback(255);
  
  Serial.print("Position: ");
  Serial.print(Acount);
  Serial.print(", Direction: ");
  Serial.println(dir);
  delay(100);
  
}

void movefor(int x){
  digitalWrite(MOTOR_PIN1,HIGH);
  digitalWrite(MOTOR_PIN2,LOW);
  analogWrite(MOTOR_PWM,x);
}
void moveback(int x){
  digitalWrite(MOTOR_PIN1,LOW);
  digitalWrite(MOTOR_PIN2,HIGH);
  analogWrite(MOTOR_PWM,x);
}
void stop(){
  digitalWrite(MOTOR_PIN1,LOW);
  digitalWrite(MOTOR_PIN2,LOW);
}
void ChannelA_callback(){
  
  if(digitalRead(interruptChannelBpin)==0){
    dir = 0;
    Acount++;
  }
  
}
void ChannelB_callback(){ 
  if(digitalRead(interruptChannelApin)==0){
    dir = 1;
    Acount--;
  }
}
