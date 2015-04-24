/*
 * File.h
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>

using namespace std;

class File {
public:
	static string getExtension(const string &str);
	static bool exists(const string &filename);
	static bool isExtention(string haystack, string needle);

	File();
	virtual ~File();

	bool open(const char* file, const char* mode);
	uintptr_t* read(size_t bytes);
	uint8_t readByte();
	const char* readString();
	long getPosition();

	bool eof();
private:
	FILE* file;
	long size;
	long position;
	void* buffer;
};

#endif /* FILE_H_ */
