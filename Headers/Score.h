#ifndef SCORE_H
#define SCORE_H

#include "Definations.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace EdgarSam
{
class Score
{
public:
 Score(GameDataPtr data);
 void UpdateScore(int score);
 static void UpdateHighScore(int score, int highscore);
 void draw();

 
private:
 GameDataPtr _data;
 sf::Text _scoreValue;
 static sf::Text _highestscore;

};
}
#endif