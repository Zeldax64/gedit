#include <check.h>

#include <stdio.h>
#include "gedit-utils.h"

/**
 * Teste para a função gedit_utils_str_end_truncate()
 *  
 * Reduz o número de caracteres de uma string para o valor
 * 'x' passado como argumento. A string retornada é trunca-
 * da a partir da posição 'x' e substituída por reticên-
 * cias (...). Se o valor de 'x' for menor que 3 a função
 * retorna uma string igual a original.
*/
START_TEST (test_gedit_utils_str_end_truncate) {
	gchar *str   = "Hallo Welt";

	// delimiter = \342\200\246 (...)
	gchar *test1_ex = "Hallo\342\200\246";
	gchar *test2_ex = "Hallo Welt";
	gchar *test3_ex = "Hallo Welt";
	gchar *test4_ex = "Hallo Welt";
	gchar *test5_ex = "Ha\342\200\246";

	gchar *test_res;

	// Test 1
	test_res = gedit_utils_str_end_truncate(str, 6);
	ck_assert_str_eq(test1_ex, test_res);

	// Test 2
	// Não é possível truncar para length < 3 
	test_res = gedit_utils_str_end_truncate(str, 0);
	ck_assert_str_eq(test2_ex, test_res);
	
	// Test 3
	// Não é possível truncar para length < 3 
	test_res = gedit_utils_str_end_truncate(str, 1);
	ck_assert_str_eq(test3_ex, test_res);
	
	// Test 4
	// Não é possível truncar para length < 3 
	test_res = gedit_utils_str_end_truncate(str, 2);
	ck_assert_str_eq(test4_ex, test_res);
	
	// Test 5
	// A partir do terceiro caractere é possível truncar
	test_res = gedit_utils_str_end_truncate(str, 3);
	ck_assert_str_eq(test5_ex, test_res);
	
}
END_TEST

/**
 * Teste para a função gedit_utils_str_middle_truncate()
 *
 * Retorna uma string cujo o número de caracteres é reduzido
 * a um valor 'x' que é passado como parâmetro truncando o 
 * meio da string e substituindo o conteúdo truncado por 
 * reticências. Caso 'x' seja menor que 3 a string retornada
 * será igual a original.
*/

START_TEST (test_gedit_utils_str_middle_truncate) {
	gchar *str   = "Hallo Welt";

	// delimiter = \342\200\246 (...)

	gchar *test1_ex  = "Hallo Welt";
	gchar *test2_ex  = "Hallo Welt";
	gchar *test3_ex  = "Hallo Welt";
	gchar *test4_ex  = "H\342\200\246t";
	gchar *test5_ex  = "H\342\200\246lt";
	gchar *test6_ex  = "Ha\342\200\246lt";
	gchar *test7_ex  = "Ha\342\200\246elt";
	gchar *test8_ex  = "Hal\342\200\246elt";
	gchar *test9_ex  = "Hal\342\200\246Welt";
	gchar *test10_ex = "Hall\342\200\246Welt";
	gchar *test11_ex = "Hallo Welt";
	gchar *test12_ex = "Hallo Welt";
	gchar *test13_ex = "Hallo Welt";

	gchar *test_res;

	// Test 1
	test_res = gedit_utils_str_middle_truncate(str, 0);
	ck_assert_str_eq(test1_ex, test_res);	
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 1);
	ck_assert_str_eq(test2_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 2);
	ck_assert_str_eq(test3_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 3);
	ck_assert_str_eq(test4_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 4);
	ck_assert_str_eq(test5_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 5);
	ck_assert_str_eq(test6_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 6);
	ck_assert_str_eq(test7_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 7);
	ck_assert_str_eq(test8_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 8);
	ck_assert_str_eq(test9_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 9);
	ck_assert_str_eq(test10_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,10);
	ck_assert_str_eq(test11_ex, test_res);
	printf("%s\n", test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,11);
	printf("%s\n", test_res);
	ck_assert_str_eq(test12_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,12);
	printf("%s\n", test_res);
	ck_assert_str_eq(test13_ex, test_res);
}
END_TEST

Suite * test_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("gedit-utils");

	/* Core test case */
	tc_core = tcase_create("gedit_utils_str_end_truncate");

	tcase_add_test(tc_core, test_gedit_utils_str_end_truncate);
	tcase_add_test(tc_core, test_gedit_utils_str_middle_truncate);
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