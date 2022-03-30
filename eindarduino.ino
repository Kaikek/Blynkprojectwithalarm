#define BLYNK_TEMPLATE_ID           "TMPLaJSpESSy"
#define BLYNK_DEVICE_NAME           "trueproject"
#define BLYNK_AUTH_TOKEN            "KqYRCf51NysUZCu1QMJoGAl870vDhrAa"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "NoWifi";
char pass[] = "MALLALI1975";

#define DHTPIN 26         
#define DHTTYPE DHT11 
#define led 25
#define alarm 33


DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

float h;
float t;
String text;
int ledstates = 0;
int alarmstates = 0;
int stopalarm = 0;

void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {
    Serial.println("nope");
    return;
  }
  
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V7, ledstates);
  Blynk.virtualWrite(V8, alarmstates);
  
}

BLYNK_WRITE(V4)
{
  text = param.asStr(); 
  Serial.print("The message is: ");
  Serial.println(text);
}

BLYNK_WRITE(V9)
{
  stopalarm = param.asInt(); 
}

void myTimerEvent()
{
  Blynk.virtualWrite(V10, millis() / 1000);
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  dht.begin();

  pinMode(led, OUTPUT);
  pinMode(alarm, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { 
    Serial.println(F("SSD1306 allocation failed"));
  }

  timer.setInterval(1000L, sendSensor);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  
  display.clearDisplay();
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.setCursor(32, 18);
  display.print(t);
  display.println("*C");
  display.setCursor(32, 28);
  display.print(h);
  display.println("%");
  display.setCursor(32, 38);
  display.print(text);
  
  if(text == "O")
  {
    display.setCursor(32, 48);
    digitalWrite(led, HIGH);
    display.print("Led is ON");
    ledstates = 1;
  }
  else if(text == "N")
  {
    display.setCursor(32, 48);
    digitalWrite(led, LOW);
    display.print("Led is OFF");
    ledstates = 0;
  }

  if(t >= 28)
  {
    if(stopalarm == 0)
    { 
      digitalWrite(alarm, HIGH);
      alarmstates = 1;
    }
    else
    {
      digitalWrite(alarm, LOW);
      alarmstates = 0;
    }
  }
  else if(t < 27)
  {
    digitalWrite(alarm, LOW);
    alarmstates = 0;
  }
  
  display.display();

  
}
