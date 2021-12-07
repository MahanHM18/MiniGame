#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	
public:
	Game();
	virtual ~Game();
	void Event();
	void Update();
	void Render();

	void CreateWindow(int width, int height,sf::String title);
	bool IsOpen();
};

