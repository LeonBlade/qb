/*
 * QB.h
 *
 *  Created on: Apr 19, 2015
 *      Author: LeonBlade
 */

#ifndef QB_H_
#define QB_H_

#include "Log.h"

#include <string>

using namespace std;

enum QB_OpCode {
	QB_SCRIPT_END = 0x00,
	QB_INSTRUCT = 0x01,
	QB_EOLN = 0x02,
	QB_STRUCT = 0x03,
	QB_STRUCT_END = 0x04,
	QB_ARRAY = 0x05,
	QB_ARRAY_END = 0x06,
	QB_EQUALS = 0x07,
	QB_ARROW = 0x08,
	QB_COMMA = 0x09,
	QB_MINUS = 0x0A,
	QB_PLUS = 0x0B,
	QB_MULTIPLY = 0x0C,
	QB_DIVIDE = 0x0D,
	QB_OPEN = 0x0E,
	QB_CLOSE = 0x0F,
	QB_EQUALTO = 0x11,
	QB_LT = 0x12,
	QB_LTE = 0x13,
	QB_GT = 0x14,
	QB_GTE = 0x15,
	QB_HASH = 0x16,
	QB_LONG = 0x17,
	QB_HEX = 0x18,
	QB_ENUM = 0x19,
	QB_FLOAT = 0x1A,
	QB_STRING = 0x1B,
	QB_FMT_STRING = 0x1C,
	QB_VECTOR3 = 0x1E,
	QB_VECTOR2 = 0x1F,
	QB_WHILE = 0x20,
	QB_REPEAT = 0x21,
	QB_CONTINUE = 0x22,
	QB_FUNC = 0x23,
	QB_FUNC_END = 0x24,
	QB_IF2 = 0x25,
	QB_ELSE2 = 0x26,
	QB_ELSE_IF = 0x27,
	QB_END_IF = 0x28,
	QB_RETURN = 0x29,
	QB_SYMBOL = 0x2B,
	QB_NULL = 0x2C,
	QB_ARGS = 0x2D,
	QB_JUMP = 0x2E,
	QB_RANDOM1 = 0x2F,
	QB_RANDOMR = 0x30,
	QB_OR = 0x32,
	QB_AND = 0x33,
	QB_SHIFT_LEFT = 0x35,
	QB_SHIFT_RIGHT = 0x36,
	QB_RANDOM2 = 0x37,
	QB_RANDOMR2 = 0x38,
	QB_NOT = 0x39,
	QB_AND2 = 0x3A,
	QB_OR2 = 0x3B,
	QB_SWITCH = 0x3C,
	QB_SWITCH_END = 0x3D,
	QB_CASE = 0x3E,
	QB_DEFAULT = 0x3F,
	QB_RANDOM3 = 0x40,
	QB_RANDOM4 = 0x41,
	QB_DOT = 0x42,
	QB_IF = 0x47,
	QB_ELSE = 0x48,
	QB_BREAK = 0x49
};

struct QB_Instruction {
	uint8_t op = QB_INSTRUCT;
};

struct QB_Symbol {
	unsigned int id;
	string name;

	void generateID() {
		Log::debug("TODO: implement generateID() for QB_Symbol struct");
	}
};

struct QB_Array {

};

struct QB_Struct {

};

class QB {
public:
	QB();
	virtual ~QB();
};

#endif /* QB_H_ */
