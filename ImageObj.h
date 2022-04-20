#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class side {
    LEFT,
    RIGNT,
    NONE
};

class ImageObj {
private:
    Sprite sprite;

    Vector2f speed;

    bool active;

public:
    ImageObj(Texture& texture, int posX, int posY);

    ImageObj(Texture& texture, int posX, int posY, bool active);

    ImageObj(Texture& texture, int posX, int posY, bool active, float speedX, float speedY);

    void setPosition(int x, int y);

    void setPosition(Vector2f pos);

    void setRotation(float angle);

    void setOrigin(int x, int y);

    const Vector2f& getPosition() const;

    void setSpeed(float x, float y);

    void setActive(bool active);

    bool getAtive() const;

    const Vector2f& getSpeed() const;

    const Sprite& getSprite() const;

    //friend void RenderWindow::draw(const ImageObj imgObj, const RenderStates& states = RenderStates::Default);

    ~ImageObj();
};