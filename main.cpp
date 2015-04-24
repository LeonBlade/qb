/*
 * main.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#include "QB.h"
#include "Log.h"
#include "File.h"

using namespace std;

// usage message for program
void usage() {
	Log::info("\nUsage: [-c -d] input [output]");
	Log::info("Options:");
	Log::info("  [-c] Optional flag, compile source into QB script");
	Log::info("  [-d] Optional flag, decompile QB script into source");
	Log::info("Files:");
	Log::info("  [input] Your input file to be compiled or decompiled");
	Log::info("  [output] Optional file output to write to");
}

int main(int argc, char* argv[]) {

	Log::info("THUG 2 QB (De)Compiler (v0.1) by LeonBlade");

	// invalid amount of arguments
	if (argc < 2) {
		Log::error("Invalid amount of arguments!");
		usage();

		return 1;
	}
	// too many arguments
	if (argc > 4) {
		Log::error("Too many inputs!");
		usage();

		return 1;
	}

	// variables
	char flag;
	string input;
	string output;

	// Usage: qb filename
	if (argc == 2) {
		input = argv[1];
		// getting flag from extension type
		if (File::isExtention(input, "qb"))
			flag = 'd';
		else
			flag = 'c';
	}

	// Usage: qb [-c -d] input
	// Usage: qb input output
	if (argc == 3) {
		// flag determined from input
		if (argv[1][0] == '-' && (argv[1][1] == 'c' || argv[1][1] == 'd')) {
			flag = argv[1][1];
			input = argv[2];
		}
		else {
			input = argv[1];
			output = argv[2];
			// getting flag from extension type
			if (File::isExtention(input, "qb"))
				flag = 'd';
			else
				flag = 'c';
		}
	}

	// Usage: qb [-c -d] input output
	if (argc == 4) {
		if (argv[1][0] == '-' && (argv[1][1] == 'c' || argv[1][1] == 'd')) {
			flag = argv[1][1];
		}
		else {
			Log::error("Invalid flag!");
			usage();

			return 1;
		}

		input = argv[2];
		output = argv[3];
	}

	// input error checking
	if (flag == 0 || input.empty()) {
		Log::error("Invalid arguments!");
		usage();

		return 1;
	}

	// does the input file exist
	if (!File::exists(input)) {
		Log::error("Input file '%s' does not exist!", input.c_str());

		return 1;
	}

	// new QB file
	QB* qb = new QB();

	// check against flags
	if (flag == 'c') {
		Log::info("Compiling \"%s\" ...", input.c_str());
	}
	else if (flag == 'd') {
		Log::info("Decompiling \"%s\" ...", input.c_str());
		qb->decompile(input.c_str(), output.c_str());
	}
	else {
		Log::error("Invalid flag!");
		usage();

		return 1;
	}

	Log::info("Done!");

	return 0;
}
