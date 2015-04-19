/*
 * Log.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#include "Log.h"

void Log::info(const char *message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_INFO, message, args);
	va_end(args);
}

void Log::warning(const char *message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_WARN, message, args);
	va_end(args);
}

void Log::error(const char *message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_ERR, message, args);
	va_end(args);
}

void Log::log(LogType type, const char *message, va_list args) {
	if (type == LOG_INFO)
		printf("[INFO] %s\n", message);
	else if (type == LOG_WARN)
		printf("[WARN] %s\n", message);
	else if (type == LOG_ERR)
		printf("[ERROR] %s\n", message);
}

