#include <WiFi.h>
#include <WebServer.h>

// Network credentials
const char* ssid = "premium";
const char* password = "edupremium";

// Web server running on port 80
WebServer server(80);

// Variables to store the current LED states
String statePin16 = "off";
String statePin17 = "off";
String statePin18 = "off";
String statePin19 = "off";
String statePin12 = "off";
String statePin13 = "off";
String statePin14 = "off";
String statePin15 = "off";
String statePin22 = "off";
String statePin23 = "off";
String statePin25 = "off";
String statePin26 = "off";

// Output variables to GPIO pins
const int ledPin16 = 16;
const int ledPin17 = 17;
const int ledPin18 = 18;
const int ledPin19 = 19;
const int ledPin12 = 12;
const int ledPin13 = 13;
const int ledPin14 = 14;
const int ledPin15 = 15;
const int ledPin22 = 22;
const int ledPin23 = 23;
const int ledPin25 = 25;
const int ledPin26 = 26;
const int ledAlarm21 = 21;

void handleRoot() {
  // Handle the GPIO states for each pin
  if (server.arg("LED16") == "on") {
    statePin16 = "on";
    digitalWrite(ledPin16, HIGH);
  } else if (server.arg("LED16") == "off") {
    statePin16 = "off";
    digitalWrite(ledPin16, LOW);
  }

  if (server.arg("LED17") == "on") {
    statePin17 = "on";
    digitalWrite(ledPin17, HIGH);
  } else if (server.arg("LED17") == "off") {
    statePin17 = "off";
    digitalWrite(ledPin17, LOW);
  }

  if (server.arg("LED18") == "on") {
    statePin18 = "on";
    digitalWrite(ledPin18, HIGH);
  } else if (server.arg("LED18") == "off") {
    statePin18 = "off";
    digitalWrite(ledPin18, LOW);
  }

  if (server.arg("LED19") == "on") {
    statePin19 = "on";
    digitalWrite(ledPin19, HIGH);
  } else if (server.arg("LED19") == "off") {
    statePin19 = "off";
    digitalWrite(ledPin19, LOW);
  }

  if (server.arg("LED12") == "on") {
    statePin12 = "on";
    digitalWrite(ledPin12, HIGH);
  } else if (server.arg("LED12") == "off") {
    statePin12 = "off";
    digitalWrite(ledPin12, LOW);
  }

  if (server.arg("LED13") == "on") {
    statePin13 = "on";
    digitalWrite(ledPin13, HIGH);
  } else if (server.arg("LED13") == "off") {
    statePin13 = "off";
    digitalWrite(ledPin13, LOW);
  }

  if (server.arg("LED14") == "on") {
    statePin14 = "on";
    digitalWrite(ledPin14, HIGH);
  } else if (server.arg("LED14") == "off") {
    statePin14 = "off";
    digitalWrite(ledPin14, LOW);
  }

  if (server.arg("LED15") == "on") {
    statePin15 = "on";
    digitalWrite(ledPin15, HIGH);
  } else if (server.arg("LED15") == "off") {
    statePin15 = "off";
    digitalWrite(ledPin15, LOW);
  }

  if (server.arg("LED22") == "on") {
    statePin22 = "on";
    digitalWrite(ledPin22, HIGH);
  } else if (server.arg("LED22") == "off") {
    statePin22 = "off";
    digitalWrite(ledPin22, LOW);
  }

  if (server.arg("LED23") == "on") {
    statePin23 = "on";
    digitalWrite(ledPin23, HIGH);
  } else if (server.arg("LED23") == "off") {
    statePin23 = "off";
    digitalWrite(ledPin23, LOW);
  }

  if (server.arg("LED25") == "on") {
    statePin25 = "on";
    digitalWrite(ledPin25, HIGH);
  } else if (server.arg("LED25") == "off") {
    statePin25 = "off";
    digitalWrite(ledPin25, LOW);
  }

  if (server.arg("LED26") == "on") {
    statePin26 = "on";
    digitalWrite(ledPin26, HIGH);
  } else if (server.arg("LED26") == "off") {
    statePin26 = "off";
    digitalWrite(ledPin26, LOW);
  }
    if (server.arg("ALL") == "on"){
    statePin16 = "on";
    statePin17 = "on";
    statePin18 = "on";
    statePin19 = "on";
    statePin12 = "on";
    statePin13 = "on";
    statePin14 = "on";
    statePin15 = "on";
    statePin22 = "on";
    statePin23 = "on";
    statePin25 = "on";
    statePin26 = "on";
    digitalWrite(ledPin16, HIGH);
    digitalWrite(ledPin17, HIGH);
    digitalWrite(ledPin18, HIGH);
    digitalWrite(ledPin19, HIGH);
    digitalWrite(ledPin12, HIGH);
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin14, HIGH);
    digitalWrite(ledPin15, HIGH);
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
  } else if (server.arg("ALL") == "off") {
    statePin16 = "off";
    statePin17 = "off";
    statePin18 = "off";
    statePin19 = "off";
    statePin12 = "off";
    statePin13 = "off";
    statePin14 = "off";
    statePin15 = "off";
    statePin22 = "off";
    statePin23 = "off";
    statePin25 = "off";
    statePin26 = "off";
    digitalWrite(ledPin16, LOW);
    digitalWrite(ledPin17, LOW);
    digitalWrite(ledPin18, LOW);
    digitalWrite(ledPin19, LOW);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin13, LOW);
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);

  }

  // Send the HTML response
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<link rel=\"icon\" href=\"data:,\">";
  html += "<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}";
  html += ".button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px;";
  html += "text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}";
  html += ".button2 {background-color: gray;}";
  html += ".region {display: inline-block; margin: 10px; text-align: center;}";
  html += ".all-buttons {text-align: center; margin-top: 20px;}</style></head>";

  html += "<body><h1>ESP32 Web Server</h1>";
  html += "<p>Control LED State</p>";
  html += "<p>By KELOMPOK 12B</p>";

  // Right region (Pins 16, 17, 18, 19)
  html += "<div class='region'><p>Right Region</p>";
  html += "<p>LED 16 - State: " + statePin16 + "</p>";
  html += "<p><a href=\"/?LED16=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED16=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 17 - State: " + statePin17 + "</p>";
  html += "<p><a href=\"/?LED17=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED17=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 18 - State: " + statePin18 + "</p>";
  html += "<p><a href=\"/?LED18=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED18=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 19 - State: " + statePin19 + "</p>";
  html += "<p><a href=\"/?LED19=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED19=off\"><button class=\"button button2\">OFF</button></a></p></div>";

  // Up region (Pins 12, 13, 14, 15)
  html += "<div class='region'><p>Up Region</p>";
  html += "<p>LED 12 - State: " + statePin12 + "</p>";
  html += "<p><a href=\"/?LED12=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED12=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 13 - State: " + statePin13 + "</p>";
  html += "<p><a href=\"/?LED13=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED13=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 14 - State: " + statePin14 + "</p>";
  html += "<p><a href=\"/?LED14=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED14=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 15 - State: " + statePin15 + "</p>";
  html += "<p><a href=\"/?LED15=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED15=off\"><button class=\"button button2\">OFF</button></a></p></div>";

  // Left region (Pins 22, 23, 25, 26)
  html += "<div class='region'><p>Left Region</p>";
  html += "<p>LED 22 - State: " + statePin22 + "</p>";
  html += "<p><a href=\"/?LED22=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED22=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 23 - State: " + statePin23 + "</p>";
  html += "<p><a href=\"/?LED23=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED23=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 25 - State: " + statePin25 + "</p>";
  html += "<p><a href=\"/?LED25=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED25=off\"><button class=\"button button2\">OFF</button></a></p>";

  html += "<p>LED 26 - State: " + statePin26 + "</p>";
  html += "<p><a href=\"/?LED26=on\"><button class=\"button\">ON</button></a>";
  html += "<a href=\"/?LED26=off\"><button class=\"button button2\">OFF</button></a></p></div>";

  // 'ALL ON' and 'ALL OFF' buttons
  html += "<div class='all-buttons'><p>Control All LEDs</p>";
  html += "<p><a href=\"/?ALL=on\"><button class=\"button\">ALL ON</button></a>";
  html += "<a href=\"/?ALL=off\"><button class=\"button button2\">ALL OFF</button></a></p></div>";

  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  // Initialize GPIOs as outputs
  pinMode(ledPin16, OUTPUT);
  pinMode(ledPin17, OUTPUT);
  pinMode(ledPin18, OUTPUT);
  pinMode(ledPin19, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin14, OUTPUT);
  pinMode(ledPin15, OUTPUT);
  pinMode(ledPin22, OUTPUT);
  pinMode(ledPin23, OUTPUT);
  pinMode(ledPin25, OUTPUT);
  pinMode(ledPin26, OUTPUT);
  pinMode(ledAlarm21, OUTPUT);

  // Set all initial LED states to off
  digitalWrite(ledPin16, LOW);
  digitalWrite(ledPin17, LOW);
  digitalWrite(ledPin18, LOW);
  digitalWrite(ledPin19, LOW);
  digitalWrite(ledPin12, LOW);
  digitalWrite(ledPin13, LOW);
  digitalWrite(ledPin14, LOW);
  digitalWrite(ledPin15, LOW);
  digitalWrite(ledPin22, LOW);
  digitalWrite(ledPin23, LOW);
  digitalWrite(ledPin25, LOW);
  digitalWrite(ledPin26, LOW);
  digitalWrite(ledAlarm21, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  digitalWrite(ledAlarm21, HIGH);
  delay(500);
  digitalWrite(ledAlarm21, LOW);
  delay(500);
  digitalWrite(ledAlarm21, HIGH);
  delay(500);
  digitalWrite(ledAlarm21, LOW);
  delay(500);
  digitalWrite(ledAlarm21, HIGH);
  delay(500);
  digitalWrite(ledAlarm21, LOW);
  delay(500);
  digitalWrite(ledAlarm21, HIGH);
  delay(1500);
  digitalWrite(ledAlarm21, LOW);

  // Start the server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledAlarm21, HIGH);
    delay(250);
    digitalWrite(ledAlarm21, LOW);
    delay(250);
  }
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(ledAlarm21, LOW);
  }
}
