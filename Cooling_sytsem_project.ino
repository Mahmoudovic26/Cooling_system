/**
 ******************************************************************************
 **Version 2.2.1
 * @file           : Cooling_sytsem_project.ino
 * @author         : Bayoumi
 * @brief          : contains DHT11,LCD,Arduino uno,fan
 ******************************************************************************
 */

#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(4, 5, 0, 1, 2, 3); //declartion of lcd pins
//4 RS,5 E
int fan=12;//fan pin
int DHTPIN =11;//dht pin
int led=8;//led pin
#define DHTTYPE DHT11   //getting dht function from dht library
DHT dht(DHTPIN, DHTTYPE); 
void setup() {
 dht.begin();
  lcd.begin(16, 2);
}


void loop() {
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  int hum = dht.readHumidity();
  int tem = dht.readTemperature();  
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(tem);
  lcd.print("C");
  lcd.setCursor(0, 1);//(col,row)
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
    if(tem>=30){
    digitalWrite(fan,HIGH);
    }
    else
    {
      digitalWrite(fan,LOW);
    }
    if(tem>=30){
      while(tem>=30){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    break;
    }
    }
    else
    {
      digitalWrite(led,LOW);
    }
  delay(500);
  }


/**
 ******************************************************************************
 User          Date                 Brief
 ******************************************************************************
 Bayoumi     15Nov2022            started project 'version 1.0.0'
 Bayoumi     30Nov2022            changed the used sensor from lm35 to DHT11 'version 2.0.0'
 Bayoumi     2Dec2022             Added the fan to the system 'version 2.1.0'
 Abdulrahman 2Dec2022             Fixed the fan bug 'version 2.1.1'
 Bayoumi      2Dec2022             fixed fan control bug & added led 'version 2.2.1'
*/
