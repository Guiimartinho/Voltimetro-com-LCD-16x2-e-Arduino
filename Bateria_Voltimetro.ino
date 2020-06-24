/**
 * Nome: Luiz Guilherme M. S. Ito
 * Voltimetro
 * Date: Jun 1, 2020
 *
 * NOTE: O Voltímetro só é capaz de medir tensões de 0 - 5V.
 * Para tensões maiores, utilizar módulos divisores de Tensão para 5V de saída
 * 
 */

#include <LiquidCrystal_I2C.h>

// Constants
int VOLTAGE_PIN = A0;

// Global variables
LiquidCrystal_I2C lcd(0x27,16,2);

// ----- Bits para Caracteres Especiais para Bateria -----
byte bat0[8] = {
  B01110,
  B11011,
  B10001,
  B11011,
  B10101,
  B11011,
  B10001,
  B11111
};
byte bat1[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte bat2[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};
byte bat3[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111
};
byte bat4[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat5[8] = {
  B01110,
  B11011,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat6[8] = {
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat7[8] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {

  // Initialize the LCD and clear it
  lcd.begin(16, 2);
  lcd.clear();

  lcd.createChar(0, bat0);
  lcd.createChar(1, bat1);
  lcd.createChar(2, bat2);
  lcd.createChar(3, bat3);
  lcd.createChar(4, bat4);
  lcd.createChar(5, bat5);
  lcd.createChar(6, bat6);
  lcd.createChar(7, bat7);
  lcd.setCursor(15, 0);
}

void loop() {

  int sensorValue;
  float voltage;
  float porcent;

  // Read the analog value from A0
  sensorValue = analogRead(VOLTAGE_PIN);

  // Convert the analog value to a voltage
  //voltage = ((float)sensorValue * 5.0) / 1023;

  porcent = map(sensorValue, 658.9, 1023, 0, 100);

   if(porcent > 98.1){
    lcd.setCursor(15, 0);
    lcd.write(7);
    }
 
  else if((porcent > 91.5) && (porcent < 98.0)){
    // Display the voltage on the LCD
  lcd.setCursor(15, 0);
  //lcd.print(porcent);
  //lcd.print("%");
  lcd.write(6);
  //lcd.clear();
  }

  else if((porcent > 75.3) && (porcent < 91.4)){
    lcd.setCursor(15, 0);
    lcd.write(5);
    }

     else if((porcent > 58.6) && (porcent < 75.2)){
    lcd.setCursor(15, 0);
    lcd.write(4);
    //lcd.clear();
    }

     else if((porcent > 41.9) && (porcent < 58.5)){
    lcd.setCursor(15, 0);
    lcd.write(3);
    //lcd.clear();
    }

     else if((porcent > 25.2) && (porcent < 41.8)){
    lcd.setCursor(15, 0);
    lcd.write(2);
    //lcd.clear();
    }

     else if((porcent > 8.5) && (porcent < 25.1)){
    lcd.setCursor(15, 0);
    lcd.write(1);
    //lcd.clear();
    }
    
     else if((porcent < 8.49)){
    lcd.setCursor(15, 0);
    lcd.write(0);
    //lcd.clear();
    }
     // Wait 200 ms before taking another reading
  delay(200);
 
}
