#include "SCoop.h"
#include "dht11.h"
  dht11 DHT11;
#define DHT11PIN 7
defineTask(Task1);
//defineTask(Task2);
#define NTD0 -1
#define NTD1 270
#define NTD2 290
#define NTD3 325
#define NTD4 350
#define NTD5 390
#define NTD6 440
#define NTD7 500

#define NTDL7 245

#define NTDH1 535
#define NTDH2 590
#define NTDH3 655
#define NTDH4 700
#define NTDH5 780
#define NTDH6 880
#define NTDH7 999

//#define WHOLEQUA 4
#define WHOLEDOUBLE 2
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
//#define EIGHTH 0.125
#define SIXTEENTH 0.625

int tune1[]=
{
NTDH4,NTDH3,NTDH2,NTDH1,
NTD7,NTD6,NTD7,NTDH1,
NTDH2,NTDH1,NTD7,NTD6,
NTD5,NTD4,NTD5,NTD6,
NTDH6,NTDH4,NTDH5,NTDH6,NTDH4,NTDH5,
NTDH6,NTD6,NTD7,NTDH1,NTDH2,NTDH3,NTDH4,NTDH5,
NTDH4,NTDH2,NTDH3,NTDH4,NTD4,NTD5,
NTD6,NTD7,NTD6,NTD5,NTD6,NTD4,NTD5,NTD6,
NTD5,NTD7,NTD6,NTD5,NTD4,NTD3,
NTD4,NTD3,NTD2,NTD3,NTD4,NTD5,NTD6,NTD7,
NTD5,NTD7,NTD6,NTD7,NTDH1,NTDH2,
NTD6,NTD7,NTDH1,NTDH2,NTDH3,NTDH4,NTDH5,NTDH6,
NTDH4,NTDH2,NTDH3,NTDH4,NTDH3,NTDH2,
NTDH3,NTDH1,NTDH2,NTDH3,NTDH4,NTDH3,NTDH2,NTDH1,
NTDH2,NTD7,NTDH1,NTDH2,NTD2,NTD3,
NTD4,NTD5,NTD4,NTD3,NTD4,NTDH2,NTDH1,NTDH2,
NTD7,NTDH2,NTDH1,NTD7,NTD6,NTD5,
NTD6,NTD5,NTD4,NTD5,NTD6,NTD7,NTDH1,NTDH2,
NTD7,NTDH2,NTDH1,NTDH2,NTDH1,NTD7,
NTDH1,NTDH2,NTDH3,NTDH2,NTDH1,NTDH2,NTD7,NTDH1,
};
float durt1[] =
{
 2,2,2,2,
  2,2,2,2,
  2,2,2,2,
  2,2,2,2,
  0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
 0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
   0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
 0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,
};
int tune2[]=
{
NTD5 ,NTDH1,NTDH2, NTDH3,NTDH2,NTDH1,NTDH1,NTD0,
NTD5 ,NTDH1 ,NTDH2, NTDH3,NTDH2,NTDH1,NTDH2,NTDH3,NTDH3,
NTD5 ,NTDH1 ,NTDH2, NTDH3,NTDH2,NTDH1,NTDH1,NTD0,
NTD5 ,NTDH1 ,NTDH2, NTDH3,NTDH2,NTDH1,NTDH2,NTDH5,NTDH3,
NTDH3,NTDH4,NTDH5,NTDH5,NTDH5,NTDH5,NTDH5,NTDH3,NTDH1,
NTDH3,NTDH4,NTDH5,NTDH5,NTDH5,NTDH5,NTDH5,NTDH3,NTDH1,
NTDH1,NTDH2,NTDH3,NTDH3,NTDH3,NTDH3,NTDH3,NTDH6,NTDH6,NTDH3,NTDH2,NTDH1,NTDH2,NTDH2,NTDH2,

};
float durt2[]=
{
0.25,0.25,0.25,0.25,0.5,0.25,1,1,
0.25,0.25,0.25,0.25,0.5,0.25,0.5,0.5,1,
0.25,0.25,0.25,0.25,0.5,0.25,1,1,
0.25,0.25,0.25,0.25,0.5,0.25,0.5,0.5,1,
0.5,0.5,0.5,0.25,0.625,0.5,0.5,0.25,0.625,
0.25,0.25,0.5,0.25,0.625,0.5,0.5,0.25,0.625,
0.25,0.25,0.5,0.25,0.625,0.5,0.5,0.5,0.25,0.25,0.25,0.5,1,0.5,0.25,

};
int length1;
int length2;
int tonepin=6;
int ledp=13;
//int ledw=9;
//int ledcolor=12;
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
//int relay5 = 5;


