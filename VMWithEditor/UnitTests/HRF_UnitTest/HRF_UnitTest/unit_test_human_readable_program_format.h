#ifndef UNIT_TEST_HUMAN_READABLE_PROGRAM_FORMAT_H
#define UNIT_TEST_HUMAN_READABLE_PROGRAM_FORMAT_H
// Unit tests that can be called from main.

#include <stdbool.h>

extern bool unit_test_hrf_duplicate_program(unsigned test_step);
extern bool unit_test_hrf_create_program_step(unsigned test_step);
extern bool unit_test_hrf_convert_array_program_to_linked_list(unsigned test_step);
extern bool unit_test_hrf_convert_link_list_program_to_array(unsigned test_step);
extern bool unit_test_all_human_readable_format();
extern void write_to_test_log_file(char* buffer);

#endif
