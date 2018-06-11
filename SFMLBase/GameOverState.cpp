#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"



namespace Bardo {

	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}


	void GameOverState::Init()
	{

		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));


		_retryButton.setPosition((this->_data->window.getSize().x / 2) - (_retryButton.getLocalBounds().width / 2)
			, (this->_data->window.getSize().y / 3) - (_retryButton.getLocalBounds().height / 2));

		_homeButton.setPosition((this->_data->window.getSize().x / 2) - (_homeButton.getLocalBounds().width / 2)
			, (this->_data->window.getSize().y / 3 * 2) - (_homeButton.getLocalBounds().height / 2));

	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}

}


