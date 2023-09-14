#include "Score.h"


namespace EdgarSam
{

Score::Score(GameDataPtr data) : _data{data}
{
//Load Font
 this->_data->assets.AddFont("ScoreFont", MAINMENU_FONT);
//Setting the font
this->_scoreValue.setFont(_data->assets.getFont("ScoreFont"));
this->_scoreValue.setString("0");
this->_scoreValue.setCharacterSize(20);
this->_scoreValue.setFillColor(sf::Color::Green);
this->_scoreValue.setPosition(_data->window.getSize().x/20,_data->window.getSize().y/50);

this->_highestscore.setFont(_data->assets.getFont("ScoreFont"));
this->_highestscore.setString("0");
this->_highestscore.setCharacterSize(20);
this->_highestscore.setFillColor(sf::Color::Green);
this->_highestscore.setPosition(_data->window.getSize().x/20,_data->window.getSize().y/50);

}

void Score::UpdateScore(int score)
{

 _scoreValue.setString("Current Score: " + std::to_string(score));

 

}
static void Score::UpdateHighScore(int score, int highscore)
{

 if (score > highscore)
 {
    highscore = score;
    _highestscore.setString("Highest Score: " + std::to_string(highscore));

 }
}
void Score::draw()
{

_data->window.draw(_scoreValue);
_data->window.draw(_highestscore);

}



}