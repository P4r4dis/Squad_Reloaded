#include "../include/Phaser.hpp"

int	main()
{
	Phaser p(5, Phaser::ROCKET);

	p.fire();
	p.reload();
	std::cout << "Firing all ammunitions" << std::endl;
	while (p.getCurrentAmmos() > 0)
		p.fire();
	
	return 0;
}