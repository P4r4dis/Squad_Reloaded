#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
// #include <signal.h>


#include "../test_include/test_Skat.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Skat, test_Skat_ctor, .init = redirect_all_stdout)
{
    Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    cr_assert(s.getName() == "test");
    cr_assert(s.getStimPaks() == 20);
    cr_assert(s.getSerial() == 12345);
    cr_assert(s.getPosX() == 1);
    cr_assert(s.getPosY() == 2);
    cr_assert(s.getAmmoType() == Phaser::REGULAR);
    cr_assert(s.getPhaser() != nullptr);
    cr_assert(s.getKreogCom() != nullptr);
}

Test(Skat, test_Skat_fire, .init = redirect_all_stdout)
{
    Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
    s.fire();
    cr_assert(s.getPhaser()->getCurrentAmmos() == 19);

}

Test(Skat, test_Skat_locate, .init = redirect_all_stdout)
{
    Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    s.locate();
    cr_assert(s.getPosX() == 1);
    cr_assert(s.getPosY() == 2);
}

Test(Skat, test_Skat_reload, .init = redirect_all_stdout)
{
    Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
    s.fire();
    cr_assert(s.getPhaser()->getCurrentAmmos() == 19);
    s.reload();
    cr_assert(s.getPhaser()->getCurrentAmmos() == 20);
}

Test(Skat, test_Skat_com, .init = redirect_all_stdout)
{
    Skat s("test", 20, 12345, 1, 2, Phaser::REGULAR);

    cr_assert(s.com().getCom() == nullptr);
}

// Test(Phaser, test_Phaser_ctor)//, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);
    
//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);
// }

// Test(Phaser, test_Phaser_fire, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);
    
//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);

//     while (p.getCurrentAmmos() > 0)
//         p.fire();
    
//     cr_assert(p.getCurrentAmmos() == 0);
//     p.fire();
//     cr_assert(p.getMagazine() == 0);

// 	cr_assert_stdout_eq_str(
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Clip empty, please reload\n"
//     );
// }

// Test(Phaser, test_Phaser_ejectClip, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);
    
//     p.ejectClip();
//     cr_assert(p.getCurrentAmmos() == 0);
//     cr_assert(p.getMagazine() == 0);

//     p.fire();
    
// 	cr_assert_stdout_eq_str(
//         "Clip empty, please reload\n"
//     );
// }

// Test(Phaser, test_Phaser_changeType, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);

//     cr_assert(p.getAmmoType() == Phaser::ROCKET);
//     p.changeType(Phaser::PLASMA);
//     cr_assert(p.getAmmoType() == Phaser::PLASMA);
//     p.changeType(Phaser::REGULAR);
//     cr_assert(p.getAmmoType() == Phaser::REGULAR);
//     p.changeType(Phaser::ROCKET);
//     cr_assert(p.getAmmoType() == Phaser::ROCKET);
// 	cr_assert_stdout_eq_str(
//         "Switching ammo to type: plasma\n"
//         "Switching ammo to type: regular\n"
//         "Switching ammo to type: rocket\n"

//     );
// }

// Test(Phaser, test_Phaser_reload, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);

//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);

//     p.fire();
//     cr_assert(p.getCurrentAmmos() == 4);
//     cr_assert(p.getMagazine() == 4);

//     p.reload();
//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);

// 	cr_assert_stdout_eq_str(
//         "Booooooom\n"
//         "Reloading...\n"
//     );
// }

// Test(Phaser, test_Phaser_addAmmo, .init = redirect_all_stdout)
// {
//     Phaser  p(5, Phaser::ROCKET);

//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);

//     p.addAmmo(Phaser::ROCKET);
//     p.fire();
//     cr_assert(p.getCurrentAmmos() == 4);
//     cr_assert(p.getMagazine() == 4);

//     p.addAmmo(Phaser::ROCKET);
//     cr_assert(p.getCurrentAmmos() == 5);
//     cr_assert(p.getMagazine() == 5);

// 	cr_assert_stdout_eq_str(
//         "Clip full\n"
//         "Booooooom\n"
//     );
// }

// Test(Phaser, test_Phaser_mainFunction, .init = redirect_all_stdout)
// {
//     Phaser p(5, Phaser::ROCKET);

//     p.fire();
//     p.reload();
//     std::cout << "Firing all ammunitions" << std::endl;
//     while (p.getCurrentAmmos() > 0)
//         p.fire();
//     cr_assert_stdout_eq_str(
//         "Booooooom\n"
//         "Reloading...\n"
//         "Firing all ammunitions\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//     );
// }