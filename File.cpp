/*
 * File.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#include "File.h"

#ifdef _WIN32
#include <sys/stat.h>
#endif
#include <algorithm>

string File::getExtension(const string &str) {
	size_t l = str.find_last_of('.');
	return str.substr(l + 1);
}

bool File::exists(const string &filename) {

#ifdef _SYS_STAT_H_
	struct stat buffer;
	return (stat(file, &buffer) == 0);
#else
	if (FILE *file = fopen(filename.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else
		return false;
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

