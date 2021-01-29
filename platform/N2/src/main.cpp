#include <Arduino.h>
#include <Master0.c>

// MASTER

#define CONTROL 2

#define Bu1 4
#define Bu2 5
#define Bu3 6
#define Bu4 7

#define S1 8
#define S2 9

#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13

#define DEBUG 3

void push(void);
void swithDevice(void);


void setup() {
  Serial.begin (9600);

  pinMode(CONTROL,OUTPUT);
  Master0_initialize();

  pinMode(Bu1, INPUT);
  pinMode(Bu2, INPUT);
  pinMode(Bu3, INPUT);
  pinMode(Bu4, INPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  
  pinMode(DEBUG, OUTPUT);

}

int start = -1;
int led1 = LOW;
int led2 = LOW;
int led3 = LOW;
int led4 = LOW;
int s1 = LOW;
int s2 = LOW;
int slaves[2] = {8, 9};
int status;

void loop() {
  int cm = millis();
  if(start != -1 && cm - start < 70) return;
  start = cm;
  //check buttons
  swithDevice();
  push();
  //set inputs
  //change state
  Master0_step();
  //check outputs
   if(rtY.bus_mode == 0){      //read mode
  //  delay(20);
    digitalWrite(CONTROL,LOW);
    while(!Serial.available()){}
      status = Serial.read();
  }else if(rtY.bus_mode == HIGH){                        //write mode
    digitalWrite(CONTROL,HIGH);
    Serial.write(rtY.bus_data);     
  }
  if(s1 || s2){
    digitalWrite(DEBUG, HIGH);
  }else if(!s1 && !s2){
    digitalWrite(DEBUG, LOW);
  }
}


void push(){
  if(s1 || s2){
    if(digitalRead(Bu1)) rtU.input = 2;
    else if(digitalRead(Bu2)) rtU.input = 3;
    else if(digitalRead(Bu3)) rtU.input = 4;
    else if(digitalRead(Bu4)) rtU.input = 5;
    else
    {
      rtU.input=6;
    }
    
   return; 
  }
  if(digitalRead(Bu1)){
    led1 = led1==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu2)){
    led2 = led2==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu3)){
    led3 = led3==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu4)){
    led4 = led4==LOW ? HIGH:LOW;
  }
  digitalWrite(LED1, led1);
  digitalWrite(LED2, led2);
  digitalWrite(LED3, led3);
  digitalWrite(LED4, led4);
}

void swithDevice(){
  rtU.device_select = 0;
  if(digitalRead(S1)) {
    s1 = s1 == LOW ? HIGH:LOW;
    rtU.device_select = 1;
    if(s1) {
      s2=LOW;
      rtDW.address = slaves[0];
    }
  }
  else if(digitalRead(S2)){
    s2 = s2 == LOW ? HIGH:LOW;
    rtU.device_select = 2;
    if(s2) {
      s1=LOW;
      rtDW.address = slaves[1];
    }
  }
}