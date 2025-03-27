#include <stdio.h>
#include "gps.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// GPS object and serial communication
TinyGPSPlus gps;
SoftwareSerial ss(4, 3); // RX, TX pins for GPS module

void get_gps_location(char *location) {
    while (ss.available() > 0) {
        gps.encode(ss.read());
    }

    if (gps.location.isUpdated()) {
        float lat = gps.location.lat();
        float lon = gps.location.lng();
        snprintf(location, 50, "Lat: %.6f, Lon: %.6f", lat, lon);
    } else {
        strcpy(location, "No GPS Signal");
    }
}
