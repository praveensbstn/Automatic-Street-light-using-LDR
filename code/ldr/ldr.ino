#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 1);//(rs,e,d4,d5,d6,d7)

int ldrpin= A0;   // select the input pin for ldr
int ldrvalue = 0;  // variable to store the value coming from the sensor

void setup() {
 // Serial.begin(9600); //sets serial port for communication
  
lcd.begin(16, 1);
// Print a message to the LCD.
lcd.print("Ldr out= ");

pinMode(2, OUTPUT); //pin connected to the relay
}

void loop() 
{
  // read the value from the sensor:
  ldrvalue = analogRead(ldrpin);    
  
  lcd.setCursor(10,0);
  lcd.print(ldrvalue);
  
  if(ldrvalue > 300) //setting a threshold value
  digitalWrite(2,LOW); //turn relay off
  
  else 
  
  digitalWrite(2,HIGH); //turn relay On
  
  delay(100);                  
}
