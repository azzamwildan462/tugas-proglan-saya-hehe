
#ifndef MYLIB_H
#define MYLIB_H

#include "initlib.h"

float findDirection(float xpos, float ypos, float xtarget, float ytarget);
void heavyRotation(float xpos, float ypos, float x0, float y0, float *xrot, float *yrot, float angle);
void linearLine(float x, float *y, float x0, float y0, float x1, float y1);
void linearLineInvers(float *x, float y, float x0, float y0, float x1, float y1);
float find_r(float x, float y);
bool openingGame(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor);
bool mainMenu(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor);
bool victory(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor);
int gameOver(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor);
int game1(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor, sf::Cursor *tele_cursor, sf::Vector2i *cursor2);

#endif