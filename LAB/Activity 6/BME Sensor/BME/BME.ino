#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

const char* ssid = "me.baheti.07";   
const char* password = "123456789";   

WiFiClient  client;

unsigned long Channel_ID = 1923409;
const char * API_Key = "4JHYJDEPWG9IGO3W";

unsigned long last_time = 0;
unsigned long Delay = 30000;

// Variables to store sensor readings
float temperature;
float humidity;
float pressure;


// Create a sensor object
Adafruit_BME280 bme; 

void initBME(){
  if (!bme.begin(0x76)) {
    Serial.println("BME280 not properly connected!");
    while (1);
  }
}

void setup() {
  Serial.begin(115200);  
  initBME();
  
  WiFi.mode(WIFI_STA);   
  
  ThingSpeak.begin(client); 
}

void loop() {
  if ((millis() - last_time) > Delay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Connecting...");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    // Obtaining a new sensor reading for all fields
    temperature = bme.readTemperature();
    Serial.print("Temperature (ºC): ");
    Serial.println(temperature);
    humidity = bme.readHumidity();
    Serial.print("Humidity (%): ");
    Serial.println(humidity);
    pressure = bme.readPressure() / 100.0F;
    Serial.print("Pressure (hPa): ");
    Serial.println(pressure);
    
    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, pressure);
    ThingSpeak.setField(3, humidity);
   
    int Data = ThingSpeak.writeFields(Channel_ID, API_Key);

    if(Data == 200){
      Serial.println("Channel updated successfully!");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(Data));
    }
    last_time = millis();
  }
}
