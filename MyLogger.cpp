#include "MyLogger.h"

void MyLogger::logMessageFunc(Print* interface, int level, const char* message, const char* func, int line) {
  char log[256];
  snprintf(log, sizeof(log), "[%lu ms] | %s | %s:%d | %s",
           millis(),
           (level == DEBUG) ? "DEBUG" : (level == INFO) ? "INFO" : (level == WARNING) ? "WARNING" : "ERROR",
           func,
           line,
           message);

  logToInterface(interface, log);
}

void MyLogger::logToInterface(Print* interface, const char* log) {
  if (interface != nullptr) {
    interface->println(log);
  }
}
