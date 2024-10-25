#ifndef APPL_BLUETOOTH_H
  #define APPL_BLUETOOTH_H

  #include <Arduino.h>  // Inclui as definições principais do Arduino, incluindo String
  #include "config.h"
  
  class BluetoothInterface {
  public:
      virtual void begin(int baudRate) = 0;
      virtual void send(const String &message) = 0;
      virtual void send(char message) = 0;
      virtual bool available() = 0;
      virtual char read() = 0;

      // Funcoes adicionadas para tornar a funcao MyLogger mais versatil
        // Implementação da função write exigida pela classe Print
        virtual size_t write(uint8_t byte) = 0;  // Não Funcionou
  
        virtual Print* getPrintInterface() = 0;  // Novo método
  };

  #ifdef USE_BLUETOOTH_HC06
    #include <SoftwareSerial.h>
    
    class HC06 : public BluetoothInterface/*, public Print*/ {
    public:
        HC06(int rxPin, int txPin);
    
        void begin(int baudRate) override;
    
        void send(const String &message) override;
        void send(char message) override;
    
        bool available() override;
    
        char read() override;

        // Funcoes adicionadas para tornar a funcao MyLogger mais versatil
          // Implementação da interface Print
          size_t write(uint8_t byte) override;  // Função exigida pela classe Print  // Não Funcionou
  
          Print* HC06::getPrintInterface() override;
    
    private:
        SoftwareSerial btSerial;
    };
  #endif
  
  #ifdef USE_BLUETOOTH_ESP32
    #include <BluetoothSerial.h>
    
    class ESP32Bluetooth : public BluetoothInterface/*, public Print*/ {
    public:
        ESP32Bluetooth(const char* deviceName = "ESP32_BT");
        
        void begin(int baudRate) override;
        void send(const String &message) override;
        void send(char message) override;  // Implementação da sobrecarga
        bool available() override;
        char read() override;

        // Funcoes adicionadas para tornar a funcao MyLogger mais versatil
          // Implementação da interface Print
          size_t write(uint8_t byte) override;  // Não Funcionou
  
          Print* ESP32Bluetooth::getPrintInterface() override;
    
    private:
        BluetoothSerial SerialBT;
    };
  #endif

#endif
