#include <Thermocouple.h> 
#include <MAX6675_Thermocouple.h> 

#define SCK_PIN 10 
#define CS_PIN 9 
#define SO_PIN 8 

int ledBlue = 48; 
int ledGreen = 50; 
int ledRed = 52; 

Thermocouple* thermocouple;

void setup() { 
    Serial.begin(9600); 
    pinMode(ledBlue, OUTPUT); 
    pinMode(ledGreen, OUTPUT); 
    pinMode(ledRed, OUTPUT); 
    thermocouple = new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN); 
}

void loop() { 
    const double celsius = thermocouple->readCelsius(); 

    Serial.print("Temperature: "); 
    Serial.print(celsius); 
    Serial.println(" C, "); 

    if (celsius < 180) { 
        digitalWrite (ledBlue, HIGH); 
        digitalWrite (ledGreen, LOW); 
        digitalWrite (ledRed, LOW); 
    }
    else if (celsius < 260){ 
        digitalWrite (ledBlue, LOW); 
        digitalWrite (ledGreen, HIGH); 
        digitalWrite (ledRed, LOW); 
    }
    else if (260 < celsius){ 
        digitalWrite (ledBlue, LOW); 
        digitalWrite (ledGreen, LOW); 
        digitalWrite (ledRed, HIGH); 
    }
    delay(500); 
}