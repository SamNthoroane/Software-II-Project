#include "GameOverState.h"
#include "MenuState.h"
#include "GameState.h"
#include <iostream>
#include "Definations.h"

namespace EdgarSam
{
    GameOverState::GameOverState(GameDataPtr data) : _data(data)
    {
    }

    void GameOverState::InitState()
    {
        // stored in a map
        this->_data->assets.AddTexture("Background_gameover", GAMEOVER_BACKGROUND);
        this->_background.setTexture(_data->assets.getTexture("Background_gameover"));
        _background.setScale(sf::Vector2f(1.00392157f, 1.088646967f));

        this->InitText();
    }

    void GameOverState::InitText()
    {
        // load font
        this->_data->assets.AddFont("Font", MAINMENU_FONT);
        // load text
        this->gameover_text.setFont(_data->assets.getFont("Font"));
        this->gameover_text.setCharacterSize(40);
        this->gameover_text.setFillColor(sf::Color::White);
        this->gameover_text.setString("Game Over");

        this->title = this->gameover_text;
        this->title.setString("DEFENDER");
        this->title.setFillColor(sf::Color::Red);
        this->title.setCharacterSize(60);

        this->gameover_text.setPosition((SCREEN_WIDTH - gameover_text.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - gameover_text.getGlobalBounds().height) / 2);
        this->title.setPosition((SCREEN_WIDTH - title.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - title.getGlobalBounds().height * 6.0f) / 2);
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _data->window.close();
            }

            if (_data->inputs.IsHovering(this->gameover_text, _data->window))
            {
                this->gameover_text.setFillColor(sf::Color::Green);
            }
            else
            {
                this->gameover_text.setFillColor(sf::Color::White);
            }
        }
    }

    void GameOverState::Update(float dt)
    {
    }
    void GameOverState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(gameover_text);
        _data->window.draw(title);
        _data->window.display();
    }
}