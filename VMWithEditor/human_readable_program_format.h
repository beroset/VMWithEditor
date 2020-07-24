/* 
 * human_readable_program_format.h
 * Provides the API for using the Human Readable Programing Format (assembly language for the virtual machine).
 * A program consists of assembly language instructions of the format '{' OPCODE ',' OPERAND '}' [','].
 * Unfortunately due to the simple nature of the parser all instructions require an OPCODE OPERAND pair.
 * A program can be either a linked list of Program_Step_Nodes or an array of Human_Readable_Program_Format.
 * The ability to convert from aaray to linked list and back again is provided.
 */
#ifndef HUMAN_READABLE_PROGRAM_FORMAT_H
#define HUMAN_READABLE_PROGRAM_FORMAT_H

#include "opcode.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t OperandType;

typedef struct human_readable_program_format {
	OPCODE opcode;
	OperandType operand;
} Human_Readable_Program_Format;

typedef struct program_step_node
{
	Human_Readable_Program_Format opcode_and_operand;
	struct program_step_node* next_step;
} Program_Step_Node;

extern Human_Readable_Program_Format* duplicate_program(Human_Readable_Program_Format* program, size_t program_size);
extern Program_Step_Node* create_program_step(Human_Readable_Program_Format* user_input);
extern Human_Readable_Program_Format* convert_link_list_program_to_array(Program_Step_Node* linked_program, size_t program_size);
extern Program_Step_Node* convert_array_program_to_linked_list(Human_Readable_Program_Format* array_program, size_t program_size);
extern void delete_linked_list_of_program_steps(Program_Step_Node* linked_list_of_program_steps);
extern Program_Step_Node* hrf_check_line_syntax_return_program_step_if_valid(unsigned char* text_line, size_t* line_number, char* file_name);

#ifdef UNIT_TESTING
#include "unit_test_human_readable_program_format.h"
#endif	// UNIT_TESTING

#endif
