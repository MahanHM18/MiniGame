#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
	Game* game = new Game();

	game->CreateWindow(640, 480,"Game",60);

	while (game->IsOpen())
	{
		game->Update();
	}

	return 0;
}