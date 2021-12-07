#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	sf::RectangleShape enemy;
	
public:
	Game();
	virtual ~Game();
	void Event();
	void Update();
	void Render();

	void CreateWindow(int width, int height,sf::String title,int limitFrame);
	bool IsOpen();

	void Enemy(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
};

