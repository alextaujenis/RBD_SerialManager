// Arduino RBD Serial Manager Library v1.0.0-alpha.2 - A simple interface for serial communication.
// https://github.com/alextaujenis/RBD_SerialManager
// Copyright 2016 Alex Taujenis
// MIT License

#ifndef RBD_SERIAL_MANAGER
#define RBD_SERIAL_MANAGER

#include <Arduino.h>

namespace RBD {
  class SerialManager {
    public:
      void start();
      void setFlag(char value);
      void setDelimiter(char value);
      bool onReceive();
      String getValue();
      String getCmd();
      String getParam();
      bool isCmd(String value);
      bool isParam(String value);
      template <typename T> void print(T value){Serial.print(value);}
      template <typename T> void println(T value){Serial.println(value);}
    private:
      int _position;
      char _char;
      char _flag      = ';';
      char _delimiter = ',';
      String _buffer  = "";
      String _value   = "";
  };
}

#endif