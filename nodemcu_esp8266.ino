#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>
String URL="http://api.thingspeak.com/update?api_key=YOUR_THINKSPEAK_KEY=";
void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  delay(2000);
  Serial.print("Start connection...");
  WiFi.begin("YOUR_SSID_NAME","YOUR_WIFI_PASSWORD");
  while((!(WiFi.status()== WL_CONNECTED))){
      delay(200);
      Serial.print("..");
    }
    Serial.println("Connected...");
}

void loop() {
      if(Serial.available()>0){
        String data = Serial.readStringUntil('\n');
        Serial.println(data);
        int comma = data.indexOf(',');
        if(comma!=-1){
          float h1=data.substring(0,comma).toFloat();
          float t1=data.substring(comma+1).toFloat();

          String data = Serial.readStringUntil('\n');
          Serial.println(data);
          int comma = data.indexOf(',');
          if(comma!=-1){
          float light1=data.substring(0,comma).toFloat();
          float value1=data.substring(comma+1).toFloat();
         
          
          Serial.print(h1);
          Serial.print(t1);
          Serial.print(light1);
          Serial.print(value1);
          sendData(t1,h1,light1,value1);
        }
      }
      }
}
void sendData(float t1, float h1,float light1, float value1){
  WiFiClient client;
  HTTPClient http;
  String newUrl= URL+String(t1)+"&field2="+String(h1)+"&field3="+String(light1)+"&field4="+String(value1);
  http.begin(client,newUrl);
  int responsecode=http.GET();
  String data=http.getString();
  Serial.println(data);
  http.end();
}
