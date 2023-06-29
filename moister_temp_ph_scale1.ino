#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float volume=0;
float Moisture=0;
float temp=0;
int buzz=13;

void setup() 
{
  pinMode (8,OUTPUT);
  lcd.begin(16, 2); 
  //
  lcd.setCursor(4,0);
  lcd.print("IOT MAJOR");
  lcd.setCursor(5,4);
  lcd.print("PROJECT");
  delay(2000);
  lcd.clear();
  
}

void loop() 
{
  //calculating an displaying moisture
  volume=analogRead(A0);
  Moisture=(volume/1023)*100;
  lcd.setCursor(0,0);lcd.print("Moisture: ");
  lcd.print (Moisture);lcd.print("%");
  
  //calculating and displaying temp
  temp=analogRead(A1);
  temp= (temp * 0.48828125-50);
  lcd.setCursor(0, 1);lcd.print ("Temp: ");
  lcd.print(temp);lcd.print("C");
  //condition to turn motor on
    if (Moisture<=20 && temp> 24)
  {
    digitalWrite (8,1);
    
  } 
   else if (Moisture>=40)
  {
    digitalWrite (8,0);
    
  }
  
  delay (1000);
}
