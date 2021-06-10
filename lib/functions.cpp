#include "../include/mylib.h"
#include "../include/main_char.h"
#include "../include/others.h"
#include "math.h"

float find_direction(float xpos, float ypos, float xtarget, float ytarget)
{
    float result, temp;
    xtarget -= xpos;
    ytarget -= ypos;

    temp = sqrt((xtarget * xtarget) + (ytarget * ytarget));
    if (xtarget >= 0 && ytarget >= 0 || xtarget >= 0 && ytarget < 0)
    {
        result = asin(ytarget / temp);
    }
    else if (xtarget >= 0 && ytarget >= 0 || xtarget < 0 && ytarget >= 0)
    {
        result = acos(xtarget / temp);
    }
    else if (xtarget < 0 && ytarget < 0)
    {
        xtarget *= -1;
        ytarget *= -1;
        result = asin(ytarget / temp);
        result += (180 / 180) * 3.141592653589793238;
    }
    result *= 180 / 3.141592653589793238;
    return result + 90;
}
void heavy_rotation(float xpos, float ypos, float x0, float y0, float *xrot, float *yrot, float angle)
{
    angle *= 3.141592653589793238 / 180;
    x0 -= xpos;
    y0 -= ypos;
    *xrot = (cos(angle) * x0) + (-1 * sin(angle) * y0) + xpos;
    *yrot = (sin(angle) * x0) + (cos(angle) * y0) + ypos;
}
void linear_line(float x, float *y, float x0, float y0, float x1, float y1)
{
    *y = ((y1 - y0) * (x - x0) / (x1 - x0)) + y0;
}
void linear_line_invers(float *x, float y, float x0, float y0, float x1, float y1)
{
    *x = ((x1 - x0) * (y - y0) / (y1 - y0)) + x0;
}

