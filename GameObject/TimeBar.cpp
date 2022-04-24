#include "TimeBar.h"
#include "../Scene/LevelScene.h"

TimeBar::TimeBar()
    :timerBarWidthPerSecond(0.f), timeMax(0.f), timeRemaining(timeMax)
{

}

void TimeBar::init(float timeMax)
{
    float timeBarWidth = 400;
    float timerBarHeight = 80;
    
    timerBarSize = sf::Vector2f(timeBarWidth, timerBarHeight);
    rs.setSize(timerBarSize);

    sf::Vector2f timerPos = sf::Vector2f(1920 * 0.5f - timeBarWidth * 0.5f, 980.f);
    rs.setPosition(timerPos);

    rs.setFillColor(sf::Color::Red);

    this->timeMax = timeMax;
    timeRemaining = timeMax;
    timerBarWidthPerSecond = timeBarWidth / timeMax;
}

TimeBar::~TimeBar()
{

}

void TimeBar::HanddleInput(sf::Keyboard::Key key, int score)
{
    switch (key)
    {
    case sf::Keyboard::Return:
        timeRemaining = timeMax;
        break;
    case sf::Keyboard::Left:
    case sf::Keyboard::Right:
        timeRemaining += (2 / score) + 0.15f;
        timeRemaining += 2.15f;
        if (timeRemaining > timeMax)
        {
            timeRemaining = timeMax;
        }
        break;
    default:
        break;
    }
}

void TimeBar::Update(float dt)
{
    timeRemaining -= dt;
    timerBarSize.x = timeRemaining * timerBarWidthPerSecond;
    rs.setSize(timerBarSize);
}

bool TimeBar::IsEnd()
{
    if (timeRemaining < 0.f) {
        timerBarSize.x = 0.f;
        rs.setSize(timerBarSize);
        return true;
    }
    return false;
}

void TimeBar::Render(sf::RenderWindow& window)
{
    window.draw(rs);
}
