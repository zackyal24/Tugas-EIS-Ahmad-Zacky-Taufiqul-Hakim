#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int valorsensorgas;
int LED = 7;
int buzzerPin = 13;

// Tentukan batas bawah dan atas untuk deteksi gas
const int gasThresholdLow = 300;  
const int gasThresholdHigh = 1000; 

void setup() { 
  pinMode(LED, OUTPUT);
  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Mengaktifkan lampu latar LCD
  lcd.print("Gas Zacky");
  Serial.begin(9600);
}

void loop() {
  valorsensorgas = analogRead(A1);
  delay(1000);

  lcd.clear();
  lcd.print("sensor gas: ");
  lcd.print(valorsensorgas, 1); 
  Serial.print(valorsensorgas);
  Serial.println();

  // Cek apakah nilai sensor gas berada dalam rentang tertentu
  if (valorsensorgas >= gasThresholdLow && valorsensorgas <= gasThresholdHigh) {
    digitalWrite(LED, HIGH); // Nyalakan LED
    tone(buzzerPin, 200); //nyalakan buzzer
  } else {
    noTone(buzzerPin); //matikan buzzer
    digitalWrite(LED, LOW); // Matikan LED
  }
  delay(1000);
}

