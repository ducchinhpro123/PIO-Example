#include "WiFiType.h"
#include "esp32-hal-adc.h"
#include <Arduino.h>
#include <WiFi.h>

// Built-in LED pin (usually GPIO 2 on most ESP32 boards)
#define LED_BUILTIN 2



void setup() {
    // Initialize serial communication at 115200 baud rate
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    // Initialize the built-in LED pin as an output
    // pinMode(LED_BUILTIN, OUTPUT);

    Serial.println("Setup done");
}

void loop() {
    Serial.println("scan start");
    int n = WiFi.scanNetworks();

    Serial.println("scan done");

    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; i++) {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
    delay(5000);


}
