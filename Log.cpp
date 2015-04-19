/*
 * Log.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#define __DEBUG__

#include "Log.h"

void Log::info(const char* message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_INFO, message, args);
	va_end(args);
}

void Log::warning(const char* message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_WARN, message, args);
	va_end(args);
}

void Log::error(const char* message, ...) {
	va_list args;
	va_start(args, message);
	Log::log(LOG_ERR, message, args);
	va_end(args);
}

void Log::debug(const char* message, ...) {
#ifdef __DEBUG__
	va_list args;
	va_start(args, message);
	Log::log(LOG_BUG, message, args);
	va_end(args);
#endif
}

void Log::log(LogType type, const char* message, va_list args) {
	if (type == LOG_WARN)
		printf("[WARN] ");
	else if (type == LOG_ERR)
		printf("[ERROR] ");
	else if (type == LOG_BUG)
		printf("[DEBUG] ");

	va_list _args;
	size_t size;
	char *buffer;

	va_copy(_args, args);
	size = vsnprintf(NULL, 0, message, _args) + 1;
	va_end(_args);

	buffer = (char*) malloc(size);

	if (!buffer) {
		printf("[ERROR] Buffer NULL logging message \"%s\"\n", message);
		return;
	}

	vsnprintf(buffer, size, message, args);
	printf("%s\n", buffer);
}

