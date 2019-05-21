/*
	Programa de testes para o arquivo gedit-time-plugin.c
*/

#include <check.h>

#include <stdio.h>
#include "plugins/time/gedit-time-plugin.c"

START_TEST (test_gedit_get_time) {
	gchar* time_format = "%a, %d %b %Y %H:%M:%S %z";
	gchar* time;
	time = get_time(time_format);

	printf("TIME: %s \n", time);
}
END_TEST

Suite * test_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("gedit-time-plugin");

	/* Core test case */
	tc_core = tcase_create("gedit-time-plugin>tc_core");

	tcase_add_test(tc_core, test_gedit_get_time);
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