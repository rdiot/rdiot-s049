/* Mini Mercury Switch Module (KY-017) [S049] : http://rdiot.tistory.com/77 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int pin = 2;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S049:Mercury KY-017");
 
  int val = digitalRead(pin);
 
  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");
 
  if(val == LOW)
  { 
    lcd.setCursor(0,2);
    lcd.print("Tilt CLOSE");
  }
  else
  {
    lcd.setCursor(0,2);
    lcd.print("Tilt OPEN ");  
  }
  
}
