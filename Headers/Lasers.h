#ifndef LASERS_H
#define LASERS_H



#include "StateManager.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace EdgarSam
{

    class Lasers
    {
    public:
        Lasers(GameDataPtr data, sf::Vector2f position, bool right_Dir);
        ~Lasers(){};
        void SpawnLasers(sf::Vector2f position, bool right_Dir);
        void Update(float dt);
        void updateDirection();
        sf::FloatRect getBounds() const;
        void draw();

    private:
        GameDataPtr _data;
        sf::Sprite _laser;
        sf::Vector2f direction;
        std::vector<sf::Sprite>
            _laserSprites;
    };
}
#endif