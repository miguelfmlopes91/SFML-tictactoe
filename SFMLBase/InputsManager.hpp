#pragma once

#include "SFML\Graphics.hpp"

namespace Bardo
{
	class InputsManager
	{
	public:
		InputsManager() {}
		~InputsManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}