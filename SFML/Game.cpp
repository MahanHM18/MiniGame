#include "Game.h"

Game::Game()
{
	window = nullptr;
}

Game::~Game()
{

}
void Game::Render()
{
	window->clear();
	window->display();
}

void Game::Event()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}
void Game::Update()
{

}

bool Game::IsOpen()
{
	return window->isOpen();
}

void Game::CreateWindow(int width,int height,sf::String title)
{
	videoMode.height = height;
	videoMode.width = width;
	window = new sf::RenderWindow(videoMode, title, sf::Style::Default);
}