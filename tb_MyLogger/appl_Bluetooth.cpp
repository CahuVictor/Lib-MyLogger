#include "appl_Bluetooth.h"
#include "config.h"

#ifdef USE_BLUETOOTH_HC06
  // Implementação da classe HC06
  HC06::HC06(int rxPin, int txPin) : btSerial(rxPin, txPin) {}
  
  void HC06::begin(int baudRate) {
      btSerial.begin(baudRate);
  }
  
  void HC06::send(const String &message) {
      btSerial.print(message);
  }
  
  void HC06::send(char message) {
      btSerial.print(message);
  }
  
  bool HC06::available() {
      return btSerial.available();
  }
  
  char HC06::read() {
      return btSerial.read();
  }

  // Funcoes adicionadas para tornar a funcao MyLogger mais versatil
    // Implementação da interface Print
    size_t HC06::write(uint8_t byte) {  // Não Funcionou
      return btSerial.write(byte);
    }

    Print* HC06::getPrintInterface() {
      return &btSerial;  // Retorna a instância de SoftwareSerial
    }

#endif

#if defined(ESP32)
  // Implementação da classe ESP32Bluetooth
  ESP32Bluetooth::ESP32Bluetooth(const char* deviceName) {
      // Inicializa BluetoothSerial com o nome do dispositivo
      SerialBT.begin(deviceName);
  }
  
  void ESP32Bluetooth::begin(int baudRate) {
      // O ESP32 BluetoothSerial não precisa de baud rate, mas mantemos a função para compatibilidade
      // Você pode usar o baud rate para configurações adicionais se necessário
      // Por exemplo, SerialBT.begin() já foi chamado no construtor
  }
  
  void ESP32Bluetooth::send(const String &message) {
      SerialBT.print(message);
  }
  
  void ESP32Bluetooth::send(char message) {  // Implementação da função para char
      SerialBT.print(message);
  }
  
  bool ESP32Bluetooth::available() {
      return SerialBT.available();
  }
  
  char ESP32Bluetooth::read() {
      return SerialBT.read();
  }

  // Funcoes adicionadas para tornar a funcao MyLogger mais versatil
    // Implementação da interface Print
    size_t ESP32Bluetooth::write(uint8_t byte) {  // Não Funcionou
      return SerialBT.write(byte);
    }

    Print* ESP32Bluetooth::getPrintInterface() {
      return &SerialBT;  // Retorna a instância de BluetoothSerial
    }

#endif
