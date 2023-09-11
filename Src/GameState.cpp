#include "GameState.h"
#include "StateManager.h"
#include "Definations.h"
#include "GameOverState.h"

namespace EdgarSam
{
    GameState::GameState(GameDataPtr data) : _data(data)
    {
    }
    GameState::~GameState()
    {
        delete this->space;
        delete this->spaceShip;
        for (auto *laser : lasers)
        {
            delete laser;
        }
        for (auto *asteroid : asteroids)
        {
            delete asteroid;
        }
        for (auto *lander : landers)
        {
            delete lander;
        }
    }
    void GameState::InitState()
    {
        // OBJECT
        this->spaceShip = new SpaceShip(_data);
        this->space = new Space(_data);
    }
    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _data->window.close();
            }
        }
    }

    void GameState::shootLasers()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            lasers.push_back(new Lasers(_data, sf::Vector2f(spaceShip->getPosition().x, spaceShip->getPosition().y + spaceShip->getBounds().height * 0.45f), spaceShip->getDirection()));
        }
    }

    //Shoot missile? Has to be implemented within the spawning of Landers

    void GameState::InitAsteroid()
    {
        if (this->clock_1.getElapsedTime().asSeconds() > ASTERIOD_SPAWNTIME)
        {
            asteroids.push_back(new Asteroid(_data));
            this->clock_1.restart();
        }
    }
    void GameState::InitLander()
    {
        if (this->clock_2.getElapsedTime().asSeconds() > LANDER_SPAWNTIME && landers.size() < LANDER_COUNT)
        {
            landers.push_back(new Lander(_data));
            //launch missile
            this->clock_2.restart();
        }
    }

    void GameState::UpdateLaser(float dt)
    {
        for (unsigned int counter = 0; counter < lasers.size(); counter++)
        {
            lasers[counter]->Update(dt);
            if (lasers[counter]->getBounds().left + lasers[counter]->getBounds().width < 0 || lasers[counter]->getBounds().left > _data->window.getSize().x)
            {
                delete lasers[counter];
                lasers.erase(lasers.begin() + counter);
            }
        }
        std::cout << "sizeLaser: " << lasers.size() << std::endl;
    }
    
    //Need an update for missile?

    void GameState::UpdateLander(float dt)
    {
        for (unsigned int counter = 0; counter < landers.size(); counter++)
        {
            landers[counter]->update(dt);
        }
        std::cout << "sizelanders: " << landers.size() << std::endl;
    }

    void GameState::LaserAsteroidCollision()
    {
        for (unsigned int i = 0; i < asteroids.size(); ++i)
        {
            bool asteroid_removed = false;

            for (unsigned int k = 0; k < lasers.size() && asteroid_removed == false; ++k)
            {
                if (lasers[k]->getBounds().intersects(asteroids[i]->getBounds()))
                {
                    // freeing up the memory allocated for the asteroid and laser object.
                    delete asteroids[i];
                    delete lasers[k];
                    // removes the asteroid and laser objects from the vectors.
                    lasers.erase(lasers.begin() + k);
                    asteroids.erase(asteroids.begin() + i);
                    asteroid_removed = true;
                }
            }
        }
    }

    void GameState::LaserLanderCollision()
    {
        for (unsigned int i = 0; i < landers.size(); ++i)
        {
            bool lander_removed = false;

            for (unsigned int k = 0; k < lasers.size() && lander_removed == false; ++k)
            {
                if (lasers[k]->getBounds().intersects(landers[i]->getBounds()))
                {
                    // freeing up the memory allocated for the asteroid and laser object.
                    delete landers[i];
                    delete lasers[k];
                    // removes the asteroid and laser objects from the vectors.
                    lasers.erase(lasers.begin() + k);
                    landers.erase(landers.begin() + i);
                    lander_removed = true;
                }
            }
        }
    }

    void GameState::shipAsteroidCollision()
    {
        bool collided = false;
        
        for (unsigned int i = 0; i < asteroids.size(); ++i)
        {
            asteroids[i]->scale(0.625f);
            if (asteroids[i]->getBounds().intersects(spaceShip->getBounds()))
            {
                collided = true;
                break;
            }
        }
        if (collided)
        {
            _data->states.PushState(std::unique_ptr<State>(new GameOverState(_data)), true);
        }
    }

    void GameState::UpdateAsteroid(float dt)
    {
        for (unsigned int counter = 0; counter < asteroids.size(); counter++)
        {
            this->asteroids[counter]->Update(dt);
            if (asteroids[counter]->getBounds().top > _data->window.getSize().y)
            {
                delete asteroids[counter];
                asteroids.erase(asteroids.begin() + counter);
            }
        }
        std::cout << "sizeAsteroid: " << asteroids.size() << std::endl
                  << std::endl;
    }
    void GameState::checkCollision()
    {
        this->LaserAsteroidCollision();
        this->LaserLanderCollision();
        this->shipAsteroidCollision();
        //Need to check missile collision
    }
    void GameState::Update(float dt)
    {
        this->space->update(dt);
        this->spaceShip->update(dt);
        this->shootLasers();
        this->InitAsteroid();
        this->InitLander();
        this->UpdateLaser(dt);
        this->UpdateAsteroid(dt);
        this->UpdateLander(dt);
        this->checkCollision();
    }

    void GameState::Draw(float dt)
    {
        _data->window.clear();
        this->space->draw();
        this->spaceShip->draw();
        for (auto *laser : lasers)
        {
            laser->draw();
        }
        for (auto *asteroid : asteroids)
        {
            asteroid->draw();
        }
        for (auto *lander : landers)
        {
            lander->draw();
        }
        _data->window.display();
    }
}