void setup(){
  Serial.begin(9600);
 mySCoop.start();
 pinMode(tonepin,OUTPUT);
 pinMode(ledp,OUTPUT);
 //pinMode(ledw,OUTPUT);
 //pinMode(ledcolor,OUTPUT);
 
  length1=sizeof(tune1)/sizeof(tune1[0]);
  length2=sizeof(tune2)/sizeof(tune2[0]);
}

void loop(){
   DHT11.read(DHT11PIN);
  if (DHT11.humidity>0&&DHT11.temperature>59)
  {for(int x=0;x<length1;x++)
  {
    tone(tonepin,tune1[x]);
    //digitalWrite(jidianqi, HIGH);
    digitalWrite(ledp, HIGH); 
    //digitalWrite(ledw, HIGH); 
    //digitalWrite(ledcolor, LOW); 
    delay(400*durt1[x]);//pgm_read_byte_near(&durt1[x])
    //与前一代码不同之处，这里将原来的500分为了400和100，分别控制led的开与关
    digitalWrite(ledp, LOW);
    //digitalWrite(ledw, LOW);
    //digitalWrite(ledcolor, HIGH);
    //digitalWrite(jidianqi, LOW);
    delay(100*durt1[x]);
    noTone(tonepin);
  }}
   if (DHT11.humidity>0&&DHT11.temperature<60)
  {for(int x=0;x<length2;x++)
  {
    tone(tonepin,tune2[x]);
    //digitalWrite(jidianqi, HIGH);
    digitalWrite(ledp, HIGH); 
    //digitalWrite(ledcolor, LOW); 
    delay(600*durt2[x]);//pgm_read_byte_near(&durt1[x])
    //与前一代码不同之处，这里将原来的500分为了400和100，分别控制led的开与关
    digitalWrite(ledp, LOW);
    //digitalWrite(ledcolor, HIGH);
    //digitalWrite(jidianqi, LOW);
    delay(150*durt2[x]);
    noTone(tonepin);
  }}
  yield();
  }
  
  void Task1::setup()
 {
   Serial.begin(9600);
   pinMode(relay1,OUTPUT);
   pinMode(relay2,OUTPUT);
   pinMode(relay3,OUTPUT);
   pinMode(relay4,OUTPUT);
   //pinMode(relay5,OUTPUT);
 }
 void Task1::loop()
 {
  DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);
  if (DHT11.humidity>0&&DHT11.temperature>59)
  {
  //lento
  for(int i=1;i<=2;i++)
  {digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, LOW);
  sleep(2000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(2000);}
  for(int i=1;i<=2;i++)
  {digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, LOW);
  sleep(1000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(1000);}
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(2000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(2000);
  //fast ++
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(2000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1000);
  }
  if (DHT11.humidity>0&&DHT11.temperature<60)//temp<20&&temp>40&&hum<20&&hum>40
  { //lento
  for(int i=1;i<=2;i++)
  {digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, LOW);
  sleep(1312.5);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1500);}
  for(int i=1;i<=2;i++)
  {digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(1312.5);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1500);}
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, LOW);
  sleep(1125);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, LOW);
  sleep(1656);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, LOW);
  sleep(750);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1406);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(656);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(750);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(656);
  digitalWrite(relay1, LOW); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW); 
  digitalWrite(relay4, HIGH);
  sleep(1406);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, LOW);
  sleep(1500);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH); 
  digitalWrite(relay4, HIGH);
  sleep(1875);
  }
 }
 /*void Task2::setup()
 {
   pinMode(relay5,OUTPUT);
 }
  void Task2::loop()
 { digitalWrite(relay5, HIGH);
   sleep(30000);
 }*/
