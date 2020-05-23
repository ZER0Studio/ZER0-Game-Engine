
#include "Window2D.h"
#include "Logger.h"

namespace ZEROGE {
	Window2D::Window2D(unsigned int width, unsigned int height, const char* applicationName) {
		Logger::Trace("Start 2D Window");
		_window(sf::VideoMode(width, height), applicationName);
	}
	const bool Window2D::StartGameTime() {
		while (_window->isOpen()) {
			sf::Event event;
			while (_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_window->close();
				}
			}
			_window->clear(sf::Color::Magenta);
			_window->display();
		}
	}

}