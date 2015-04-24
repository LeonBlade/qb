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

File::File() {
	this->buffer = NULL;
	this->file = NULL;
	this->size = 0;
	this->position = 0;
}

File::~File() {
	fclose(this->file);
}

bool File::open(const char* filename, const char* mode) {
	this->file = fopen(filename, mode);
	fseek(this->file, 0, SEEK_END);
	this->size = ftell(this->file);
	rewind(this->file);

	return (this->file != NULL);
}

uintptr_t* File::read(size_t size) {
	this->buffer = (uintptr_t*) malloc(size);
	size_t result = fread(this->buffer, size, 1, this->file);
	// return the buffer if we read in an element otherwise return NULL to avoid returning what was last in the buffer
	return (result > 0) ? (uintptr_t*)this->buffer : NULL;
}

uint8_t File::readByte() {
	return (uint8_t) *this->read(1);
}

const char* File::readString() {
	char buf = 0;
	size_t size = 0;
	do {
		fread(&buf, 1, 1, this->file);
		size++;
	} while (buf != '\0');
	// rewind bytes
	fseek(this->file, -size, SEEK_CUR);
	const char* str = (const char*) this->read(size);
	return str;
}

bool File::eof() {
	return (this->size <= this->getPosition());
}

long File::getPosition() {
	return ftell(this->file);
}
