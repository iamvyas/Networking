#include<ESP8266WebServer.h>
ESP8266WebServer server;

const char username[]="esp";
const char password[]="12345678";


#define pin 16

void setup()
{
  pinMode(pin,OUTPUT);
    Serial.begin(115200);
    WiFi.softAP(username,password);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: "); 
    Serial.println(myIP); //Pr

    server.begin();
    server.on("/led", led );
    
}

void loop()
{
  
  server.handleClient();
   
}

void led()
{
  String myhtml = "<html><head><title>ESP8266Webserver </title> </head> <body style=\"background-color: palegreen\"> <h1><center>10T</center r></h1> <form> What do you want to do? <br> <button type=\"submit\" name=\"state\" value=\"0\" > LED ON</button> <button type=\"submit\" name=\"state\" value=\"1\"> LED OFF</button> </form></body> </html>";


  server.send(200,"text/html",myhtml);
  if(server.arg("state")=="0")
  {
    digitalWrite(pin,LOW);
  }
  else{
      digitalWrite(pin,HIGH); 
   }

 
}
