#include <iostream>
#include "SFML/Graphics.hpp"
#define _CRTDBG_MAP_ALLOC

float sigmoid(float x)
{
	return 1 / (1 + exp(-x));
}

float sigmoid_derivative(float x)
{
	return sigmoid(x) * (1 - sigmoid(x));
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML", sf::Style::Close);
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color(0, 0, 0));
		window.display();
	}

	return 0;
}

