#include "Game.h"
#include <iostream>

Game::Game()
{
	window = nullptr;
	enemyMaxTimer = 100;
	maxEnemy = 5;
}

Game::~Game()
{

}
void Game::Render()
{
	window->clear();
	EnemyRenderer();
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
	EnemyMove();
	EnemySpawner();
	Event();
	Render();
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

void Game::EnemySpawner()
{
	std::cout << enemyTimer << std::endl;
	if (enemies.size() < maxEnemy)
	{
		if (enemyTimer >= enemyMaxTimer)
		{
			Enemy(sf::Vector2f(5.f, 5.f), sf::Vector2f(60.f, 60.f), sf::Color::Green);
			enemies.push_back(enemy);
			enemyTimer = 0;
		}
		else
			enemyTimer += 1;
	}
}

void Game::EnemyRenderer()
{
	for (auto &item : enemies)
	{
		window->draw(item);
	}
}

void Game::EnemyMove()
{
	//moving
	for (auto &item : enemies)
	{
		item.move(sf::Vector2f(5.f,0.f));
	}
}