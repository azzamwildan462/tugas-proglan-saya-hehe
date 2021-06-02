#ifndef OTHERS_H
#define OTHERS_H

#include "initlib.h"

#include <cstdio>
class Bullet
{
private:
    float x0 = 200, y0 = 90;
    float angle = 0;
    float xpos = 100, ypos = 100;
    float xtar, ytar;
    float dx, dy, r;
    float scale = 5;
    float speed = 0.7;
    bool hitted = 0;
    float bulletColor[4] = {145, 18, 9, 255};
    sf::RenderWindow *window;
    sf::CircleShape body;

public:
    void init();
    void move();
    bool isMove();
    bool isHitted();
    void draw();
    void setHit(bool state);
    void setDxDyR(float dx, float dy, float r);
    void setWindow(sf::RenderWindow *window);
    void setPosition(float xpos, float ypos);
    void setAngle(float angle);
    float getXpos();
    float getYpos();
    void setSpeed(float speed);
    void setColor(float r, float g, float b, float a);
};

class Enemy
{
private:
    float dx, dy, r;
    float xpos = 400, ypos = 400;
    float xtar, ytar;
    float angle = 0;
    float scale = 50;
    float xBulletFromTank = 300, yBulletFromTank = 300;
    float playerColor[4] = {150, 0, 176, 200};
    bool destroyed = 0;
    bool hitted = 0;
    int HP = 100;
    int damage = 10;
    bool setfirst = 0;
    bool fire_ing = 0;
    bool bulletHitted = 0;
    sf::CircleShape body, head;
    sf::RectangleShape gun;
    sf::RenderWindow *window;
    sf::Text Hitpoints;

public:
    bool timeToFire = 0;
    Bullet bullet;
    sf::Font font;
    void setPosition(float xpos, float ypos);
    void init();
    void setWindow(sf::RenderWindow *window);
    void draw();
    void setColor(float r, float g, float b, float a);
    void find_target(float xtar, float ytar);
    void setAngle(float angle);
    void fire();
    bool isFire();
    void setRelationWithTank(float xBulletPos, float yBulletPos);
    float getHP();
    bool isHitted();
    bool isDestroy();
    void setDamagefromTank(int damage);
    void setBulletHitted(bool state);
};

#endif