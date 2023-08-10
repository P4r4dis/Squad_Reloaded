#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
// #include <signal.h>


#include "../test_include/test_Phaser.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Phaser, test_Phaser_ctor)//, .init = redirect_all_stdout)
{
    Phaser  p(5, Phaser::ROCKET);
    
    cr_assert(p.getCurrentAmmos() == 5);
	// cr_assert_stdout_eq_str(
        // "KreogCom 101010 initialized\n"
        // "KreogCom 101010 shutting down\n"
    // );
}
