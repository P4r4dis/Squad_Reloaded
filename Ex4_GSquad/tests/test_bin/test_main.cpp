#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
// #include <signal.h>


#include "../test_include/test_Skat.hpp"
#include "../test_include/test_Squad.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test(Skat, test_Skat_ctor, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    
//     cr_assert(s.getName() == "test");
//     cr_assert(s.getStimPaks() == 20);
//     cr_assert(s.getSerial() == 12345);
//     cr_assert(s.getPosX() == 1);
//     cr_assert(s.getPosY() == 2);
//     cr_assert(s.getAmmoType() == Phaser::REGULAR);
//     cr_assert(s.getPhaser() != nullptr);
//     cr_assert(s.getKreogCom() != nullptr);
// }

// Test(Skat, test_Skat_fire, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

//     cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
//     s.fire();
//     cr_assert(s.getPhaser()->getCurrentAmmos() == 19);
// }

// Test(Skat, test_Skat_locate, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

//     s.locate();
//     cr_assert(s.getPosX() == 1);
//     cr_assert(s.getPosY() == 2);
// }

// Test(Skat, test_Skat_reload, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

//     cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
//     s.fire();
//     cr_assert(s.getPhaser()->getCurrentAmmos() == 19);
//     s.reload();
//     cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
// }

// Test(Skat, test_Skat_com, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

//     cr_assert(s.com().getCom() == nullptr);
// }

// Test(Skat, test_Skat_addCom, .init = redirect_all_stdout)
// {
//     Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

//     KreogCom kreog(2, 3, 1);



//     kreog.addCom(&s.com());
//     kreog.locateSquad();


//     // kreog.locateSquad();

//     //   KreogCom kreog2(2, 3, 2);

//     // s.addCom(&kreog);
//     // s.com().ping();
 
// }

// Test(Squad, Test_Squad, .init = redirect_all_stdout)
// {
//     Squad   squad;

//     cr_assert(squad.getPosXBegin() == 0);
//     cr_assert(squad.getPosYBegin() == 0);
//     cr_assert(squad.getAmmoType() == Phaser::REGULAR);
//     cr_assert(squad.getSize() == 5);
// }


// Test(Squad, Test_Squad_foreach, .init = redirect_all_stdout)
// {
//     Squad   squad;

//     squad.foreach(0, &Skat::fire);
// }

Test(Squad, Test_Squad_localisation, .init = redirect_all_stdout)
{
    Squad   squad;

    // squad.localisation();
    cr_assert_stdout_eq_str(
"KreogCom 0 initialized\n"
"KreogCom 1 initialized\n"
"KreogCom 2 initialized\n"
"KreogCom 3 initialized\n"
"KreogCom 4 initialized\n"
"KreogCom 0 shutting down\n"
"KreogCom 1 shutting down\n"
"KreogCom 2 shutting down\n"
"KreogCom 3 shutting down\n"
"KreogCom 4 shutting down\n");
}
// "KreogCom 0 currently at 0 0\n"
// "KreogCom 1 currently at 10 15\n"
// "KreogCom 2 currently at 20 30\n"
// "KreogCom 3 currently at 30 45\n"
// "KreogCom 4 currently at 40 60\n"

// Test(Squad, Test_Squad_Skats, .init = redirect_all_stdout)
// {
//     Squad   squad;

//     cr_assert(squad.skats() != nullptr);
// }


// Test(Squad, Test_Squad_at, .init = redirect_all_stdout)
// {
//     Squad   squad;

//     cr_assert(squad.at(0) == (*squad.skats()));
//     cr_assert(squad.at(6) == nullptr);
// }
