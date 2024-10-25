#ifndef __MyLogger_h__
	#define __MyLogger_h__

	#include "Arduino.h"

	#define __DEBUG   4
	#define __INFO    3
	#define __WARNING 2
	#define __ERROR   1

	#define LOG_DEBUG(interface, message)   MyLogger::logMessageFunc(interface, __DEBUG, message, __FUNCTION__, __LINE__)
  #define LOG_INFO(interface, message)    MyLogger::logMessageFunc(interface, __INFO, message, __FUNCTION__, __LINE__)
  #define LOG_WARNING(interface, message) MyLogger::logMessageFunc(interface, __WARNING, message, __FUNCTION__, __LINE__)
  #define LOG_ERROR(interface, message)   MyLogger::logMessageFunc(interface, __ERROR, message, __FUNCTION__, __LINE__)

  class MyLogger {
    public:
      static void logMessageFunc(Print* interface, int level, const char* message, const char* func, int line);
  
    private:
      static void logToInterface(Print* interface, const char* log);
  };

#endif
