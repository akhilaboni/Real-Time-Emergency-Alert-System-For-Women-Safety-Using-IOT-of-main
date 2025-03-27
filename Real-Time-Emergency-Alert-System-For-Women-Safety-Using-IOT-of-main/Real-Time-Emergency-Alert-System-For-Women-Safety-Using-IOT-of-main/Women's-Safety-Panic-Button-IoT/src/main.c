#include <stdio.h>
#include "wifi.h"
#include "gps.h"
#include "panic_button.h"
#include "config.h"
#include "WiFi.h"
#include <HTTPClient.h>

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    connect_wifi();

    // Check if panic button is pressed
    if (panic_button_pressed()) {
        char location[50];
        get_gps_location(location);
        send_alert(location);
    } else {
        Serial.println("No emergency detected.");
    }
}

void loop() {
    // Your main loop code if needed (for continuous checking)
}
