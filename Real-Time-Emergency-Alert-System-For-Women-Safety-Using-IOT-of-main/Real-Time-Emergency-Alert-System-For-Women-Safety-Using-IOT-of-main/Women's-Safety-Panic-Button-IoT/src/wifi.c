#include <WiFi.h>
#include "wifi.h"
#include "config.h"

void connect_wifi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connected to Wi-Fi!");
}
