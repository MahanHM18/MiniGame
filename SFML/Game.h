#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	int enemyTimer;
	int enemyMaxTimer;
	int maxEnemy;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	
public:
	Game();
	virtual ~Game();
	void Event();
	void Update();
	void Render();

	void CreateWindow(int width, int height,sf::String title,int limitFrame);
	bool IsOpen();

	void EnemyAdd(sf::Vector2f pos, sf::Vector2f size, sf::Color color);

	void EnemySpawner();

	void EnemyRenderer();

	void EnemyMove();

	void MouseUpdate();
};

