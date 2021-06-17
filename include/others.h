#ifndef OTHERS_H
#define OTHERS_H

#include "initlib.h"

#include <cstdio>
class Bullet
{
private:
    //==== Variabel ====
    float x0 = 200, y0 = 90;
    float angle = 0;
    float xpos = 100, ypos = 100;
    float xtar, ytar;
    float dx, dy, r;
    float scale = 5;
    float speed = 0.7;
    bool hitted = 0;
    float bullet_color[4] = {145, 18, 9, 255};

    //==== Instance ====
    sf::RenderWindow *window;
    sf::CircleShape body;

public:
    //==== Method ====

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
    //==== Variabel ====
    float dx, dy, r;
    float xpos = 400, ypos = 400;
    float xtar, ytar;
    float angle = 0;
    float scale = 50;
    float x_bullet_from_tank = 300, y_bullet_from_tank = 300;
    float player_color[4] = {150, 0, 176, 200};
    bool destroyed = 0;
    bool hitted = 0;
    int HP = 100;
    int damage = 10;
    bool set_first = 0;
    bool fire_ing = 0;
    bool bullet_hitted = 0;
    bool destroyed_sound_played = 0;
    bool hitted_sound_played = 0;

    //==== Instance ====
    sf::CircleShape body, head;
    sf::RectangleShape gun;
    sf::RenderWindow *window;
    sf::Text Hitpoints;
    sf::SoundBuffer tower_destroy, tower_fire, tower_hitted;
    sf::Sound tower_destroy_sound, tower_fire_sound, tower_hitted_sound;

public:
    //==== Variabel ====
    bool time_to_fire = 0;

    //==== Instance ====
    Bullet bullet;
    sf::Font font;

    //==== Methods ====
    Enemy();
    void setPosition(float xpos, float ypos);
    void init();
    void setWindow(sf::RenderWindow *window);
    void draw();
    void setColor(float r, float g, float b, float a);
    void findTarget(float xtar, float ytar);
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