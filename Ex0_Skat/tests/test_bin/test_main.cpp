#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Skat.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Skat, test_Skat_constructor)//, .init = redirect_all_stdout)
{
    Skat    skat;
    cr_assert(skat.stimPaks() == 15);
    cr_assert(skat.name() == "bob");
    skat.name() = "t";
    Skat    skat2("Bob2", 20);
    cr_assert(skat2.stimPaks() == 20);
    cr_assert(skat2.name() == "Bob2");
	// cr_assert_stdout_eq_str("");
}
