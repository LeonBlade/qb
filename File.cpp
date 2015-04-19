/*
 * File.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#include "File.h"
#include "Log.h"

#ifndef _WIN32
#include <sys/stat.h>
#endif
#include <algorithm>

string File::getExtension(const string &str) {
	size_t l = str.find_last_of('.');
	return str.substr(l + 1);
}

bool File::exists(const string &filename) {

#ifdef _WIN32
	Log::debug("Using fopen() to check for file exist.");
		if (FILE *file = fopen(filename.c_str(), "r")) {
			fclose(file);
			return true;
		}
		else
			return false;
#else
	Log::debug("Using stat() to check for file exist.");
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
#endif

	return false;
}

bool File::isExtention(string haystack, string needle) {
	string extension = File::getExtension(haystack);

	// strtolower
	transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
	transform(needle.begin(), needle.end(), needle.begin(), ::tolower);

	return (extension == needle);
}

