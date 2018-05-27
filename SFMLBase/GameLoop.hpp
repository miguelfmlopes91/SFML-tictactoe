#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StatesMachine.hpp"
#include "AssetsManager.hpp"
#include "InputsManager.hpp"

namespace Bardo
{
	struct GameData
	{
		StatesMachine machine;
		sf::RenderWindow window;
		AssetsManager assets;
		InputsManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class GameLoop
	{
	public:
		GameLoop(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}