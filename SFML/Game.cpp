#include "Game.h"

Game::Game()
{
	window = nullptr;
	enemyMaxTimer = 40;
	maxEnemy = 100;
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

void Game::EnemyAdd(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	enemy.setPosition(pos);
	enemy.setSize(size);
	enemy.setFillColor(color);
	enemies.push_back(enemy);
}

void Game::EnemySpawner()
{
	if (enemies.size() < maxEnemy)
	{
		if (enemyTimer >= enemyMaxTimer)
		{
			EnemyAdd(sf::Vector2f(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
				static_cast<float> (rand() % static_cast<int>(window->getSize().y - enemy.getSize().y))), sf::Vector2f(50.f, 50.f),
				sf::Color::Green);
			
			enemyTimer = 0;
		}
		else
			enemyTimer += 1;
	}
}

void Game::EnemyRenderer()
{
	for (auto& item : enemies)
	{
		window->draw(item);
	}
}

void Game::EnemyMove()
{
	for (auto& item : enemies)
	{
		item.move(sf::Vector2f(0.f, 4.f));
	}
}