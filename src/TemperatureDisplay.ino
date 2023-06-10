#include <DHT.h>
#include <LiquidCrystal.h>

const int RS = 2, EN = 3, D0 = 4, D1 = 5, D2 = 6, D3 = 7, D4 = 8, D5 = 9, D6 = 10, D7 = 11; //Arduino Digital Pin Numbers for LCD pins
LiquidCrystal lcd(RS, EN, D0, D1, D2, D3, D4, D5, D6, D7);                                  //Creating a LCD object using the pin numbers

const int DHTPIN = 12;   //Arduino Digital Pin Numbers for DHT signal pin
DHT dht11(DHTPIN, DHT11); //Creating a DHT object for DHT11 sensor connected at Pin 12

void setup() {

  //LCD initialization
  lcd.begin(16, 2);   //Initialize cols and rows of LCD
  lcd.setCursor(0,0); //Start writing on first line
  lcd.write("Temp:"); 
  lcd.setCursor(0,1); //Start writing on second line
  lcd.write("Humd:");  

  //DHT initialization
  dht11.begin();   //Start reading data from DHT11 sensor

}

void loop() {
  
  float temperature = dht11.readTemperature(true); //Reading in temp in Fahreinheit from sensor
  float humidity = dht11.readHumidity();           //Reading in humidity from sensor

  //Printing temperature onto LCD Display
  lcd.setCursor(5,0);
  lcd.print(temperature);
  lcd.setCursor(10,0);
  lcd.print("F");

  //Printing humidity onto LCD Display
  lcd.setCursor(5,1);
  lcd.print(humidity);
  lcd.setCursor(10,1);
  lcd.print("%");

  
}
