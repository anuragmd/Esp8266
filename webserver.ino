#include <ESP8266WiFi.h>
const char* ssid = "********";  // Enter SSID here
const char* password = "********";  //Enter Password here

// Variable to store the HTTP request
String header;
String D1State = "off";
String D2State = "off";
String D3State = "off";
String D4State = "off";
String D5State = "off";
String D6State = "off";
String D7State = "off";
String D8State = "off";
const int p1 = 0;
const int p2 = 1;
const int p3 = 2;
const int p4 = 3;
const int p5 = 4;
const int p6 = 5;
const int p7 = 6;
const int p8 = 7;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(p1, OUTPUT);
  digitalWrite(p1, LOW);
 Serial.print("Connecting to ");
 Serial.println(ssid);
WiFi.begin( ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   Serial.print(".");
 }

// Print local IP address and start web server
 Serial.println("");
  Serial.println("WiFi connected-->");
  Serial.println("Copy this IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
 WiFiClient client = server.available();   
  if (client) {                             // If a new client connects,
    Serial.println("new client connected");          
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected())
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /D1/on") >= 0) {    //device 1
              Serial.println("D1 on");
              D1State = "on";
              digitalWrite(p1, HIGH);
            } 
            else if (header.indexOf("GET /D1/off") >= 0) {
              Serial.println("D1 off");
              D1State = "off";
              digitalWrite(p1, LOW);
            } 
            if (header.indexOf("GET /D2/on") >= 0) {    //device 2
              Serial.println("D2 off");
              D2State = "on";
              digitalWrite(p2, HIGH);
            }
            else if (header.indexOf("GET /D2/off") >= 0) {
              Serial.println("D2 off");
              D2State = "off";
              digitalWrite(p2, LOW);
            }    
            if (header.indexOf("GET /D3/on") >= 0) {    //device 3
              Serial.println("D3 off");
              D3State = "on";
              digitalWrite(p3, HIGH);
            }
            else if (header.indexOf("GET /D3/off") >= 0) {
              Serial.println("D3 off");
              D3State = "off";
              digitalWrite(p3, LOW);
            }    
            if (header.indexOf("GET /D4/on") >= 0) {    //device 4
              Serial.println("D4 off");
              D4State = "on";
              digitalWrite(p4, HIGH);
            }
            else if (header.indexOf("GET /D4/off") >= 0) {
              Serial.println("D2 off");
              D4State = "off";
              digitalWrite(p4, LOW);
            }    
            if (header.indexOf("GET /D5/on") >= 0) {    //device 5
              Serial.println("D5 off");
              D5State = "on";
              digitalWrite(p5, HIGH);
            }
            else if (header.indexOf("GET /D5/off") >= 0) {
              Serial.println("D5 off");
              D5State = "off";
              digitalWrite(p5, LOW);
            }    
            if (header.indexOf("GET /D6/on") >= 0) {    //device 6
              Serial.println("D6 off");
              D6State = "on";
              digitalWrite(p6, HIGH);
            }
            else if (header.indexOf("GET /D6/off") >= 0) {
              Serial.println("D6 off");
              D6State = "off";
              digitalWrite(p6, LOW);
            }    
            if (header.indexOf("GET /D7/on") >= 0) {    //device 7
              Serial.println("D7 off");
              D7State = "on";
              digitalWrite(p7, HIGH);
            }
            else if (header.indexOf("GET /D7/off") >= 0) {
              Serial.println("D7 off");
              D7State = "off";
              digitalWrite(p7, LOW);
            }    
            if (header.indexOf("GET /D8/on") >= 0) {    //device 8
              Serial.println("D8 off");
              D8State = "on";
              digitalWrite(p8, HIGH);
            }
            else if (header.indexOf("GET /D8/off") >= 0) {
              Serial.println("D8 off");
              D8State = "off";
              digitalWrite(p8, LOW);
            }    
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: #ccffb3;}");
            client.println(".button { background-color: #006699; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 35px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
                           
            // Web Page Heading
            client.println("<body><h2>ESP server</h2>");
            client.println("<p>Device 1 State: " + D1State + "  ....    Device 5 State: " + D5State + "</p>");
            client.println("<p>Device 2 State: " + D2State + "  ....    Device 6 State: " + D6State + "</p>");
            client.println("<p>Device 3 State: " + D3State + "  ....    Device 7 State: " + D7State + "</p>");
            client.println("<p>Device 4 State: " + D4State + "  ....    Device 8 State: " + D8State + "</p>");

                                    
            // If the LED1State is off, it displays the ON button       
            if (D1State=="off") { //device 1
              client.println("<p><a href=\"/D1/on\"><button class=\"button\">turn on device 1</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/D1/off\"><button class=\"button button2\">turn off device 1</button></a></p>");
            }    
            if (D2State=="off") { //device 2
              client.println("<p><a href=\"/D2/on\"><button class=\"button\">turn on device 2</button></a></p>");
            }
            else {
              client.println("<p><a href=\"/D2/off\"><button class=\"button button2\">turn off device 2</button></a></p>");
            }    
            if (D3State=="off") { //device 3
              client.println("<p><a href=\"/D3/on\"><button class=\"button\">turn on device 3</button></a></p>");
            }
            else {
              client.println("<p><a href=\"/D3/off\"><button class=\"button button2\">turn off device 3</button></a></p>");
            }   
            if (D4State=="off") { //device 4
              client.println("<p><a href=\"/D4/on\"><button class=\"button\">turn on device 4</button></a></p>");
            }
            else {
              client.println("<p><a href=\"/D4/off\"><button class=\"button button2\">turn off device 4</button></a></p>");
            }     
            if (D5State=="off") { //device 5
              client.println("<p><a href=\"/D5/on\"><button class=\"button\">turn on device 5</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/D5/off\"><button class=\"button button2\">turn off device 5</button></a></p>");
             }     
            if (D6State=="off") { //device 6
              client.println("<p><a href=\"/D6/on\"><button class=\"button\">turn on device 6</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/D6/off\"><button class=\"button button2\">turn off device 6</button></a></p>");
             }    
            if (D7State=="off") { //device 7
              client.println("<p><a href=\"/D7/on\"><button class=\"button\">turn on device 7</button></a></p>");
            }
            else {
              client.println("<p><a href=\"/D7/off\"><button class=\"button button2\">turn off device 7</button></a></p>");
            }     
            if (D8State=="off") { //device 8
              client.println("<p><a href=\"/D8/on\"><button class=\"button\">turn on device 8</button></a></p>");
            } 
            else {
              client.println("<p><a href=\"/D8/off\"><button class=\"button button2\">turn off device 8</button></a></p>");
            }   
            
            client.println("</body></html>");
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected");
    Serial.println("");
    
}
