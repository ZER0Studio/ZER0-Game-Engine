#pragma once

#include <SFML\Graphics.hpp>

struct sf::RenderWindow;

namespace ZEROGE {
	class Window2D
	{
	public:
		Window2D(unsigned int width, unsigned int height ,const char* applicationName);
		~Window2D();
		const bool StartGameTime();

	private:
		sf::RenderWindow* _window;
	};


}