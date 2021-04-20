/*  Please add http://arduino.esp8266.com/stable/package_esp8266com_index.json 
 *  to the "Additional boards manager URLs" in Preference 
 *  Then add ESP8266 in "Boards Manager"
 *  Install https://github.com/tzapu/WiFiManager by add .Zip Library
 *  
 *          Petoi WiFi module Config 
 *  Module name: ESP-WROOM-02D / 4MB Flash
 *  Board: Generic ESP8266 Module
 *  Built-in LED: IO2 (Pin 2)
 *  Upload speed 921600 (may downgrade to half automatically)
 *  CPU Frequency: 80MHz (Power saving, lower heat) / 160MHz (High performance)
 *  Crystal: 26MHz
 *  Flash size: 4MB (FS:2MB / OTA:1019KB recommend) 
 *  Flash mode: DQOUT (Compatible)
 *  Flash frequency: 40MHz
 *  Others: Default
 *  
 *  Connecting the WiFi dongle to the serial programmer, search and connect "Bittle-AP" in WiFi
 *  The setup page should pop up directly, or you may visit 192.168.4.1 
 *  Set up the connection to your router 
 *  Check the IP address assigned to the WiFi module, then you can visit the server by your web browser.
 */

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
#include <ArduinoJson.h>

#include "commons.h"
#include "mainpage.h"
#include "actionpage.h"
#include "calibrationpage.h"

#define BUILTIN_LED 2

ESP8266WebServer server(80);

String PROGMEM renderHtml(String body, String title) {
  String page;
  page += FPSTR(head);
  page.replace(FPSTR("%TITLE%"), title);
  page += body;
  page += FPSTR(foot);
  return page;
}

void handleMainPage() {
  server.send(200, "text/html", renderHtml(FPSTR(mainpage), "Home"));
}

void handleActionPage() {
  if (server.hasArg("cmd")) {
    Serial.print(server.arg("cmd"));
  }
  server.send(200, "text/html", renderHtml(FPSTR(actionpage), "Actions"));
}

void handleCommand() {
  StaticJsonDocument<30> data;
  DeserializationError error = deserializeJson(data, server.arg("plain"));
  
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  const String cmd = data["cmd"];

  if (cmd == "cycle") {
    Serial.print("s");
    delay(500);
    Serial.print("ksit");
    delay(2000);
    Serial.print("kbalance");
    delay(2000);
    Serial.print("c");
  }
  
  Serial.print(cmd);
  server.send(200);
}

void handleCalibrationPage() {
  server.send(200, "text/html", renderHtml(FPSTR(calibrationpage), "Calibration"));
  Serial.print("c");
}

void handleSerialOutput() {
  if (Serial.available() > 0) {
    String output;
    output += Serial.read();
    server.send(200, "text/plain", output);
  } else {
    server.send(204);
  }
}

void setup(void) {

  // Serial and GPIO LED
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);

  // WiFiManager
  WiFiManager wifiManager;

  // Start WiFi manager, default gateway IP is 192.168.4.1
  wifiManager.autoConnect("Bittle-AP");
  digitalWrite(BUILTIN_LED, HIGH);      // While connected, LED lights

  // Print the IP get from DHCP Server of your Router
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // HTTP server started with handlers
  server.on("/", handleMainPage);
  server.on("/commander", handleCommand);
  server.on("/actions", handleActionPage);
  server.on("/calibrationpage", handleCalibrationPage);
  server.on("/getOutput", handleSerialOutput);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  // handle clients
  server.handleClient();
}
