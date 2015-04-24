/*
 * QB.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#include "QB.h"

#include <vector>

#define bswap(a) __asm("bswap %0\n" : "=q"(a) : "0"(a) : "0");

vector<QB_Name> names;

QB::QB() {
	// TODO Auto-generated constructor stub

}

QB::~QB() {
	// TODO Auto-generated destructor stub
}

bool QB::compile(const char* input, const char* output) {


	return false;
}

bool QB::decompile(const char* input, const char* output) {

	File* file = new File();

	if (!file->open(input, "rb")) {
		Log::error("Could not open file \"%s\"!", input);
		return false;
	}

	// while we are not at the end of the file
	while (!file->eof()) {

		// attempt to read an instruction
		unsigned char byte = file->readByte();

		// we have an instruction
		if (byte == QB_INSTRUCT) {
			// read the next byte to figure out what we are trying to do
			unsigned char inst_byte = file->readByte();

			// switch over the possible options
			switch (inst_byte) {
			case QB_HASH:

				// create QB_Name
				QB_Name qb_name;
				// read the ID
				qb_name.id = *file->read(4);
				// swap byte order
				bswap(qb_name.id);

				// push into list
				names.push_back(qb_name);
				break;
			}
		}
		else if (byte == QB_HASH) {
			// create QB_Name
			QB_Name qb_name;
			// read the ID
			qb_name.id = *file->read(4);
			// swap byte order
			bswap(qb_name.id);

			// push into list
			names.push_back(qb_name);
		}
		else if (byte == QB_SYMBOL) {
			uint32_t id = *file->read(4);
			// swap byte order
			bswap(id);

			for (vector<QB_Name>::iterator i = names.begin(); i != names.end(); ++i) {
				QB_Name q = *i;
				if (q.id == id) {
					q.name = file->readString();
					Log::info("Match found! (%s)", q.toString());
					break;
				}
				// *i = q;
			}
		}

		// log byte
		// Log::info("Read: 0x%.2X @%i", byte, file->getPosition());
	}

	Log::info("End of file...");

	return true;
}
