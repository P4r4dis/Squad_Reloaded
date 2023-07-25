#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Parts.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Parts, test_Parts_Arms_constructor)//, .init = redirect_all_stdout)
{
    Arms arms;

    cr_assert(arms.serial() == "A-01");
    cr_assert(arms.getFunctional() == true);

    Arms arms2("Arms-01", false);

    cr_assert(arms2.serial() == "Arms-01");
    cr_assert(arms2.getFunctional() == false);
	// cr_assert_stdout_eq_str("");
}
