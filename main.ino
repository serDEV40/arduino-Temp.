#include <LiquidCrystal.h>;
int buttonPin = 8;
int Beta = 3950;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16,2);
}

void loop() {
  if(digitalRead(buttonPin) == LOW){
    int analogValue = analogRead(A5);
    double quadratic = 1 / (log(1 / (1023. / analogValue - 1)) / Beta + 1.0 / 298.15) - 273.15;
    double fahr = ((9/5) * quadratic) + 32 ; 
    lcd.setCursor(9,0);
    lcd.print(fahr);
    lcd.setCursor(14,0);
    lcd.print(char(223));
    lcd.setCursor(15,0);
    lcd.print("F");
  }else{
    int analogValue = analogRead(A5);
    double quadratic = 1 / (log(1 / (1023. / analogValue - 1)) / Beta + 1.0 / 298.15) - 273.15;
    lcd.setCursor(9,0);
    lcd.print(quadratic);
    lcd.setCursor(14,0);
    lcd.print(char(223));
    lcd.setCursor(15,0);
    lcd.print("C");
  }
}
