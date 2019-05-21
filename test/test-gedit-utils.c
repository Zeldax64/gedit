/*
	Programa de testes para o arquivo gedit-utils.c
*/

#include <check.h>

#include <stdio.h>
#include "gedit/gedit-utils.h"

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
	gchar *str2   = "";
	gchar *str3   = NULL;

	// delimiter = \342\200\246 (...)
	gchar *test1_ex = "Hallo\342\200\246";
	gchar *test2_ex = "Hallo Welt";
	gchar *test3_ex = "Hallo Welt";
	gchar *test4_ex = "Hallo Welt";
	gchar *test5_ex = "Ha\342\200\246";
	gchar *test6_ex = "";
	gchar *test7_ex = NULL;

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

	// Test 6
	// Truncar uma string vazia não é possível
	test_res = gedit_utils_str_end_truncate(str2, 3);
	ck_assert_str_eq(test6_ex, test_res);

	// Test 7
	// Ao receber NULL, retorna NULL
	test_res = gedit_utils_str_end_truncate(str3, 3);
	ck_assert_ptr_eq(test7_ex, test_res);
	
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
	gchar *str2   = "";
	gchar *str3   = NULL;	

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
	gchar *test14_ex = "";
	gchar *test15_ex = NULL;

	gchar *test_res;

	// Test 1
	test_res = gedit_utils_str_middle_truncate(str, 0);
	ck_assert_str_eq(test1_ex, test_res);	
	
	test_res = gedit_utils_str_middle_truncate(str, 1);
	ck_assert_str_eq(test2_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 2);
	ck_assert_str_eq(test3_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 3);
	ck_assert_str_eq(test4_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 4);
	ck_assert_str_eq(test5_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 5);
	ck_assert_str_eq(test6_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 6);
	ck_assert_str_eq(test7_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 7);
	ck_assert_str_eq(test8_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 8);
	ck_assert_str_eq(test9_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str, 9);
	ck_assert_str_eq(test10_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,10);
	ck_assert_str_eq(test11_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,11);
	ck_assert_str_eq(test12_ex, test_res);
	
	test_res = gedit_utils_str_middle_truncate(str,12);
	ck_assert_str_eq(test13_ex, test_res);

	test_res = gedit_utils_str_middle_truncate(str2,3);
	ck_assert_str_eq(test14_ex, test_res);

	test_res = gedit_utils_str_middle_truncate(str3,3);
	ck_assert_ptr_eq(test15_ex, test_res);
}
END_TEST

/**
 * Teste para a função gedit_utils_make_valid_utf8()
 *
 * Converte um conjunto de caracteres para uma string
 * do tipo UTF-8 valida
 * 
 * 
 * 
*/
START_TEST (test_gedit_utils_make_valid_utf8) {
	gchar *test1   = "Teste";
	gchar *test2   = "Testes e mais testes";
	gchar *test3   = NULL;
	gchar *test4   = "";
	gchar *result1   = "\x54\x65\x73\x74\x65";
	gchar *result2   = "\x54\x65\x73\x74\x65\x73\x20\x65\x20\x6D\x61\x69\x73\x20\x74\x65\x73\x74\x65\x73";
	gchar *result3   = NULL;
	gchar *result4   = "";
	
	gchar *test_res;
	
	// Test 1
	test_res = gedit_utils_make_valid_utf8(test1);
	ck_assert_str_eq(result1, test_res);

	// Test 2
	test_res = gedit_utils_make_valid_utf8(test2);
	ck_assert_str_eq(result2, test_res);

	// Test 3
	test_res = gedit_utils_make_valid_utf8(test3);
	ck_assert_ptr_eq(test_res, result3);

	// Test 4
	test_res = gedit_utils_make_valid_utf8(test4);
	ck_assert_str_eq(result4, test_res);
}
END_TEST

/**
 * Teste para a função gedit_utils_location_get_dirname_for_display() (em andamento)
 *
 * Retorna o nome de diretório de um path 
 * de arquivo. Não leva em conta o diretório home 
 * e similares, substituindo-os por um ~.
 * 
 * 
*/

START_TEST (test_gedit_utils_location_get_dirname_for_display) {
	gchar *path1 = "/home/teste/Documents/gedit/test.c";
	GFile *location1  = g_file_new_for_path(path1);
	gchar *result1  = "~/Documents/gedit";
	GFile *location2  = NULL;
	gchar *result2  = NULL;
	gchar *path3 = "/home/test.c";
	GFile *location3  = g_file_new_for_path(path3);
	gchar *result3  = "/home";

	gchar *test_res;

	// Test 1
	test_res = gedit_utils_location_get_dirname_for_display(location1);
	printf("test_gedit_utils_location_get_dirname_for_display: %s\n", test_res);
	ck_assert_str_eq(result1, test_res);

	// Test 2
	test_res = gedit_utils_location_get_dirname_for_display(location2);
	ck_assert_ptr_eq(test_res, result2);

	// Test 3
	test_res = gedit_utils_location_get_dirname_for_display(location3);
	ck_assert_str_eq(test_res, result3);

}
END_TEST

/**
 * Teste para a função gedit_utils_is_valid_location() (em andamento)
 *
 * Verifica se um determinado path é
 * válido, isso é, se ele está no padrão
 * correto, não se ele existe ou não.
 * 
*/

START_TEST (test_gedit_utils_is_valid_location) {
	gchar *path1 = "/home/teste/Documents/gedit/test.c";
	GFile *location1  = g_file_new_for_path(path1);
	gchar *path2 = "/";	
	GFile *location2  = g_file_new_for_path(path2);
	gchar *path3 = "";	
	GFile *location3  = g_file_new_for_path(path3);
	GFile *location4  = NULL;

	gboolean test_res;

	// Test 1
	test_res = gedit_utils_is_valid_location(location1);
	ck_assert(test_res);

	// Test 2
	test_res = gedit_utils_is_valid_location(location2);
	ck_assert(test_res);

	// Test 3
	test_res = gedit_utils_is_valid_location(location3);
	ck_assert(test_res);

	// Test 4
	test_res = gedit_utils_is_valid_location(location4);
	ck_assert(!test_res);
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
	tcase_add_test(tc_core, test_gedit_utils_make_valid_utf8);
	tcase_add_test(tc_core, test_gedit_utils_location_get_dirname_for_display);
	tcase_add_test(tc_core, test_gedit_utils_is_valid_location);
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
