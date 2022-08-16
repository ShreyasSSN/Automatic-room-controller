#include<LiquidCrystal.h>
int in=4;
int out=5;
int visit=0;
int led=7;
int fan=6;
LiquidCrystal lcd(13, 12, 8, 9, 10, 11);
bool p1,p0;
void setup()
{
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  lcd.begin(16,2);
}

void loop(){
  lcd.clear();
  p1=digitalRead(in);
  p0=digitalRead(out);
  if(p1==1)
  {
    visit++;
    delay(500);
  }
  if(p0==1)
  {
    visit--;
    delay(500);
  }
 // visit=constrain(visit, 0, 50);
  lcd.setCursor(0,0);
  lcd.print("people in");
  if(visit>0)
  {
    digitalWrite(led, HIGH);
    digitalWrite(fan,HIGH);
    lcd.setCursor(0,1);
  	lcd.print(visit);
  	lcd.print(" people inside");
  }
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(fan,LOW);
    lcd.setCursor(0,1);
    visit=0;
  	lcd.print(visit);
  	lcd.print(" people inside");
  }
  delay(2000);
}
