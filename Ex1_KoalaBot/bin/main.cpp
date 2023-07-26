#include "../include/KoalaBot.hpp"
int	main()
{
    KoalaBot    kb;

    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();

	return 0;
}