#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pirPin 12 
int statusPir = LOW; 
int gerakanPir; 
int motioncount = 0;

void setup() {
  pinMode(pirPin, INPUT); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Tugas");
  lcd.setCursor(3,1);
  lcd.print("Sensor PIR");
  Serial.begin(9600); 
  delay(4000);
}

void loop() {
  gerakanPir = digitalRead(pirPin);
  if(gerakanPir==HIGH){ 
    delay(2000);
    motioncount++;
    updateLCD();

    Serial.print("Motion Detect = ");
    Serial.println(motioncount);

    lcd.backlight();  
    lcd.setCursor(0, 0);  
    lcd.print("Motion Detect !");
    delay(2000) ;
  }
  else{  
    Serial.println("NO motion detect");
    lcd.clear();
  }
  delay(2000);
}

void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("Count =  ");
  lcd.print(motioncount);
}

