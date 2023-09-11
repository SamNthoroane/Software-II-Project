#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "StateManager.h"
#include "InputManager.h"
#include "Game.h"
#include "SpaceShip.h"
#include "Space.h"
#include "Lasers.h"
#include "Asteroid.h"
#include "Lander.h"
#include <vector>
namespace EdgarSam
{
    class GameState : public State
    {
    public:
        GameState(GameDataPtr data);
        ~GameState();
        void InitState();
        void HandleInput();
        void checkCollision();
        void Update(float dt);
        void Draw(float dt);

    private:
        // data
        GameDataPtr _data;
        sf::Clock clock_1;
        sf::Clock clock_2;
        // functions
        void shootLasers();
        void UpdateLaser(float dt);
        void InitAsteroid();
        void UpdateAsteroid(float dt);
        void InitLander();
        void UpdateLander(float dt);
        void LaserAsteroidCollision();
        void LaserLanderCollision();
        void shipAsteroidCollision();
        // Objects
        SpaceShip *spaceShip;
        Space *space;
        std::vector<Lasers *> lasers;
        std::vector<Asteroid *> asteroids;
        std::vector<Lander *> landers;
    };
}
#endif
