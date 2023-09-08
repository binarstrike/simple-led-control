#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "secret.h"

/**
 * isi data dibawah sesuai dengan yang ada pada aplikasi blynk atau web blynk.cloud
 * dan sesuaikan nama akses point atau hotspot dan password nya
*/
#ifndef SECRET_H_
  #define BLYNK_AUTH_TOKEN "auth token"
  #define SSID "access point 1"
  #define PASSWORD "password"
#endif

#define BLYNK_TEMPLATE_ID "TMPL62F1EqaD-"
#define BLYNK_TEMPLATE_NAME "Template 3A9D2F7"
#define BLYNK_PRINT Serial

const uint8_t LED_PIN = D1;
uint8_t brightness = 0;

BLYNK_WRITE(V0) //* slider 0 ~ 255
{
  brightness = param.asInt();
}
BLYNK_WRITE(V1) //* button on: 255, off: 0
{
  brightness = param.asInt();
}
BLYNK_CONNECTED()
{
  Blynk.syncAll();
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASSWORD);
  pinMode(LED_PIN, OUTPUT);
}
void loop()
{
  Blynk.run();
  analogWrite(LED_PIN, brightness);
}