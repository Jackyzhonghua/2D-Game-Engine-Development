#include <iostream>
#include <time.h> 
#include "Game.h"


int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	Game game;
	if (game.inite())
	{
		game.Update();
	}

	return 0;
}
