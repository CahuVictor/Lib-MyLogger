#include "MyLogger.h"
#include "appl_Bluetooth.h"
#include "config.h"
#include <SD.h>

File updateFile;

#define BT_TX 9
#define BT_RX 10

BluetoothInterface* btModule = new HC06(BT_RX, BT_TX);
//HC06 btModule(BT_RX, BT_TX);  // Instância da interface Bluetooth

void setup() {
  Serial.begin(9600);
  btModule->begin(9600);

  if (SD.begin(10)) {  // CS pin 10
    updateFile = openLogFile();
  } else {
    Serial.println("Falha ao iniciar o cartão SD");
  }
  
  delay(1000);

  LOG_INFO(&Serial,"Sistema inicializado com Interface Serial PC");
  //LOG_INFO(&btModule.btSerial,"Sistema inicializado com Interface Serial Bluetooth"); // Não Funcionou
  //LOG_INFO(static_cast<Print*>(btModule),"Sistema inicializado com Interface Serial Bluetooth"); // Não Funcionou
  //LOG_INFO(btModule,"Sistema inicializado com Interface Serial Bluetooth"); // Não Funcionou
  LOG_INFO(btModule->getPrintInterface(),"Sistema inicializado com Interface Serial Bluetooth");

  updateFile = openLogFile();
  LOG_INFO(&updateFile, "Sistema inicializado com saída para SD Card");
  updateFile.close();
}

void loop() {
  LOG_DEBUG(&Serial,"Loop test Interface Serial PC");
  //LOG_DEBUG(&btModule.btSerial,"Loop test Interface Bluetooth"); // Não Funcionou
  //LOG_DEBUG(static_cast<Print*>(btModule),"Loop test Interface Bluetooth"); // Não Funcionou
  //LOG_DEBUG(btModule,"Loop test Interface Bluetooth"); // Não Funcionou
  LOG_DEBUG(btModule->getPrintInterface(),"Loop test Interface Bluetooth");
  updateFile = openLogFile();
  LOG_INFO(&updateFile, "Log de teste para SD Card");
  updateFile.close();
  delay(1000);
}

// Função para abrir e retornar o arquivo de log
File openLogFile() {
  File logFile = SD.open("log.txt", FILE_WRITE);  // Abre o arquivo para adicionar conteúdo
  if (!logFile) {
    LOG_ERROR(&Serial, "Erro ao abrir o arquivo log.txt");
    //return NULL;
  }
  return logFile;  // Retorna o arquivo aberto
}
