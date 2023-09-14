#include "SplashState.h"
#include "MenuState.h"
#include <iostream>
#include "Definations.h"
namespace EdgarSam
{
    SplashState::SplashState(GameDataPtr data) : _data(data)
    {
    }

    void SplashState::InitState()
    {
        // store them in a map ...then get
        _data->assets.AddTexture("splashbackground", SPLASHSTATE_BACKGROUND);
        _background.setTexture(_data->assets.getTexture("splashbackground"));
        _background.setScale(sf::Vector2f(1.0f, 0.7777778f));

        this->_data->assets.AddFont("InstructionFont", MAINMENU_FONT);
        //Setting the font
        this->_Instruction.setFont(_data->assets.getFont("InstructionFont"));
        this->_Instruction.setString("Right Click Mouse to Shoot and Arrows to Move");
        this->_Instruction.setCharacterSize(15);
        this->_Instruction.setFillColor(sf::Color::Yellow);
        this->_Instruction.setPosition(_data->window.getSize().x/10,_data->window.getSize().y/2);

        this->_clock.restart();
    }

    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
        }
    }
    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASHSTATE_SHOW_TIME)
        {
            _data->states.PushState(std::unique_ptr<State>(new MenuState(_data)), true, true); // on vector
            this->_clock.restart();
        }
    }
    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_Instruction);
        _data->window.display();
    }

}
