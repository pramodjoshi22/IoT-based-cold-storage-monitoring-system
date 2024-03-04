#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
#define DHTPIN 3     // what pin we're connected to DHT11
#define DHTTYPE DHT11 
LiquidCrystal_I2C lcd(0x27, 16, 2);
// DHT 11
DHT dht(DHTPIN, DHTTYPE);
int light;
const int MQ3=0;
const int LED=8;
const int LEDG=7;
int value;
int h;  //Stores humidity value
int t; //Stores temperature value

void setup() {
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(MQ3, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LEDG, OUTPUT);
  digitalWrite(LED,LOW);
  digitalWrite(LEDG,LOW);
  dht.begin();
  lcd.begin();
  lcd.backlight();
}
void loop()
{
  value= analogRead(MQ3);
  light = analogRead(A2);
  h = dht.readHumidity();
  t = dht.readTemperature();
  float value1= analogRead(MQ3);
  float  light1 = analogRead(A2);
  float h1 = dht.readHumidity();
  float t1 = dht.readTemperature();
    lcd.setCursor(1,0);
    lcd.print("Food Spoilage ");
    lcd.setCursor(1,1);
    lcd.print("Dection System");
    delay(3000);
    lcd.backlight();
    lcd.clear();
    delay(3000);
    lcd.clear();
    Serial.print(h1);
    Serial.print(",");
    Serial.print(t1);
    Serial.println();
    Serial.print(value1);
    Serial.print(",");
    Serial.print(light1);
    Serial.println();

   if(h>73 ||t>24){
    digitalWrite(LED,HIGH);
    digitalWrite(LEDG,LOW);
    lcd.setCursor(1,0);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");
   lcd.setCursor(9,0);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(2,1);
    lcd.print("Food Spoiled ");
    delay(3000); //Delay 3 sec.
}else{
   
 digitalWrite(LEDG,HIGH);
 digitalWrite(LED,LOW);
   lcd.setCursor(1,0);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");
   lcd.setCursor(9,0);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%RH");
    lcd.print(light);
      lcd.setCursor(3,1);
    lcd.print("Fresh Food");
    delay(3000); //Delay 3 sec.
}
lcd.clear();
  if(value>780|| light>500 )
  {
    digitalWrite(LED,HIGH);
    digitalWrite(LEDG,LOW);
  
    lcd.setCursor(1,0);
    lcd.print("MQ3=");
    lcd.print(value);
    lcd.setCursor(9,0);
    lcd.print("LDR=");
    lcd.print(light);
    lcd.setCursor(2,1);
    lcd.print("Food Spoiled ");
  }else{
   digitalWrite(LEDG,HIGH);
   digitalWrite(LED,LOW);
    lcd.setCursor(1,0);
    lcd.print("MQ3=");
    lcd.print(value);
    lcd.setCursor(9,0);
    lcd.print("LDR=");
    lcd.print(light);
    lcd.setCursor(3,1);
    lcd.print("Fresh Food");
  }
 //Delay 3 sec.
  delay (3000);
}




