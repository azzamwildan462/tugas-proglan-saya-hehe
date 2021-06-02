#include "../include/mylib.h"
#include "../include/main_char.h"
#include "../include/others.h"
#include <cstdio>

using namespace sf;
int main()
{
    bool wPressed = 0;
    bool f10Pressed = 0;
    uint64_t timer = 1;
    bool isGameplayed = 1;

    RenderWindow window(VideoMode(800, 600), "Destroyer");
    Event event_handler;
    Vector2i cursor, cursor2;
    Cursor moveCursor, teleCursor;
    moveCursor.loadFromSystem(Cursor::Arrow);
    teleCursor.loadFromSystem(Cursor::Cross);
    window.setMouseCursor(moveCursor);

    if (!opening_game(&window, &event_handler, &cursor, &moveCursor))
        return 0;

    while (1)
    {
        if (!main_menu(&window, &event_handler, &cursor, &moveCursor)) //play = retuern 1
            return 0;

        if (!game1(&window, &event_handler, &cursor, &moveCursor, &teleCursor, &cursor2))
        {
            return 0;
        }
        // else
        // {
        //     // printf("go TO MAIN menu");
        //     if (!main_menu(&window, &event_handler, &cursor, &moveCursor))
        //         return 0;
        // }
    }

    return 0;
}