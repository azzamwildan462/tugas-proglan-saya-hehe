#include "../include/mylib.h"
#include "../include/main_char.h"
#include "../include/others.h"
#include "../include/koneksi.h"
#include <cstdio>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Destroyer");
    Event event_handler;
    Vector2i cursor, cursor2;
    Cursor move_cursor, tele_cursor;
    move_cursor.loadFromSystem(Cursor::Arrow);
    tele_cursor.loadFromSystem(Cursor::Cross);
    window.setMouseCursor(move_cursor);

    // Koneksi *koneksi = Koneksi::getInstance();

    // Thread koneksi_thread(&Koneksi::loop, Koneksi::getInstance());
    // koneksi_thread.launch();

    if (!openingGame(&window, &event_handler, &cursor, &move_cursor))
    {
        // koneksi_thread.terminate();
        return 0;
    }

    while (1)
    {
        if (!mainMenu(&window, &event_handler, &cursor, &move_cursor)) //play = retuern 1
        {
            // koneksi_thread.terminate();
            return 0;
        }

        if (!game1(&window, &event_handler, &cursor, &move_cursor, &tele_cursor, &cursor2))
        {
            // koneksi_thread.terminate();
            return 0;
        }
    }

    // koneksi_thread.terminate();
    return 0;
}