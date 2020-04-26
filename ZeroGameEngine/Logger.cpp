#include <stdarg.h>
#include <stdio.h>
#include <string>

#include "Defines.h"
#include "Logger.h"

namespace ZEROGE {

	static void writeLog(const char* prepend, const char* message, va_list args ) {
		vprintf((std::string(prepend) + message + "\n").c_str(), args);

	}

	void Logger::Trace(const char* message, ...) {
		va_list args;
		va_start(args, message);
		writeLog("[ TRACE ] => ", message, args);
		va_end(args);
	}
	void Logger::Log(const char* message, ...) {
		va_list args;
		va_start(args, message);
		writeLog("[ Log ] => ", message, args);
		va_end(args);

	}
	void Logger::Warn(const char* message, ...) {
		va_list args;
		va_start(args, message);
		writeLog("[ Warning ] => ", message, args);
		va_end(args);

	}

	void Logger::Error(const char* message, ...) {
		va_list args;
		va_start(args, message);
		writeLog("[ Error ] => ", message, args);
		va_end(args);

	}
	void Logger::Fatal(const char* message, ...) {
		va_list args;
		va_start(args, message);
		writeLog("[ Fatal ] => ", message, args);
		va_end(args);

		ASSERT(false);
	}
	
}