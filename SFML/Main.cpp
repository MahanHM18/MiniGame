#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
	Game* game = new Game();

	game->CreateWindow(640, 480,"Game",60);
	game->Enemy(sf::Vector2f(324.f,206.f), sf::Vector2f(60.f, 60.f), sf::Color::Green);

	while (game->IsOpen())
	{
		game->Update();
		game->Event();
		game->Render();
	}

	return 0;
}