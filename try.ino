#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char *ssid = "SuVeBi";
const char *password = "saikiran";
ESP8266WebServer server(80);
int i =0;
String text;
void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.print("Server IP address");
  Serial.println(WiFi.softAPIP());
  Serial.print("Server MAC address");
  Serial.println(WiFi.softAPmacAddress());
  server.on("/" ,webServer);
  server.begin();
  pinMode(2,OUTPUT);
}

void loop() {
  server.handleClient();
}

void webServer(){
    String webpage;
webpage = "<html>";
webpage += "<head>";
  webpage += "<title>Welcome</title>";
webpage += "</head>";
webpage += "<body style='text-align: center; width: 100%;'>";
webpage += "<h1>FAN</h1>";
webpage += "<div style='width: 100%'>";
  webpage += "<form method='POST' action=' ' style='width: 50%;float: left;'>";
    webpage += "<input type='text' name='FAN1' style='visibility: hidden;'>";
    webpage += "<button type='submit'>ON</button>";
  webpage += "</form>";
  webpage += "<form method='POST' action=' ' style='width: 50%;float: left;'>";
    webpage += "<input type='text' name='FAN0' style='visibility: hidden;'>";
    webpage += "<button type='submit'>OFF</button>";
  webpage += "</form>";
webpage += "</div>";
webpage += "</body>";
webpage += "</html>";
server.send(200, "text/html", webpage);
if(server.args()>0){
  for(uint8_t i=0; i<server.args(); i++){
    if(server.argName(i) == "FAN1"){
      digitalWrite(2,LOW);
      }else if(server.argName(i)== "FAN0"){
        digitalWrite(2,HIGH);
        }else{
    digitalWrite(2,LOW);
    }
    }
    }
}
