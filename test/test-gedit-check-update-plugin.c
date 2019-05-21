/*
	Programa de testes para o arquivo gedit-check-update-plugin.c
*/

#include <check.h>

#include <stdio.h>
#include "plugins/checkupdate/gedit-check-update-plugin.c"

START_TEST (test_get_numbers) {
}
END_TEST

START_TEST (test_newer_version) {
}
END_TEST

START_TEST (test_is_unstable) {
}
END_TEST

START_TEST (test_parse_file_version) {
}
END_TEST

Suite * test_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("gedit-check-update-plugin");

	/* Core test case */
	tc_core = tcase_create("gedit-check-update-plugin: tc_core");

	tcase_add_test(tc_core, test_get_numbers);
	tcase_add_test(tc_core, test_newer_version);
	tcase_add_test(tc_core, test_is_unstable);
	tcase_add_test(tc_core, test_parse_file_version);
	suite_add_tcase(s, tc_core);

	return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	printf("Fails: %d\n", number_failed);
	srunner_free(sr);

    return number_failed;
}