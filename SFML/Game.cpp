#include "Game.h"
#include <iostream>

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
	window->draw(enemy);
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
	std::cout << "Mouse x : " << sf::Mouse::getPosition(*window).x << std::endl << "Mouse y : " << sf::Mouse::getPosition(*window).y << std::endl;
}

bool Game::IsOpen()
{
	return window->isOpen();
}

void Game::CreateWindow(int width, int height, sf::String title, int limitFrame)
{
	videoMode.height = height;
	videoMode.width = width;
	window = new sf::RenderWindow(videoMode, title, sf::Style::Default);
	window->setFramerateLimit(limitFrame);
}

void Game::Enemy(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	enemy.setPosition(pos);
	enemy.setSize(size);
	enemy.setFillColor(color);
}