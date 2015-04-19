/*
 * Log.h
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

enum LogType {
	LOG_INFO,
	LOG_WARN,
	LOG_ERR
};

class Log {
public:
	static void info(const char* message, ...);
	static void warning(const char* message, ...);
	static void error(const char* message ...);

private:
	static void log(LogType type, const char* message, va_list args);
};

#endif /* LOG_H_ */
