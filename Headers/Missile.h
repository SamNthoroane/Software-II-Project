/*#ifndef MISSILE_H
#define MISSILE_H



#include "StateManager.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace EdgarSam
{

    class Missile
    {
    public:
        Missile(GameDataPtr data, sf::Vector2f position, sf::Vector2f position2);
        ~Lasers(){};
        void SpawnMissile(sf::Vector2f position, sf::Vector2f position2);
        void Update(float dt);
        void updateDirection();
        sf::FloatRect getBounds() const;
        void draw();

    private:
        GameDataPtr _data;
        sf::Sprite _missile;
        sf::Vector2f direction;
        std::vector<sf::Sprite>
            _missileSprites;
    };
}
#endif*/