// Arduino RBD Serial Manager Library v1.0.0-alpha.1 Example - Control the rotation of a servo with serial commands: up; down; move,90;
// https://github.com/alextaujenis/RBD_SerialManager
// Copyright 2015 Alex Taujenis
// MIT License

#include <RBD_SerialManager.h> // https://github.com/alextaujenis/RBD_SerialManager
#include <RBD_Servo.h>         // https://github.com/alextaujenis/RBD_Servo

RBD::SerialManager usb;
RBD::Servo servo(2, 700, 2300); // digital pin 2, 700ms - 2300ms pulse range

void setup() {
  usb.start();
}

void loop() {
  servo.update();

  if(usb.onReceive()) {
    // example serial command: up;
    if(usb.isCmd("up")) {
      servo.moveToDegrees(180);
    }

    // example serial command: down;
    else if(usb.isCmd("down")) {
      servo.moveToDegrees(0);
    }

    // example serial command: move,90;
    else if(usb.isCmd("move")) {
      int _position = usb.getParam().toInt();
      servo.moveToDegrees(_position);
    }
  }
}