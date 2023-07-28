#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>


#include "../test_include/test_KreogCom.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(KreogCom, test_KreogCom_constructor, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    k.ping();
	cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 currently at 42 42\n");
}


Test(KreogCom, test_KreogCom_getCom, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    cr_assert_null(k.getCom());
	cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n");
}

Test(KreogCom, test_KreogCom_addCom, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
	cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n");
}

Test(KreogCom, test_KreogCom_locateSquad, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
	cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 51 currently at 73 34\n"
        "KreogCom 65 currently at 56 25\n"
        "KreogCom 101010 currently at 42 42\n");
}