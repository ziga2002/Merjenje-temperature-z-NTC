//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int Sensor_Pin = A0;

byte stopinja[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  
  pinMode(Sensor_Pin, INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  lcd.createChar(0, stopinja);

  lcd.setCursor(3,0);
  lcd.print("TERMOMETER");
  lcd.setCursor(3,1);
  lcd.print("Ver. : 1.0");
  delay(2000);
  lcd.clear();
}

void loop() {
 
  int Sensor_Val = analogRead(Sensor_Pin);
  float Analog_in_voltage = (Sensor_Val / 1023.0);
  float Temp_C = (Analog_in_voltage - 0.5) * 100;


  lcd.setCursor(0, 0);
  lcd.print("Temp.: ");
  lcd.setCursor(7,0);
  lcd.print(Temp_C);
  lcd.setCursor(13, 0);
  lcd.write(0);
  lcd.setCursor(14, 0);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print(" or ");

  lcd.setCursor(6,1);
  lcd.print(Temp_C + 273.15);
  lcd.setCursor(13, 1);
  lcd.write(0);
  lcd.setCursor(14, 1);
  lcd.print("K");

  delay(2000);

  lcd.setCursor(6,1);
  lcd.print(" ");
  lcd.setCursor(7,1);
  lcd.print(Temp_C * 1.8 +32);
  lcd.setCursor(12, 1);
  lcd.print(" ");
  lcd.setCursor(13, 1);
  lcd.write(0);
   lcd.setCursor(14, 1);
  lcd.print("F");
  
   
  delay(2000);

}
