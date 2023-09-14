/*#include "Missile.h"

namespace EdgarSam
{
    Missile::Missile(GameDataPtr data, sf::Vector2f position, sf::Vector2f position2) : _data(data)
    {
        this->SpawnLasers(position, position2);
    }
    void Missile::SpawnMissile(sf::Vector2f position,Vector2f position2 )
    {
        
        _data->assets.AddTexture("missile", Missile_FILEPATH);
        _laser.setTexture(_data->assets.getTexture("missle"));
        _laser.setPosition(position);
        _laser.setScale(0.30f, 0.50f);
        
       
            direction.getPosition().y = position2.getPosition.y 
            direction.getPosition().x = position2getPosition().x
        
    }
    void Missile::Update(float dt)
    {
        _missile.move(dt * MISSILE_SPEED * direction);
    }
    void Missile::updateDirection()
    {
    }
    void Missile::draw()
    {
        _data->window.draw(_missile);
    }
    sf::FloatRect Missile::getBounds() const
    {
        return _missile.getGlobalBounds();
    }
}*/