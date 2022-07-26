#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" 

#define LED1 13  //D7
#define LED2 12  //D6

const char* ssid = "Wifi_ID";
const char* password = "Wifi_PASSWORD";
void close_Door()
{  digitalWrite(LED1,LOW);
   digitalWrite(LED2,HIGH);}
void open_Door()
{  digitalWrite(LED1,HIGH);
   digitalWrite(LED2,LOW);}
void stop_Door()
{  digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);}

unsigned long start_time;
long last_time = 0;
long door_movement_time = 10000;  
int waiting_time = 2000;          
long temp_time=0;
int situation;
ESP8266WebServer server(80); 


void handleRoot() {
 String s = MAIN_page;
 server.send(200, "text/html", s);

}

void handleLED() {
 String ledState;
 String t_state = server.arg("LEDstate");
 Serial.println(t_state);
 if(t_state == "0")
 {
  if (situation==2)
  {
    stop_Door();
    delay(waiting_time);
  }
  close_Door();
  last_time = start_time;
  ledState = "Close";
  situation=1;
 }
 
 else if (t_state == "1")
 {
   if (situation==1)
  {
    stop_Door();
    delay(waiting_time);
  }
  open_Door();
  last_time = start_time;
  ledState = "Open";
  situation=2;
 }

 else if (t_state == "2")
 {
  stop_Door();
  ledState = "Stop";
  situation=0;
 } 
 
 server.send(200, "text/plane", ledState); 
}

void setup(void){
  ESP.eraseConfig();
  Serial.begin(115200);
  WiFi.softAP(ssid, password);     
  Serial.println("");

  pinMode(LED1,OUTPUT); 
  pinMode(LED2,OUTPUT);
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(myIP);  
 
  server.on("/", handleRoot);      
  server.on("/setLED", handleLED);

  server.begin();                  
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
      if (situation==1 || situation==2)
    { temp_time=start_time - last_time;
      if(temp_time>door_movement_time)
      {
        stop_Door();
        situation=0;
      }
    }
  start_time = millis();
}
