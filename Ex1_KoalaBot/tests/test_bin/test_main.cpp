#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_KoalaBot.hpp"

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

Test(Parts, test_Parts_Head_constructor, .init = redirect_all_stdout)
{
    Head head;

    cr_assert(head.serial() == "H-01");
    cr_assert(head.isFunctional() == true);

    Head head2("Head-01", false);

    cr_assert(head2.serial() == "Head-01");
    cr_assert(head2.isFunctional() == false);

    head.informations();
	cr_assert_stdout_eq_str("[Parts] Head H-01 status : OK\n");
}

Test(KoalaBot, test_KoalaBot_constructor)//, .init = redirect_all_stdout)
{
    KoalaBot    kb;

    cr_assert(kb.getSerial() == "Bob-01");
    cr_assert_null(&kb.getArms());
    cr_assert_null(&kb.getLegs());
    cr_assert_null(&kb.getHead());

	// cr_assert_stdout_eq_str("[Parts] Head H-01 status : OK\n");
}

Test(KoalaBot, test_KoalaBot_setParts)//, .init = redirect_all_stdout)
{
    KoalaBot    kb;
    Arms        arms;
    Legs        legs;
    Head        head;

    cr_assert(kb.getSerial() == "Bob-01");
    cr_assert_null(&kb.getArms());
    cr_assert_null(&kb.getLegs());
    cr_assert_null(&kb.getHead());

    kb.setPart(arms, legs, head);
    cr_assert_not_null(&kb.getArms());
    cr_assert_not_null(&kb.getLegs());
    cr_assert_not_null(&kb.getHead());
	// cr_assert_stdout_eq_str("[Parts] Head H-01 status : OK\n");
}