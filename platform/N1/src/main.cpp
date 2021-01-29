#include <Arduino.h>
#include <Slave0.c>

// SLAVE

#define CONTROL 2

#define Bu1 6
#define Bu2 7
#define Bu3 8
#define Bu4 9

#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13

#define DEBUG 3

void push(void);
int getStatus(void);


void setup() {
  Serial.begin (9600);

  pinMode(CONTROL,OUTPUT);

  pinMode(Bu1, INPUT);
  pinMode(Bu2, INPUT);
  pinMode(Bu3, INPUT);
  pinMode(Bu4, INPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);


  pinMode(DEBUG, OUTPUT);
  Slave0_initialize();
  rtDW.ID = 8;
  rtU.command = 0;
}

int start = -1;
int led1 = LOW;
int led2 = LOW;
int led3 = LOW;
int led4 = LOW; 

void loop() {
  int cm = millis();
  if(start != -1 && cm - start < 70) return;
  start = cm;
  rtDW.ID = 8;
  //check buttons
  push();
  //set inputs
  rtU.status =  getStatus();
  //change state
  Slave0_step();
  //check outputs
  if(rtY.bus_mode == HIGH){ //write mode
    digitalWrite(CONTROL,HIGH);
    Serial.print(rtY.bus_data);
  }else if(rtY.bus_mode == LOW){//read mode
    digitalWrite(CONTROL,LOW);
    while(!Serial.available()){}
      rtU.command = Serial.read();
  }
  if(rtU.command == rtDW.ID){
    digitalWrite(DEBUG, HIGH);
  }
  else if(rtU.command == 0)
  {
    digitalWrite(DEBUG, LOW);
  }
}

void push(){
  if(digitalRead(Bu1) || (rtDW.is_c3_Slave0==IN_getCommand && rtU.command == 2)){
    led1 = led1==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu2)  || (rtDW.is_c3_Slave0==IN_getCommand && rtU.command == 3)){
    led2 = led2==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu3)  || (rtDW.is_c3_Slave0==IN_getCommand && rtU.command == 4)){
    led3 = led3==LOW ? HIGH:LOW;
  }
  if(digitalRead(Bu4)  || (rtDW.is_c3_Slave0==IN_getCommand && rtU.command == 5)){
    led4 = led4==LOW ? HIGH:LOW;
  }
  digitalWrite(LED1, led1);
  digitalWrite(LED2, led2);
  digitalWrite(LED3, led3);
  digitalWrite(LED4, led4);
}


int getStatus(void){
  int status = led1+led2*2+led3*4+led4*8+2;
  return status;
}