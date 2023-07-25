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

    Skat    skat2("Bob2", 20);
    cr_assert(skat2.stimPaks() == 20);
    cr_assert(skat2.name() == "Bob2");
	// cr_assert_stdout_eq_str("");
}

Test(Skat, test_Skat_shareStimPaks, .init = redirect_all_stdout)
{
    Skat    skat;
    cr_assert(skat.stimPaks() == 15);
    cr_assert(skat.name() == "bob");

    skat.shareStimPaks(16, 0);
    skat.shareStimPaks(10, 0);
    cr_assert(skat.stimPaks() == 5);
	cr_assert_stdout_eq_str(
        "Don't be greedy\n"
        "Keep the change.\n");
}

Test(Skat, test_Skat_addStimPaks, .init = redirect_all_stdout)
{
    Skat    skat;

    skat.addStimPaks(0);
    skat.addStimPaks(5);
    cr_assert(skat.stimPaks() == 20);
	cr_assert_stdout_eq_str(
        "Hey boya, did you forget something?\n");
}

Test(Skat, test_Skat_useStimPaks, .init = redirect_all_stdout)
{
    Skat    skat("bob", 1);

    cr_assert(skat.stimPaks() == 1);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 0);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 0);
	cr_assert_stdout_eq_str(
        "Time to kick some ass and chew bubble gum.\n"
        "Mediiiiiic\n");
}

Test(Skat, test_Skat_status, .init = redirect_all_stdout)
{
    Skat    skat;

    skat.status();
    cr_assert(skat.stimPaks() == 15);
    cr_assert(skat.name() == "bob");

	cr_assert_stdout_eq_str(
        "Soldier bob reporting 15 stimpaks remaining sir!\n");
}

Test(Skat, test_Skat_mainFunction, .init = redirect_all_stdout)
{
    Skat    s("Junior", 5);

    cr_assert(s.stimPaks() == 5);
    cr_assert(s.name() == "Junior");

    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    cr_assert(s.stimPaks() == 4);

	cr_assert_stdout_eq_str(
        "Soldier Junior\n"
        "Soldier Junior reporting 5 stimpaks remaining sir!\n"
        "Time to kick some ass and chew bubble gum.\n");
}