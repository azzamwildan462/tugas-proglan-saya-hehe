#include "../include/others.h"
#include "../include/mylib.h"

void Bullet::init()
{
    this->body.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->body.setRadius(scale);
    this->body.setOrigin(sf::Vector2f(this->body.getRadius(), this->body.getRadius()));
    this->body.setFillColor(sf::Color(this->bullet_color[0], this->bullet_color[1], this->bullet_color[2], this->bullet_color[3]));
    this->body.setOutlineThickness(3);
    this->body.setOutlineColor(sf::Color(87, 32, 26, 200));
    this->body.setRotation(this->angle);
    // this->body.rotate(90);
}
void Bullet::draw()
{
    Bullet::init();
    if (!Bullet::isHitted())
    {
        this->window->draw(body);
    }
}
void Bullet::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}
void Bullet::setDxDyR(float dx, float dy, float r)
{
    this->dx = dx;
    this->dy = dy;
    this->r = r;
}
void Bullet::move()
{
    if (this->isMove())
    {
        this->xpos += this->dx * this->speed;
        this->ypos += this->dy * this->speed;
        // printf("%f %f %f\n", this->dx, this->dy, this->speed);
    }
    else
    {
        Bullet::init();
    }
}
bool Bullet::isMove()
{
    if (!Bullet::isHitted())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Bullet::isHitted()
{
    return this->hitted;
}
void Bullet::setHit(bool state)
{
    this->hitted = state;
}
void Bullet::setPosition(float xpos, float ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}
float Bullet::getXpos()
{
    return this->xpos;
}
float Bullet::getYpos()
{
    return this->ypos;
}
void Bullet::setSpeed(float speed)
{
    this->speed = speed;
}
void Bullet::setColor(float r, float g, float b, float a)
{
    this->bullet_color[0] = r;
    this->bullet_color[1] = g;
    this->bullet_color[2] = b;
    this->bullet_color[3] = a;
}

//Ini pembatas jadi hiraukan sj :)
void Enemy::init()
{
    this->body.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->body.setRadius(scale);
    this->body.setOrigin(sf::Vector2f(this->body.getRadius(), this->body.getRadius()));
    this->body.setFillColor(sf::Color(87, 68, 68, 255));
    this->body.setOutlineThickness(3);
    this->body.setOutlineColor(sf::Color(54, 43, 43, 200));

    this->head.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->head.setRadius(scale * 5 / 8);
    this->head.setOrigin(sf::Vector2f(this->head.getRadius(), this->head.getRadius()));
    this->head.setFillColor(sf::Color(this->player_color[0], this->player_color[1], this->player_color[2], this->player_color[3]));
    this->head.setOutlineThickness(1);
    this->head.setOutlineColor(sf::Color(107, 10, 10, 200));

    this->gun.setPosition(sf::Vector2f(this->xpos, this->ypos));
    this->gun.setSize(sf::Vector2f(10, 150));
    this->gun.setScale(sf::Vector2f(this->scale / 75, this->scale / 75));
    this->gun.setOrigin(sf::Vector2f(5, 150));
    this->gun.setFillColor(sf::Color(this->player_color[0] + 20, this->player_color[1] + 20, this->player_color[2] + 20, this->player_color[3]));
    this->gun.setOutlineThickness(1);
    this->gun.setOutlineColor(sf::Color(0, 3, 153, 255));
    this->gun.setRotation(this->angle);

    std::string label("HP: ");
    std::string value(std::to_string(this->HP));
    label += value;
    this->Hitpoints.setFont(font);
    this->Hitpoints.setPosition(sf::Vector2f(this->xpos - 50, this->ypos + 70));
    this->Hitpoints.setString(label);
    this->Hitpoints.setCharacterSize(24);
    this->Hitpoints.setFillColor(sf::Color(((100 - this->HP) * 255 / 100), (255 - ((100 - this->HP) * 255 / 100)), 0, 255));
}
void Enemy::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}
void Enemy::draw()
{
    if (!Enemy::isDestroy() && !this->destroyed)
    {
        Enemy::init();
        this->window->draw(body);
        this->window->draw(gun);
        this->window->draw(head);
        this->window->draw(Hitpoints);
        if (this->fire_ing)
        {
            this->bullet.draw();
        }
    }
}
void Enemy::setPosition(float xpos, float ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}
void Enemy::setColor(float r, float g, float b, float a)
{
    this->player_color[0] = r;
    this->player_color[1] = g;
    this->player_color[2] = b;
    this->player_color[3] = a;
}
void Enemy::setAngle(float angle)
{
    this->angle = angle;
}
void Enemy::find_target(float xtar, float ytar)
{
    this->angle = findDirection(this->xpos, this->ypos, xtar, ytar);
    this->dx = xtar - this->xpos;
    this->dy = ytar - this->ypos;
    this->r = find_r(this->dx, this->dy);
    this->dx /= this->r;
    this->dy /= this->r;
}
void Enemy::setRelationWithTank(float xBulletPos, float yBulletPos)
{
    this->x_bullet_from_tank = xBulletPos;
    this->y_bullet_from_tank = yBulletPos;
}
bool Enemy::isHitted()
{
    this->x_bullet_from_tank -= this->xpos;
    this->y_bullet_from_tank -= this->ypos;

    if (x_bullet_from_tank < 0)
        x_bullet_from_tank *= -1;
    if (y_bullet_from_tank < 0)
        y_bullet_from_tank *= -1;

    if (this->x_bullet_from_tank < this->scale && this->y_bullet_from_tank < this->scale)
    {
        this->HP -= this->damage;
        this->hitted = 1;
        return 1;
    }
    else
        return 0;
}
float Enemy::getHP()
{
    return this->HP;
}
bool Enemy::isDestroy()
{
    if (this->HP <= 0)
    {
        if (!destroyed_sound_played)
        {
            tower_destroy_sound.play();
            destroyed_sound_played = 1;
        }
        this->xpos = 0;
        this->ypos = 0;
        this->scale = 0;
        this->destroyed = 1;
        return 1;
    }
    else
        return 0;
}
void Enemy::setDamagefromTank(int damage)
{
    this->damage = damage / 2;
}
void Enemy::fire()
{
    if (!this->set_first)
    {
        this->bullet.setPosition(this->xpos, this->ypos);
        this->bullet.setDxDyR(this->dx, this->dy, this->r);
        this->bullet.setWindow(this->window);
        this->bullet.setSpeed(0.5);
        this->bullet.setColor(this->player_color[0], this->player_color[1], this->player_color[2], this->player_color[3]);
        this->bullet.setHit(0);
        this->tower_fire_sound.play();
        this->set_first = 1;
        // this->bullet_hitted = 0;
    }
    this->fire_ing = 1;
    this->bullet.move();
    if (this->bullet.getXpos() <= 0 || this->bullet.getXpos() >= 800 || this->bullet.getYpos() <= 0 || this->bullet.getYpos() >= 800 || this->bullet_hitted)
    {
        // this->bullet_hitted = 1;
        this->bullet.setHit(1);
        this->set_first = 0;
        this->fire_ing = 0;
        this->time_to_fire = 0;
    }
}
void Enemy::setbullet_hitted(bool state)
{
    this->bullet.setHit(state);
    this->set_first = !state;
    this->fire_ing = !state;
    this->time_to_fire = !state;
}

Enemy::Enemy()
{
    if (tower_destroy.loadFromFile("../asset/audio/effects/tower_destroy.wav"))
        ;
    tower_destroy_sound.setBuffer(tower_destroy);

    if (tower_fire.loadFromFile("../asset/audio/effects/tower_fire.wav")) //bermasalah dengan file
        ;
    tower_fire_sound.setBuffer(tower_fire);

    if (tower_hitted.loadFromFile("../asset/audio/effects/tower_hitted.wav")) //bermasalah dengan file
        ;
    tower_hitted_sound.setBuffer(tower_hitted);
}