
#include "../include/main_char.h"
#include "../include/mylib.h"

void MainChar::draw()
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

void MainChar::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void MainChar::init()
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
    this->color.setFillColor(sf::Color(this->player_color[0], this->player_color[1], this->player_color[2], this->player_color[3]));
    this->color.setOutlineThickness(2);
    this->color.setOutlineColor(sf::Color(170, 0, 196, 255));
    this->color.setRotation(this->angle);

    this->Hitpoints.setPosition(sf::Vector2f(0, 570));
    this->Hitpoints.setSize(sf::Vector2f((this->HP * 8), 30));
    this->Hitpoints.setOutlineThickness(2);
    this->Hitpoints.setOutlineColor(sf::Color(255, 255, 255, 255));
    this->Hitpoints.setFillColor(sf::Color(((100 - this->HP) * 255 / 100), (255 - ((100 - this->HP) * 255 / 100)), 0, 255));
}

void MainChar::getPosition(float *xpos, float *ypos)
{
    *xpos = this->xpos;
    *ypos = this->ypos;
}
float MainChar::getXpos()
{
    return this->xpos;
}
float MainChar::getypos()
{
    return this->ypos;
}
void MainChar::setRotation(float angle)
{
    this->body.setRotation(angle);
    this->head.setRotation(angle);
    this->gun.setRotation(angle);
    this->color.setRotation(angle);
}
void MainChar::setplayer_color(float r, float g, float b, float a)
{
    this->player_color[0] = r;
    this->player_color[1] = g;
    this->player_color[2] = b;
    this->player_color[3] = a;
}
void MainChar::setPosition(float xpos, float ypos, float angle)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->angle = angle;
}
void MainChar::setAngle(float angle)
{
    this->angle = angle;
}
void MainChar::move(sf::Vector2i cursor)
{
    if (this->isMove())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //ngambil target baru
        {
            cursor = sf::Mouse::getPosition(*this->window);
            this->angle = findDirection(this->xpos, this->ypos, cursor.x, cursor.y);
            this->xtar = cursor.x;
            this->ytar = cursor.y;
            this->dx = xtar - this->xpos;
            this->dy = ytar - this->ypos;
            this->r = findR(this->dx, this->dy);
            this->dx /= this->r;
            this->dy /= this->r;
            tank_move_sound.play();
        }
        this->xpos += this->dx * this->speed;
        this->ypos += this->dy * this->speed;
    }
    else
    {
        this->angle = findDirection(this->xpos, this->ypos, cursor.x, cursor.y);
        this->xtar = cursor.x;
        this->ytar = cursor.y;
        // MainChar::init();
    }
}
float MainChar::getAngle()
{
    return this->angle;
}
void MainChar::setScale(float scale)
{
    this->scale = scale;
}
bool MainChar::isMove()
{
    if (this->xtar <= this->xpos + 1 && this->xtar >= this->xpos - 1 && this->ytar <= this->ypos + 1 && this->ytar >= this->ypos - 1)
    { //kalo sudah sampek
        return 0;
    }
    else
    { //kalo belum sampek maka jalan
        return 1;
    }
}
void MainChar::setSpeed(float speed)
{
    this->speed = speed;
}
void MainChar::fire()
{
    if (!this->set_first)
    {
        // this->bullet_hitted = 0;
        this->bullet.setPosition(this->xpos, this->ypos);
        this->bullet.setDxDyR(this->dx, this->dy, this->r);
        this->bullet.setWindow(this->window);
        this->bullet.setHit(0);
        tank_fire_sound.play();
        // tank_move_sound.play();
        this->set_first = 1;
        // printf("%f %f %f\n", this->dx, this->dy, this->r);
    }
    this->fire_ing = 1;
    this->bullet.move();
    if (this->bullet.getXpos() <= 0 || this->bullet.getXpos() >= 800 || this->bullet.getYpos() <= 0 || this->bullet.getYpos() >= 800 || this->bullet_hitted)
    {
        // this->bullet_hitted = 1;
        this->bullet.setHit(1);
        this->set_first = 0;
        this->fire_ing = 0;
    }
}
bool MainChar::isFire()
{
    return this->fire_ing;
}
float MainChar::getXbullet()
{
    return this->bullet.getXpos();
}
float MainChar::getYbullet()
{
    return this->bullet.getYpos();
}
float MainChar::getHitBullet()
{
    return this->bullet.isHitted();
}
void MainChar::setHitBullet(bool isbullet_hitted)
{
    this->bullet_hitted = isbullet_hitted;
}
void MainChar::setTarPos(float x, float y)
{
    this->xpos = x;
    this->ypos = y;
    this->xtar = x;
    this->ytar = y;
}
void MainChar::teleport(float xpos, float ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->xtar = xpos;
    this->ytar = ypos;
}
void MainChar::setHP(float hp)
{
    this->HP = hp;
}
float MainChar::getHP()
{
    return this->HP;
}
bool MainChar::isHittedFrom(float x, float y)
{
    is_tank_hitted_sound = 0;
    x -= this->xpos;
    y -= this->ypos;
    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    if (x < this->hit_area_x && y < this->hit_area_y)
    {
        if (!is_tank_hitted_sound)
        {
            tank_hitted_sound.play();
            is_tank_hitted_sound = 1;
        }
        this->HP -= 10;
        return 1;
    }
    else
        return 0;
}

MainChar::MainChar()
{
    if (tank_fire.loadFromFile("../asset/audio/effects/tank_fire.wav"))
        ;
    tank_fire_sound.setBuffer(tank_fire);
    tank_fire_sound.setVolume(60);
    // tank_fire_sound.setPosition(sf::Vector3f(this->xpos, this->ypos, 1));

    if (tank_hitted.loadFromFile("../asset/audio/effects/tank_hitted.wav"))
        ;
    tank_hitted_sound.setBuffer(tank_hitted);
    tank_hitted_sound.setVolume(50);

    if (tank_move.loadFromFile("../asset/audio/effects/tank_move.wav"))
        ;
    tank_move_sound.setBuffer(tank_move);
}