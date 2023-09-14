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
#include "Score.h"
#include <vector>
namespace EdgarSam
{
    class GameState : public State
    {
    public:
        GameState(GameDataPtr data);
        ~GameState();
        void InitScore();
        void InitState();
        void HandleInput();
        void checkCollision();
        void Update(float dt);
        void Draw(float dt);

    private:
        // data
        GameDataPtr _data;
        int randomIndex;
        //clock
        sf::Clock clock_1;
        sf::Clock clock_2;
        sf::Clock clock 3;


        int gamescore;
        int highscore;
        // functions

        void shootShipLasers();
        void shootLanderLasers();
         void UpdateShipLaser(float dt);
        void UpdateLanderLaser(float dt);
        void InitAsteroid();
         void InitLander();
        void UpdateAsteroid(float dt);
       
        void UpdateLander(float dt);
       
        
        template <typename G>
        void LaserCollision(G &enemy_1);
        //void LaserLanderCollision();
         template <typename T>
        void shipCollision(T &enemy);
        template <typename U>
        void draw(U &enemy)
        // Objects
        SpaceShip *spaceShip;
        Space *space;
        Score *score;
        std::vector<Lasers *> ship_lasers;
        std::vector<Asteroid *> asteroids;
        std::vector<Lander *> landers;
        std::vector<Lasers *> lander_lasers;
       
    };
}
#endif
