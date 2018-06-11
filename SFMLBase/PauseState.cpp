#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "PauseState.hpp"



namespace Bardo {

	PauseState::PauseState(GameDataRef data) : _data(data)
	{

	}


	void PauseState::Init()
	{
		//Set the gameplaying state


		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button",RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);


		_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));


		_resumeButton.setPosition((this->_data->window.getSize().x /2) - (_resumeButton.getLocalBounds().width/2)
			, (this->_data->window.getSize().y / 3) - (_resumeButton.getLocalBounds().height / 2));

		_homeButton.setPosition((this->_data->window.getSize().x / 2) - (_homeButton.getLocalBounds().width / 2)
			, (this->_data->window.getSize().y / 3*2) - (_homeButton.getLocalBounds().height / 2));

	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
			}
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)),true);
			}
		}
	}

	void PauseState::Update(float dt)
	{
	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}

}


