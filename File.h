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
	static bool exists(const string &file);
	static bool isExtention(string haystack, string needle);
};

#endif /* FILE_H_ */
