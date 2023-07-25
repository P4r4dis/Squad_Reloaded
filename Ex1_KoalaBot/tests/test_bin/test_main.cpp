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
    cr_assert(arms.isFunctional() == true);

    Arms arms2("Arms-01", false);

    cr_assert(arms2.serial() == "Arms-01");
    cr_assert(arms2.isFunctional() == false);
	// cr_assert_stdout_eq_str("");
}

Test(Parts, test_Parts_Arms_informations, .init = redirect_all_stdout)
{
    Arms arms;

    arms.informations();
	cr_assert_stdout_eq_str(
        "[Parts] Arms A-01 status : OK\n");
}

Test(Parts, test_Parts_Legs_constructor, .init = redirect_all_stdout)
{
    Legs legs;

    cr_assert(legs.serial() == "L-01");
    cr_assert(legs.isFunctional() == true);

    Legs legs2("Legs-01", false);

    cr_assert(legs2.serial() == "Legs-01");
    cr_assert(legs2.isFunctional() == false);

    legs.informations();
	cr_assert_stdout_eq_str("[Parts] Legs L-01 status : OK\n");
}