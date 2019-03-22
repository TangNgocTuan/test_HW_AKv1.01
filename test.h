#include "SIM808.h"
#define Hi    1
#define Lo    0

#define ERR   26
#define SIM   27
#define WIFI  14
#define Vsys  25
#define BAUD  115200
#define Vctrl 19
#define EMR   5
#define PWR   4
#include <WiFi.h>

#define ssid     "CRETA-KD"
#define password "yoursolution"

void initPort();
void testSerial();
void startPort();
void testWifi();
void testSim();
void testPower();
