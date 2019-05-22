/*
	Programa de testes para o arquivo gedit-check-update-plugin.c
*/

#include <check.h>

#include <stdio.h>
#include "plugins/checkupdate/gedit-check-update-plugin.c"

/**
* Teste para a função get_numbers()
* 
* Dado uma string contendo um número de versão (com no máximo 3 divisões)
* retorna o número de versão separado em três categorias na forma de inteiros.
* A string de versão deve conter pelo menos um separador "." e no máximo dois.
*/

START_TEST (test_get_numbers) {
	char* version;
	int major, minor, micro;

	// Teste 1 - Retornando 3 valores passando 3
	version = "3.20.0";
	get_numbers(version, &major, &minor, &micro);
	ck_assert_int_eq(major, 3);
	ck_assert_int_eq(minor, 20);
	ck_assert_int_eq(micro, 0);

	// Teste 2 - Retornando 2 valores passando 3
	version = "1.20.0";
	get_numbers(version, &major, &minor, NULL);
	ck_assert_int_eq(major, 1);
	ck_assert_int_eq(minor, 20);

	// Teste 3 - Retornando 2 valores passando 2
	version = "320.0";
	get_numbers(version, &major, &minor, NULL);
	ck_assert_int_eq(major, 320);
	ck_assert_int_eq(minor, 0);
	ck_assert_int_eq(micro, 0);
}
END_TEST

/**
* Teste para a função newer_version()
* 
* Dadas duas strings contendo números de versões, verifica se a primeira
* versão é mais nova que a segunda.
*/

START_TEST (test_newer_version) {
	char *version1;
	char *version2;

	// Teste 1
	version1 = "3.20.1";
	version2 = "3.20.0";
	ck_assert_int_eq(newer_version(version1, version2, FALSE), FALSE);

	// Teste 2
	version1 = "3.20.1";
	version2 = "3.20.0";
	ck_assert_int_eq(newer_version(version1, version2, TRUE), TRUE);

	// Teste 3
	version1 = "3.20.0";
	version2 = "3.21.0";
	ck_assert_int_eq(newer_version(version1, version2, TRUE), FALSE);

	// Teste 4
	version1 = "4.20.1";
	version2 = "3.21.0";
	ck_assert_int_eq(newer_version(version1, version2, TRUE), TRUE);

	// Teste 5
	version1 = "0.0.0";
	version2 = "0.0.0";
	ck_assert_int_eq(newer_version(version1, version2, TRUE), FALSE);

	// Teste 6
	version1 = NULL;
	version2 = NULL;
	ck_assert_int_eq(newer_version(version1, version2, TRUE), FALSE);
}
END_TEST

/**
* Teste para a função is_unstable()
* 
* Dada uma string contendo um número de versão, verifica se a versão é
* instável ou não. Para ser uma versão instável é necessário que o minor,
* valor correspondente ao campo do meio de um valor de versão, seja ímpar.
*/

START_TEST (test_is_unstable) {
	char *version;

	// Teste 1
	version = "3.20.1";
	ck_assert_int_eq(is_unstable(version), FALSE);

	// Teste 2
	version = "3.20.2";
	ck_assert_int_eq(is_unstable(version), FALSE);

	// Teste 3
	version = "3.21.2";
	ck_assert_int_eq(is_unstable(version), TRUE);

	// Teste 4
	version = "3.21.1";
	ck_assert_int_eq(is_unstable(version), TRUE);
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