
#include "../include/main_char.h"
#include "../include/mylib.h"

void main_char::draw()
{
    this->init();
    this->window->draw(this->body);
    this->window->draw(this->head);
    this->window->draw(this->gun);
    this->window->draw(this->color);
    this->window->draw(this->Hitpoints);

    if (this->fire_ing)
    {
        // this->bullet.move();
        this->bullet.draw();
    }
}

void main_char::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void main_char::init()
{
    this->body.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->body.setSize(sf::Vector2f(100, 150));
    this->body.setScale(sf::Vector2f(this->scale, this->scale));
    this->body.setOrigin(sf::Vector2f(50, 75));
    this->body.setFillColor(sf::Color(145, 18, 9, 255));
    this->body.setOutlineThickness(10);
    this->body.setOutlineColor(sf::Color(87, 32, 26, 200));
    this->body.setRotation(this->angle);

    this->head.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->head.setSize(sf::Vector2f(50, 75));
    this->head.setScale(sf::Vector2f(this->scale, this->scale));
    this->head.setOrigin(sf::Vector2f(25, 37.5));
    this->head.setFillColor(sf::Color(166, 60, 7, 255));
    this->head.setOutlineThickness(5);
    this->head.setOutlineColor(sf::Color(0, 140, 179, 255));
    this->head.setRotation(this->angle);

    this->gun.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->gun.setSize(sf::Vector2f(10, 150));
    this->gun.setScale(sf::Vector2f(this->scale, this->scale));
    this->gun.setOrigin(sf::Vector2f(5, 150));
    this->gun.setFillColor(sf::Color(194, 65, 0, 255));
    this->gun.setOutlineThickness(1);
    this->gun.setOutlineColor(sf::Color(0, 3, 153, 255));
    this->gun.setRotation(this->angle);

    this->color.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->color.setSize(sf::Vector2f(80, 40));
    this->color.setScale(sf::Vector2f(this->scale, this->scale));
    this->color.setOrigin(sf::Vector2f(40, 20));
    this->color.setFillColor(sf::Color(this->playerColor[0], this->playerColor[1], this->playerColor[2], this->playerColor[3]));
    this->color.setOutlineThickness(2);
    this->color.setOutlineColor(sf::Color(170, 0, 196, 255));
    this->color.setRotation(this->angle);

    this->Hitpoints.setPosition(sf::Vector2f(0, 570));
    this->Hitpoints.setSize(sf::Vector2f((this->HP * 8), 30));
    this->Hitpoints.setOutlineThickness(2);
    this->Hitpoints.setOutlineColor(sf::Color(255, 255, 255, 255));
    this->Hitpoints.setFillColor(sf::Color(((100 - this->HP) * 255 / 100), (255 - ((100 - this->HP) * 255 / 100)), 0, 255));
}

void main_char::getPosition(float *xpos, float *ypos)
{
    *xpos = this->xpos;
    *ypos = this->ypos;
}
float main_char::getXpos()
{
    return this->xpos;
}
float main_char::getypos()
{
    return this->ypos;
}
void main_char::setRotation(float angle)
{
    this->body.setRotation(angle);
    this->head.setRotation(angle);
    this->gun.setRotation(angle);
    this->color.setRotation(angle);
}
void main_char::setPlayerColor(float r, float g, float b, float a)
{
    this->playerColor[0] = r;
    this->playerColor[1] = g;
    this->playerColor[2] = b;
    this->playerColor[3] = a;
}
void main_char::setPosition(float xpos, float ypos, float angle)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->angle = angle;
}
void main_char::setAngle(float angle)
{
    this->angle = angle;
}
void main_char::move(sf::Vector2i cursor)
{
    if (this->isMove())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            cursor = sf::Mouse::getPosition(*this->window);
            this->angle = find_direction(this->xpos, this->ypos, cursor.x, cursor.y);
            this->xtar = cursor.x;
            this->ytar = cursor.y;
            this->dx = xtar - this->xpos;
            this->dy = ytar - this->ypos;
            this->r = find_r(this->dx, this->dy);
            this->dx /= this->r;
            this->dy /= this->r;
        }
        this->xpos += this->dx * this->speed;
        this->ypos += this->dy * this->speed;
    }
    else
    {
        this->angle = find_direction(this->xpos, this->ypos, cursor.x, cursor.y);
        this->xtar = cursor.x;
        this->ytar = cursor.y;
        // main_char::init();
    }
}
float main_char::getAngle()
{
    return this->angle;
}
void main_char::setScale(float scale)
{
    this->scale = scale;
}
bool main_char::isMove()
{
    if (this->xtar <= this->xpos + 1 && this->xtar >= this->xpos - 1 && this->ytar <= this->ypos + 1 && this->ytar >= this->ypos - 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void main_char::setSpeed(float speed)
{
    this->speed = speed;
}
void main_char::fire()
{
    if (!this->setFirst)
    {
        // this->bulletHitted = 0;
        this->bullet.setPosition(this->xpos, this->ypos);
        this->bullet.setDxDyR(this->dx, this->dy, this->r);
        this->bullet.setWindow(this->window);
        this->bullet.setHit(0);
        this->setFirst = 1;
        // printf("%f %f %f\n", this->dx, this->dy, this->r);
    }
    this->fire_ing = 1;
    this->bullet.move();
    if (this->bullet.getXpos() <= 0 || this->bullet.getXpos() >= 800 || this->bullet.getYpos() <= 0 || this->bullet.getYpos() >= 800 || this->bulletHitted)
    {
        // this->bulletHitted = 1;
        this->bullet.setHit(1);
        this->setFirst = 0;
        this->fire_ing = 0;
    }
}
bool main_char::isFire()
{
    return this->fire_ing;
}
float main_char::getXbullet()
{
    return this->bullet.getXpos();
}
float main_char::getYbullet()
{
    return this->bullet.getYpos();
}
float main_char::getHitBullet()
{
    return this->bullet.isHitted();
}
void main_char::setHitBullet(bool isBullethitted)
{
    this->bulletHitted = isBullethitted;
}
void main_char::setTarPos(float x, float y)
{
    this->xpos = x;
    this->ypos = y;
    this->xtar = x;
    this->ytar = y;
}
void main_char::teleport(float xpos, float ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->xtar = xpos;
    this->ytar = ypos;
}
void main_char::setHP(float hp)
{
    this->HP = hp;
}
float main_char::getHP()
{
    return this->HP;
}
bool main_char::isHittedFrom(float x, float y)
{
    x -= this->xpos;
    y -= this->ypos;
    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    if (x < this->hitAreaX && y < this->hitAreaY)
    {
        this->HP -= 10;
        return 1;
    }
    else
        return 0;
}