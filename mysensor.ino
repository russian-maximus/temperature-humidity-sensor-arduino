/**
 * @file Standard.ino
 * @brief Standard Sketch that uses the HomeDing Library to implement Things attached the
 * Internet.
 * The use-case covered with this Sketch is to compile a full featured firmware
 * with the most common and not too execeptional elements for a devices with 4MByte flash like
 * * full featured environment sensors
 * * ...
 * All elements from the minimal sketch are included by default.
 *
 * Compile with
 * * Board: NodeMCU 1.0
 * * Flash Size: 4M (FS:2MB, OTA:~1019KB)
 * * Debug Port: "Serial"
 * * Debug Level: "None"
 * * MMU: 32+32 balanced
 *
 * There is full featured WebUI available in the data folder.
 *
 * @author Matthias Hertel, https://www.mathertel.de
 *
 * @Copyright Copyright (c) by Matthias Hertel, https://www.mathertel.de.
 *
 * This work is licensed under a BSD 3-Clause style license,
 * https://www.mathertel.de/License.aspx.
 *
 * More information on https://www.mathertel.de/Arduino
 * and https://homeding.github.io/index.htm#page=/examples/develop.md.
 *
 * Changelog:
 * * 12.11.2019 Standard Example created from development sketch.
 * * 15.04.2020 fixed library dependencies.
 * * 15.06.2021 usable with esp8266 board manager version >= 3.0.0
 */

// ----- activatable debug options

// #define NET_DEBUG

// ===== HomeDing Configuration : Enable Elements for the firmware

#define HOMEDING_REGISTER 1

// Enable the following element groups of the HomeDing Library
#define HOMEDING_INCLUDE_SYSTEM
#define HOMEDING_INCLUDE_CORE
#define HOMEDING_INCLUDE_FULL_SYSTEM

// Enable some Common Sensor Elements
#define HOMEDING_INCLUDE_DHT
#define HOMEDING_INCLUDE_DALLAS

// Enable / Disable some more Sensor Elements upon requirement
#define HOMEDING_INCLUDE_AM2320
#define HOMEDING_INCLUDE_SHT20
#define HOMEDING_INCLUDE_AHT20
#define HOMEDING_INCLUDE_BME680
#define HOMEDING_INCLUDE_BH1750

// The PMS uses SoftwareSerial Library that requires more IRAM.
// When using, please switch the MMU: Options to give more IRAM
// #define HOMEDING_INCLUDE_PMS

// Enable some INPUT Elements
#define HOMEDING_INCLUDE_ROTARY
#define HOMEDING_INCLUDE_MENU

// Enable some TIME Elements
#define HOMEDING_INCLUDE_DSTIME

// Enable Elements for Displays
#define HOMEDING_INCLUDE_DISPLAY
#define HOMEDING_INCLUDE_DISPLAYLCD
#define HOMEDING_INCLUDE_DISPLAYSSD1306
#define HOMEDING_INCLUDE_DISPLAYSH1106
// eneble these lines to get more displays supported
// #define HOMEDING_INCLUDE_DISPLAYST7789
// #define HOMEDING_INCLUDE_DISPLAYMAX7219
// #define HOMEDING_INCLUDE_TM1637

// Enable Elements for LIGHT control
#define HOMEDING_INCLUDE_COLOR
#define HOMEDING_INCLUDE_LIGHT
#define HOMEDING_INCLUDE_NEOPIXEL
#define HOMEDING_INCLUDE_MY9291

// Network Services
#define HOMEDING_INCLUDE_MQTT
#define HOMEDING_INCLUDE_WEATHERFEED

#include <Arduino.h>
#include <HomeDing.h>

#include <FS.h>        // File System for Web Server Files
#include <LittleFS.h>  // File System for Web Server Files

#include <BuiltinHandler.h>  // Serve Built-in files
#include <BoardServer.h>     // Web Server Middleware for Elements
#include <FileServer.h>      // Web Server Middleware for UI


// ===== WLAN credentials =====

#include "secrets.h"

// WebServer on port 80 to reach Web UI and services
WebServer server(80);

// ===== implement =====

/**
 * Setup all components and Serial debugging helpers
 */
void setup(void) {
  Serial.begin(115200);

#if defined(NET_DEBUG)
  Serial.setDebugOutput(true);
#else
  Serial.setDebugOutput(false);
#endif

  // ----- setup the platform with webserver and file system -----

  homeding.init(&server, &LittleFS, "standard");

  // ----- adding web server handlers -----

  // Builtin Files
  server.addHandler(new BuiltinHandler(&homeding));

  // Board status and actions
  server.addHandler(new BoardHandler(&homeding));

  // UPLOAD and DELETE of static files in the file system.
  server.addHandler(new FileServerHandler(&homeding));

  LOGGER_INFO("setup done");
}  // setup


// handle all give time to all Elements and active components.
void loop(void) {
  server.handleClient();
  homeding.loop();
}  // loop()


// end.
