#ifndef LEXICAL_ANALYZER_UNIT_TEST_MAIN_C
#define LEXICAL_ANALYZER_UNIT_TEST_MAIN_C

/*
 * lexical_analyzer_unit_test_main.c : This file contains the 'main' function. Program execution begins and ends there.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "LAH_lexical_analyzer.h"
#include "internal_sytax_state_tests.h"
#include "lexical_analyzer_unit_test_main.h"
#include "ERH_error_reporting.h"
#include "UTL_unit_test_logging.h"

bool run_all_lexical_analyzer_unit_tests(unsigned test_step)
{
	bool all_unit_tests_passed = true;

	UTL_va_log_fprintf("Unit Test %u: Starting Lexical Analizer Unit Tests \n\n", test_step);

	all_unit_tests_passed = internal_tests_on_all_state_transitions(test_step);

	if (all_unit_tests_passed)
	{
		// test the public interface for the lexical analyzer
		all_unit_tests_passed = 
			unit_test_lexical_analyzer(test_step);
	}

	UTL_va_log_fprintf("Unit Test %u: run_all_lexical_analyzer_unit_tests(unsigned "
		"test_step) : %s\n\n", test_step, all_unit_tests_passed ? "Passed" : "Failed");

	deactivate_lexical_analyzer();

	UTL_va_log_fprintf("Unit Test %u: Ending Lexical Analizer Unit Tests \n\n", test_step);

	return all_unit_tests_passed;
}

#ifdef LEXICAL_UNIT_TEST_ONLY
/*
 * All the unit tests can be combined into a single executable, when this is
 * done main should not be in each file.
 */
int main()
{
	ERH_error_out_file = stderr;
	int passed = EXIT_SUCCESS;

	if (!ERH_init_vm_error_reporting(NULL) ||
		!UTL_init_unit_tests("lexical_analyzer_unit_test_log.txt"))
	{
		return EXIT_FAILURE;
	}

	if (!run_all_lexical_analyzer_unit_tests(0))
	{
		passed = EXIT_FAILURE;
	}

	UTL_close_unit_tests();
	ERH_disengage_error_reporting();

	return passed;
}
#endif	// LEXICAL_UNIT_TEST_ONLY

#endif	// !LEXICAL_ANALYZER_UNIT_TEST_MAIN_C
