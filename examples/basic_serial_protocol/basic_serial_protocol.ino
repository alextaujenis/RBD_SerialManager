// Arduino RBD Serial Manager Library v1.0.0-alpha.1 Example - Receive, parse, then echo characters back to serial output.
// https://github.com/alextaujenis/RBD_SerialManager
// Copyright 2015 Alex Taujenis
// MIT License

#include <RBD_SerialManager.h> // https://github.com/alextaujenis/RBD_SerialManager

RBD::SerialManager serial_manager;

void setup() {
  serial_manager.start();
}

void loop() {
  if(serial_manager.onReceive()) {
    // example serial command: hello world;
    Serial.println(serial_manager.getValue());
  }
}