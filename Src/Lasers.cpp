#include "Lasers.h"

namespace EdgarSam
{
    Lasers::Lasers(GameDataPtr data, sf::Vector2f position, bool right_Dir) : _data(data)
    {
        this->SpawnLasers(position, right_Dir);
    }
    void Lasers::SpawnLasers(sf::Vector2f position, bool right_Dir)
    {
        
        _data->assets.AddTexture("lasers", LASER_FILEPATH);
        _laser.setTexture(_data->assets.getTexture("lasers"));
        _laser.setPosition(position);
        _laser.setScale(0.30f, 0.50f);
        
        if (right_Dir)
        {
            direction = sf::Vector2f(1.0f, 0.0f); // Flip the sprite to face right
        }
        else
        {
            direction = sf::Vector2f(-1.0f, 0.0f); // Flip the sprite to face left
        }
    }
    void Lasers::Update(float dt)
    {
        _laser.move(dt * LASER_SPEED * direction);
    }
    void Lasers::updateDirection()
    {
    }
    void Lasers::draw()
    {
        _data->window.draw(_laser);
    }
    sf::FloatRect Lasers::getBounds() const
    {
        return _laser.getGlobalBounds();
    }
}