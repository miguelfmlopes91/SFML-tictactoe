#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"

namespace Bardo {

	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);
		~PauseState();

		void Init();
		// No pause() or resume() methods here as this
		// is a very simple example of a game state.
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;


	};

}

