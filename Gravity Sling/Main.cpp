#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <istream>
#include "obstacle.h"
#include "blackHole.h"
#include "GameLoop.h"
#include "interface.h"

int main()
{
	//Create Level 1
	Obstacle exit1(610, 65, 40, 0.9, "./textures/citadel.png");
	BlackHole bh1(100, 300, 100, 1200, 0.30, "./textures/blackHole.png");
	Ship ship1(150, 530, 30, 2, -2, 1, "./textures/ship.png");
	Level level1(ship1, exit1, "first Level", "./textures/space1.jpg");
	level1.addHole(bh1);
	level1.addObstacle(exit1);


	//Create Level 2 

	Obstacle exit2(610, 65, 40, 0.9, "./textures/citadel.png");
	BlackHole bh2(100, 300, 100, 1200, 0.30, "./textures/blackHole.png");
	Ship ship2(150, 530, 30, 1 / 2, -1, 1, "./textures/ship.png");
	Level level2(ship2, exit2, "second Level", "./textures/space2.jpg");
	level2.addHole(bh2);
	level2.addObstacle(exit2);


	//Create Level 3

	Obstacle exit3(610, 530, 40, 0.9, "./textures/citadel.png");
	Obstacle sun3(310, 260, 30, 0.5, "./textures/sun.png");
	BlackHole bh31(100, 300, 100, 1200, 0.30, "./textures/blackHole.png");
	BlackHole bh32(100, 300, 150, 2000, 0.30, "./textures/blackHole.png");
	Ship ship3(150, 65, 30, 1, 1, 1, "./textures/ship.png");
	Level level3(ship3, exit3, "third Level", "./textures/space3.jpg");
	level3.addHole(bh31);
	level3.addHole(bh32);
	level3.addObstacle(exit3);
	level3.addObstacle(sun3);

	//Create Level 4

	Obstacle exit4(610, 530, 40, 0.9, "./textures/citadel.png");
	Obstacle sun41(330, 200, 80, 0.5, "./textures/sun.png");
	Obstacle sun42(410, 350, 50, 0.5, "./textures/sun.png");
	BlackHole bh41(100, 300, 100, 1200, 0.30, "./textures/blackHole.png");
	BlackHole bh42(100, 300, 100, 1200, 0.30, "./textures/blackHole.png");
	BlackHole bh43(100, 300, 50, 600, 0.30, "./textures/blackHole.png");
	Ship ship4(150, 65, 30, 1, 1, 1, "./textures/ship.png");
	Level level4(ship4, exit4, "fourth Level", "./textures/space4.jpg");
	level4.addHole(bh41);
	level4.addHole(bh42);
	level4.addHole(bh43);
	level4.addObstacle(exit4);
	level4.addObstacle(sun41);
	level4.addObstacle(sun42);

	//Create Level 5
	Obstacle exit5(610, 65, 0, 0.9, "./textures/citadel.png");
	Ship ship5(150, 530, 0, 1, -1, 1, "./textures/ship.png");
	Level level5(ship5, exit5, "you won !", "./textures/win.png");
	level5.addObstacle(exit5);


	//create and launch game
	GameLoop game;
	game.pushLevel(level1);
	game.pushLevel(level2);	
	game.pushLevel(level3);	
	game.pushLevel(level4);
	game.pushLevel(level5);
	game.initGame();
	game.loop();

	return 0;
}