float find_r(float x, float y)
{
    return sqrt(x * x + y * y);
}
bool opening_game(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor)
{
    //170, 30, 199
    int r = 170, g = 30, b = 199;
    int counter = 1;
    int loadVal = 0;
    bool up = 1;
    bool windowClosed = 0;
    sf::Text loadText, titleText, tagName;
    sf::Font font, font2; //fon2 = arial
    sf::RectangleShape loadGraph;
    font.loadFromFile("../asset/fonts/font1.ttf");
    font2.loadFromFile("../asset/fonts/arial.ttf");

    loadText.setFont(font);
    loadText.setString("Loading, Please wait..");
    loadText.setPosition(sf::Vector2f(225, 200));
    loadText.setCharacterSize(60);
    loadText.setFillColor(sf::Color(198, 16, 235, 255));

    titleText.setFont(font);
    titleText.setString("Destroyer");
    titleText.setPosition(sf::Vector2f(280, 50));
    titleText.setCharacterSize(90);
    titleText.setFillColor(sf::Color(r, g, b, 255));

    tagName.setFont(font2);
    tagName.setString("Azzam Wildan Maulana - 5024201010");
    tagName.setPosition(sf::Vector2f(130, 500));
    tagName.setCharacterSize(30);
    tagName.setFillColor(sf::Color(11, 227, 216, 255));

    loadGraph.setPosition(sf::Vector2f(100, 300));
    loadGraph.setSize(sf::Vector2f(loadVal, 50));
    loadGraph.setFillColor(sf::Color(0, 234, 212, 255));

    while (1)
    {
        // printf("%d\n", windowClosed);
        // printf("%d %d %d\n", r, g, b);
        if (counter >= 10000)
        {
            counter = 1;
        }

        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                window->close();
                windowClosed = 1;
                return 0;
            }
        }
        window->clear(sf::Color(0, 0, 0, 255));
        if (windowClosed)
            break;

        titleText.setFillColor(sf::Color(r, g, b, 255));
        loadGraph.setSize(sf::Vector2f(loadVal, 50));

        window->draw(titleText);
        window->draw(loadText);
        window->draw(tagName);
        window->draw(loadGraph);

        window->display();
        counter++;
        if (counter % 20 == 0)
        {
            if (r >= 211 && g <= 0 && b >= 255 || g == 0)
            {
                up = 0;
            }
            else if (r <= 180 && g >= 45 && r <= 189)
            {
                up = 1;
            }
            if (up)
            {
                r++;
                g--;
                b++;
            }
            else
            {
                r--;
                g++;
                b--;
            }
        }
        if (counter % 10 == 0)
        {
            if (loadVal <= 600)
            {
                loadVal++;
            }
            else
            {
                break;
            }
        }
    }
    return 1;
}
int singlePlayerMainMenu(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor)
{
    int r = 170, g = 30, b = 199;
    int counter = 1;
    bool up = 1;
    bool startisClicked = 0, backisClicked = 0;
    sf::Text startText, backText, hintText, hintTitleText, objectiveText;
    sf::VertexArray hintCover(sf::LinesStrip, 5);
    sf::Font font1, font;
    font1.loadFromFile("../asset/fonts/font2.ttf");
    font.loadFromFile("../asset/fonts/font1.ttf");

    hintCover[0].position = sf::Vector2f(160, 70);
    hintCover[1].position = sf::Vector2f(640, 70);
    hintCover[2].position = sf::Vector2f(640, 240);
    hintCover[3].position = sf::Vector2f(160, 240);
    hintCover[4].position = sf::Vector2f(160, 70);

    startText.setFont(font);
    startText.setString("Start");
    startText.setPosition(sf::Vector2f(320, 260));
    startText.setCharacterSize(90);
    startText.setFillColor(sf::Color(r, g, b, 255));

    hintTitleText.setFont(font1);
    hintTitleText.setString("Hint:");
    hintTitleText.setPosition(sf::Vector2f(360, 75));
    hintTitleText.setCharacterSize(40);
    hintTitleText.setFillColor(sf::Color(r, g, b, 255));

    hintText.setFont(font1);
    hintText.setString("Use right-click to move\n  Use left-click to fire");
    hintText.setPosition(sf::Vector2f(310, 130));
    hintText.setCharacterSize(20);
    hintText.setFillColor(sf::Color(255, 72, 0, 255));

    objectiveText.setFont(font1);
    objectiveText.setString("Objective: Just destroy the enemies!!!");
    objectiveText.setPosition(sf::Vector2f(260, 195));
    objectiveText.setCharacterSize(20);
    objectiveText.setFillColor(sf::Color(255, 72, 0, 255));

    backText.setFont(font1);
    backText.setString("Back to the Main Menu");
    backText.setPosition(sf::Vector2f(240, 480));
    backText.setCharacterSize(40);
    backText.setFillColor(sf::Color(255, 72, 0, 255));

    while (1)
    {
        *cursor1 = sf::Mouse::getPosition(*window);
        // printf("%d %d\n", cursor1->x, cursor1->y);
        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                window->close();
                return 1;
            }
        }
        window->clear(sf::Color(0, 0, 0, 255));

        window->draw(startText);
        window->draw(hintCover);
        window->draw(hintTitleText);
        window->draw(hintText);
        window->draw(objectiveText);
        window->draw(backText);

        window->display();
        if (cursor1->x >= 320 && cursor1->x <= 455 && cursor1->y >= 290 && cursor1->y <= 345)
        {
            startText.setFillColor(sf::Color(r, g, b, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                startisClicked = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            startText.setFillColor(sf::Color(r, (g - 30), b, 255));
        }

        if (cursor1->x >= 240 && cursor1->x <= 540 && cursor1->y >= 480 && cursor1->y <= 515)
        {
            backText.setFillColor(sf::Color(255, 99, 0, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                backisClicked = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            backText.setFillColor(sf::Color(255, 72, 0, 255));
        }

        if (startisClicked)
        {
            return 2;
        }

        if (backisClicked)
        {
            // window->close();
            return 0;
        }
    }
}
bool main_menu(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor)
{
    int r = 170, g = 30, b = 199;
    int counter = 1;
    int singlePlayerChoice = 0;
    bool up = 1;
    bool singlePlayerisClick = 0, optionsisClick = 0, exitisClick = 0;
    sf::Text singlePlayer, titleText, options, exitText;
    sf::Font font1, font;
    font1.loadFromFile("../asset/fonts/font2.ttf");
    font.loadFromFile("../asset/fonts/font1.ttf");

    titleText.setFont(font);
    titleText.setString("Destroyer");
    titleText.setPosition(sf::Vector2f(270, 30));
    titleText.setCharacterSize(90);
    titleText.setFillColor(sf::Color(r, g, b, 255));

    singlePlayer.setFont(font1);
    singlePlayer.setString("Single Player"); //260 210 sampai 525 255
    singlePlayer.setPosition(sf::Vector2f(260, 220));
    singlePlayer.setCharacterSize(60);
    singlePlayer.setFillColor(sf::Color(255, 72, 0, 255));

    options.setFont(font1);
    options.setString("Options"); //310 320 samapi 455 355
    options.setPosition(sf::Vector2f(310, 320));
    options.setCharacterSize(60);
    options.setFillColor(sf::Color(255, 72, 0, 255));

    exitText.setFont(font1);
    exitText.setString("Exit"); //350 410 samapi 420 455
    exitText.setPosition(sf::Vector2f(348, 420));
    exitText.setCharacterSize(60);
    exitText.setFillColor(sf::Color(255, 72, 0, 255));

    while (1)
    {
        *cursor1 = sf::Mouse::getPosition(*window);
        // printf("%d %d\n", cursor1->x, cursor1->y);
        if (counter >= 10000)
        {
            counter = 1;
        }
        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                window->close();
                return 0;
            }
        }
        window->clear(sf::Color(0, 0, 0, 255));

        titleText.setFillColor(sf::Color(r, g, b, 255));

        window->draw(singlePlayer);
        window->draw(titleText);
        window->draw(options);
        window->draw(exitText);

        window->display();
        counter++;

        //hover
        if (cursor1->x >= 260 && cursor1->x <= 525 && cursor1->y >= 230 && cursor1->y <= 275)
        {
            singlePlayer.setFillColor(sf::Color(255, 99, 0, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                singlePlayerisClick = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            singlePlayer.setFillColor(sf::Color(255, 72, 0, 255));
        }

        if (cursor1->x >= 310 && cursor1->x <= 455 && cursor1->y >= 340 && cursor1->y <= 375)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                optionsisClick = 1;
                // printf("Single player clicked!\n");
            }
            options.setFillColor(sf::Color(255, 99, 0, 255));
        }
        else
        {
            options.setFillColor(sf::Color(255, 72, 0, 255));
        }

        if (cursor1->x >= 350 && cursor1->x <= 420 && cursor1->y >= 430 && cursor1->y <= 475)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                exitisClick = 1;
                // printf("Single player clicked!\n");
            }
            exitText.setFillColor(sf::Color(255, 99, 0, 255));
        }
        else
        {
            exitText.setFillColor(sf::Color(255, 72, 0, 255));
        }

        //efek
        if (singlePlayerisClick)
        {
            singlePlayerChoice = singlePlayerMainMenu(window, event, cursor1, main_sursor);
            if (singlePlayerChoice == 1)
            {
                return 0;
            }
            if (singlePlayerChoice == 2)
            {
                return 1;
            }
            singlePlayerisClick = 0;
        }

        if (exitisClick)
        {
            window->close();
            return 0;
        }

        //kelap kelip
        if (counter % 20 == 0)
        {
            if (r >= 211 && g <= 0 && b >= 255 || g == 0)
            {
                up = 0;
            }
            else if (r <= 180 && g >= 45 && r <= 189)
            {
                up = 1;
            }
            if (up)
            {
                r++;
                g--;
                b++;
            }
            else
            {
                r--;
                g++;
                b--;
            }
        }
    }
    return 1;
}
bool victory(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor)
{
    int r = 170, g = 30, b = 199;
    int counter = 1;
    bool up = 1;
    sf::Text victoryText;
    sf::Font font1;

    font1.loadFromFile("../asset/fonts/arial.ttf");

    victoryText.setFont(font1);
    victoryText.setString("Victory");
    victoryText.setPosition(sf::Vector2f(255, 70));
    victoryText.setCharacterSize(90);
    victoryText.setFillColor(sf::Color(r, g, b, 255));

    while (1)
    {
        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                window->close();
                return 0;
            }
        }
        window->clear(sf::Color(0, 0, 0, 255));

        victoryText.setFillColor(sf::Color(r, g, b, 255));
        window->draw(victoryText);

        window->display();

        //kelap kelip
        if (counter % 20 == 0)
        {
            if (r >= 211 && g <= 0 && b >= 255 || g == 0)
            {
                up = 0;
            }
            else if (r <= 180 && g >= 45 && r <= 189)
            {
                up = 1;
            }
            if (up)
            {
                r++;
                g--;
                b++;
            }
            else
            {
                r--;
                g++;
                b--;
            }
        }
        counter++;
        if (counter >= 10000)
        {
            counter = 1;
        }
    }
}
int game_over(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor)
{
    int r = 170, g = 30, b = 199;
    int counter = 1;
    bool up = 1;
    bool replayisClick = 0, mainmenuisClick = 0, exitisClick = 0;
    sf::Text loseText, replayText, mainmenuText, exitText;
    sf::Font font1, font2;
    font1.loadFromFile("../asset/fonts/font1.ttf");
    font2.loadFromFile("../asset/fonts/arial.ttf");

    loseText.setFont(font1);
    loseText.setString("Game Over");
    loseText.setPosition(sf::Vector2f(255, 70));
    loseText.setCharacterSize(90);
    loseText.setFillColor(sf::Color(r, g, b, 255));

    replayText.setFont(font2);
    replayText.setString("Play again"); //310 275 samapi 445 300
    replayText.setPosition(sf::Vector2f(310, 270));
    replayText.setCharacterSize(30);
    replayText.setFillColor(sf::Color(255, 72, 0, 255));

    mainmenuText.setFont(font2);
    mainmenuText.setString("Back to the main menu"); //230 345 samapi 530 360
    mainmenuText.setPosition(sf::Vector2f(227, 340));
    mainmenuText.setCharacterSize(30);
    mainmenuText.setFillColor(sf::Color(255, 72, 0, 255));

    exitText.setFont(font2);
    exitText.setString("Exit"); //350 415 samapi 400 435
    exitText.setPosition(sf::Vector2f(350, 410));
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color(255, 72, 0, 255));

    while (1)
    {
        *cursor1 = sf::Mouse::getPosition(*window);
        // printf("%d %d\n", cursor1->x, cursor1->y);
        if (counter >= 10000)
        {
            counter = 1;
        }

        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                window->close();
                return 0;
            }
        }
        window->clear(sf::Color(0, 0, 0, 255));

        loseText.setFillColor(sf::Color(r, g, b, 255));

        window->draw(loseText);
        window->draw(replayText);
        window->draw(mainmenuText);
        window->draw(exitText);

        window->display();

        counter++;

        //hover
        if (cursor1->x >= 310 && cursor1->x <= 445 && cursor1->y >= 275 && cursor1->y <= 300)
        {
            replayText.setFillColor(sf::Color(255, 99, 0, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                replayisClick = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            replayText.setFillColor(sf::Color(255, 72, 0, 255));
        }

        if (cursor1->x >= 230 && cursor1->x <= 530 && cursor1->y >= 345 && cursor1->y <= 370)
        {
            mainmenuText.setFillColor(sf::Color(255, 99, 0, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mainmenuisClick = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            mainmenuText.setFillColor(sf::Color(255, 72, 0, 255));
        }

        if (cursor1->x >= 350 && cursor1->x <= 400 && cursor1->y >= 415 && cursor1->y <= 435)
        {
            exitText.setFillColor(sf::Color(255, 99, 0, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                exitisClick = 1;
                // printf("Single player clicked!\n");
            }
        }
        else
        {
            exitText.setFillColor(sf::Color(255, 72, 0, 255));
        }

        //kelap kelip
        if (counter % 20 == 0)
        {
            if (r >= 211 && g <= 0 && b >= 255 || g == 0)
            {
                up = 0;
            }
            else if (r <= 180 && g >= 45 && r <= 189)
            {
                up = 1;
            }
            if (up)
            {
                r++;
                g--;
                b++;
            }
            else
            {
                r--;
                g++;
                b--;
            }
        }

        //klik atau belummmmmmmmmm
        if (mainmenuisClick)
        {
            return 1;
            // if (!main_menu(window, event, cursor1, main_sursor))
            //     return 0;
        }

        if (exitisClick)
        {
            window->close();
            return 0;
        }
    }
}
int game1(sf::RenderWindow *window, sf::Event *event, sf::Vector2i *cursor1, sf::Cursor *main_sursor, sf::Cursor *tele_cursor, sf::Vector2i *cursor2)
{
    bool wPressed = 0;
    bool f10Pressed = 0;
    uint64_t timer = 1;
    bool isGameplayed = 1;

    main_char Naruto;
    Naruto.setWindow(window);
    Naruto.setTarPos(400, 500);

    Enemy turret, turet, tower, toret;

    turret.setPosition(100, 80);
    turret.setWindow(window);
    turret.font.loadFromFile("../asset/fonts/arial.ttf");
    turret.setDamagefromTank(100); //penting ini
    turet.setPosition(300, 80);
    turet.setWindow(window);
    turet.font.loadFromFile("../asset/fonts/arial.ttf");
    turet.setDamagefromTank(100);
    tower.setPosition(500, 80);
    tower.setWindow(window);
    tower.font.loadFromFile("../asset/fonts/arial.ttf");
    tower.setDamagefromTank(100);
    toret.setPosition(700, 80);
    toret.setWindow(window);
    toret.font.loadFromFile("../asset/fonts/arial.ttf");
    toret.setDamagefromTank(100);

    while (isGameplayed)
    {
        turret.find_target(Naruto.getXpos(), Naruto.getypos());
        turet.find_target(Naruto.getXpos(), Naruto.getypos());
        tower.find_target(Naruto.getXpos(), Naruto.getypos());
        toret.find_target(Naruto.getXpos(), Naruto.getypos());
        if (timer >= 10000)
        {
            timer = 1;
        }
        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                isGameplayed = 0;
                window->close();
                return 0;
            }
        }

        window->clear(sf::Color::Black);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || Naruto.isMove())
        {
            *cursor1 = sf::Mouse::getPosition(*window);
            Naruto.move(*cursor1);
            // printf("%d dan %d dan %f\n", cursor.x, cursor.y, Naruto.getAngle());
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wPressed || Naruto.isFire())
        {
            Naruto.fire();
            turret.setRelationWithTank(Naruto.getXbullet(), Naruto.getYbullet());
            turet.setRelationWithTank(Naruto.getXbullet(), Naruto.getYbullet());
            tower.setRelationWithTank(Naruto.getXbullet(), Naruto.getYbullet());
            toret.setRelationWithTank(Naruto.getXbullet(), Naruto.getYbullet());
            if (turet.isHitted() || turret.isHitted() || tower.isHitted() || toret.isHitted())
            {
                Naruto.setHitBullet(1);
            }
            else
                Naruto.setHitBullet(0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            wPressed = 1;
        }
        if (wPressed)
        {
            window->setMouseCursor(*tele_cursor);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                *cursor2 = sf::Mouse::getPosition(*window);
                Naruto.teleport(cursor2->x, cursor2->y);
                window->setMouseCursor(*main_sursor);
                wPressed = 0;
            }
        }

        if (timer % 1000 == 0 && !turret.timeToFire)
        {
            // printf("here\n");
            turret.timeToFire = 1;
            turet.timeToFire = 1;
            tower.timeToFire = 1;
            toret.timeToFire = 1;
        }
        // printf("fire=%d ", turret.timeToFire);
        if (turret.timeToFire)
        {
            // printf("nyowo: %f\n", Naruto.getHP());
            // printf("%f %f\n", turret.bullet.getXpos(), turret.bullet.getYpos());
            turret.fire();
            // printf("%f dan %f\n", turret.bullet.getXpos(), turret.bullet.getYpos());
            if (Naruto.isHittedFrom(turret.bullet.getXpos(), turret.bullet.getYpos()))
            {
                // printf("tesss\n");
                turret.setBulletHitted(1);
            }
        }
        if (turet.timeToFire)
        {
            // printf("nyowo: %f\n", Naruto.getHP());
            // printf("%f %f\n", turet.bullet.getXpos(), turet.bullet.getYpos());
            turet.fire();
            // printf("%f dan %f\n", turet.bullet.getXpos(), turet.bullet.getYpos());
            if (Naruto.isHittedFrom(turet.bullet.getXpos(), turet.bullet.getYpos()))
            {
                // printf("tesss\n");
                turet.setBulletHitted(1);
            }
        }
        if (tower.timeToFire)
        {
            // printf("nyowo: %f\n", Naruto.getHP());
            // printf("%f %f\n", tower.bullet.getXpos(), tower.bullet.getYpos());
            tower.fire();
            // printf("%f dan %f\n", tower.bullet.getXpos(), tower.bullet.getYpos());
            if (Naruto.isHittedFrom(tower.bullet.getXpos(), tower.bullet.getYpos()))
            {
                // printf("tesss\n");
                tower.setBulletHitted(1);
            }
        }
        if (toret.timeToFire)
        {
            // printf("nyowo: %f\n", Naruto.getHP());
            // printf("%f %f\n", toret.bullet.getXpos(), toret.bullet.getYpos());
            toret.fire();
            // printf("%f dan %f\n", toret.bullet.getXpos(), toret.bullet.getYpos());
            if (Naruto.isHittedFrom(toret.bullet.getXpos(), toret.bullet.getYpos()))
            {
                // printf("tesss\n");
                toret.setBulletHitted(1);
            }
        }

        if (turret.isDestroy() && turet.isDestroy() && toret.isDestroy() && tower.isDestroy())
        {
            // printf("VICTORIOUS\n");
            if (!victory(window, event, cursor1, main_sursor))
            {
                return 0;
            }
        }
        if (Naruto.getHP() <= 0)
        {
            isGameplayed = 0;
            // printf("game over :(\n");
            if (!game_over(window, event, cursor1, main_sursor))
            {
                return 0;
            }
            else
            {
                // printf("tes tes tes ");
                return 1;
            }
        }

        Naruto.draw();
        turret.draw();
        turet.draw();
        tower.draw();
        toret.draw();

        // printf("%ld\n", timer);
        timer++;

        window->display();
    }
    return 0;
}