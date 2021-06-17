#ifndef MAIN_CHAR_H
#define MAIN_CHAR_H

#include "initlib.h"
#include "../include/others.h"
#include <cstdio>

class MainChar
{
private:
    //==== variabel ====
    int xtar = 400, ytar = 500;
    float dx = 0, dy = -0.5, r = 0;
    float angle = 0;
    float player_color[4] = {150, 0, 176, 200};
    float scale = 0.7;
    float xpos = 400, ypos = 500;
    float speed = 0.4;
    bool fire_ing = 0;
    bool set_first = 0;
    bool bullet_hitted = 0;
    float HP = 100;
    float hit_area_x = 70, hit_area_y = 105; //kali 0.7

    //==== sounding ====
    bool is_tank_hitted_sound = 0;

    //==== instance ====
    sf::RectangleShape body, head, gun, color, Hitpoints;
    sf::RenderWindow *window;
    Bullet bullet;
    sf::SoundBuffer tank_hitted, tank_fire, tank_move;
    sf::Sound tank_hitted_sound, tank_fire_sound, tank_move_sound;
    // sf::Music gas;

public:
    //==== method ====
    MainChar();
    void init();
    void setPosition(float xpos, float ypos, float angle);
    void draw();
    void getPosition(float *xpos, float *ypos);
    float getXpos();
    float getypos();
    void setRotation(float angle);
    void setplayer_color(float r, float g, float b, float a);
    void setAngle(float angle);
    void move(sf::Vector2i cursor);
    bool isMove();
    float getAngle();
    void setScale(float scale);
    void setSpeed(float speed);
    void setWindow(sf::RenderWindow *window);
    void fire();
    bool isFire();
    float getXbullet();
    float getYbullet();
    float getHitBullet();
    void setHitBullet(bool isbullet_hitted);
    void setTarPos(float x, float y);
    void teleport(float xpos, float ypos);
    void setHP(float hp);
    float getHP();
    bool isHittedFrom(float x, float y);
};
#endif