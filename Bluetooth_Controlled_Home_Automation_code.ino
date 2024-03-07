#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
#define bulb 12
#define fan 11
#define AC 10
#define TV 9
int b,f,a,t;
char *bb,*ff,*aa,*tt;
void setup()
{
pinMode(AC, OUTPUT);
pinMode(TV, OUTPUT);
pinMode(fan, OUTPUT);
pinMode(bulb, OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();
lcd.print("Home Automation");
lcd.setCursor(0,1);
lcd.print(" With LCD");
delay(2000);
}
void Display(char *B="OFF",char *A="OFF",char *F="OFF",char *T="OFF")
{
lcd.clear();
lcd.print("bulb:");
lcd.print(B);
lcd.setCursor(10,0);
lcd.print("AC:");
lcd.print(A);
lcd.setCursor(0,1);
lcd.print("fan:");
lcd.print(F);
lcd.setCursor(9,1);
lcd.print("TV:");
lcd.print(T);
delay(500);
}
void loop()
{
Display(bb,aa,ff,tt);
delay(500);
if(Serial.available()>0)
{
char data = Serial.read();
if(data == '1')
{
digitalWrite(bulb, HIGH);
bb="ON";
}
if(data == '2'){
digitalWrite(bulb, LOW);
b=0;
bb="OFF";
} 
if(data == '3')
{
digitalWrite(fan, HIGH);
ff="ON";
}
if(data == '4'){
digitalWrite(fan, LOW);
f=0;
ff="OFF";
} 
if(data == '5')
{
digitalWrite(AC, HIGH);
aa="ON";
}
if(data == '6'){
digitalWrite(AC, LOW);
a=0;
aa="OFF";
} 
if(data == '7')
{
digitalWrite(TV, HIGH);
tt="ON";
}
if(data == '8'){
digitalWrite(TV, LOW);
t=0;
tt="OFF";
} 
}
}
void Display(String B="OFF",String A="OFF",String F="OFF",String T="OFF")
{
lcd.clear();
lcd.print("bulb:");
lcd.print(B);
lcd.setCursor(10,0);
lcd.print("AC:");
lcd.print(A);
lcd.setCursor(0,1);
lcd.print("fan:");
lcd.print(F);
lcd.setCursor(9,1);
lcd.print("TV:");
lcd.print(T);
delay(500);
}
