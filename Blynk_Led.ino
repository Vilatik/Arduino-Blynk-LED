// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
#define BLYNK_TEMPLATE_ID "Template ID"
#define BLYNK_DEVICE_NAME "Device Name"
#define BLYNK_AUTH_TOKEN "Token"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.  
char ssid[] = "";
char pass[] = "";
//Pin here
int LED = D3
BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  if (value == 1) {
    digitalWrite(BUILTIN_LED, 0);//Comment it to disable LED on board
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(BUILTIN_LED, 1); //Comment it to disable LED on board
    digitalWrite(LED, LOW);
  }
  Blynk.virtualWrite(V1, value);
}

BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void myTimerEvent()
{
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);//Comment it to disable LED on board
  Blynk.begin(auth, ssid, pass);
  pinMode(LED, OUTPUT);
  timer.setInterval(1000L, myTimerEvent);
}
void loop()
{
  Blynk.run();
  timer.run();
}


