#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <time.h>
#include <iostream>
#include "player.h"
#include "menu.h"
#include "Food.h"
#include "RedRectangle.h"
#include "GreenCircle.h"
#include "OrangeHexagon.h"
#include "WhiteTriangle.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace sf;

// Constants and global variables

const char title[] = "OOP-Project, Spring-2023";
const int numSmallBoxes = 3;

void sortRecords();
// Structure to hold player records
struct PlayerRecord
{
    std::string playerName;
    int score;
};
void checkAndReplaceRecord(const std::string &playerName, int score);
void sortRecords();
string getTop10Records();

class Game
{
public:
  // Game elements

    Sprite background, pause, end,won;
    Texture bg_texture, tex, gameover,win;
    Box smallBoxes[numSmallBoxes];
    Box *box;
    int directionX = 1;
    int directionY = 1;
    Menu m;
    RedRectangle *R;
    Food **F1; // Array of pointers to Food
    Food **F2; // Array of pointers to Food
    Food **F3; // Array of pointers to Food
    Food **F4; // Array of pointers to Food
    string name;
    string top10Records;
    bool gamestart = true;
    int lives = 3;
    int level = 1;
    // Constructor
    Game()
    {

        bg_texture.loadFromFile("img/maxresdefault.png");
        background.setTexture(bg_texture);
        background.setScale(1, 1.95);
        gameover.loadFromFile("img/gameover.jpg");
        end.setTexture(gameover);
        end.setScale(0.75, 0.7);
        win.loadFromFile("img/End.png");
        won.setTexture(win);
        won.setScale(0.1, 0.1);
        
        initializeSmallBoxes();
        m.scores = getTop10Records();
        R = nullptr;
    }

    // Initialize small boxes
    //Intializing the player and enemy objects  
    void initializeSmallBoxes()
    {
        smallBoxes[0] = Box(200.f, 300.f, 40.f, 40.f, 1, 0);   // Initial direction is 1 (right), y-direction is 1 (down)
        smallBoxes[1] = Box(400.f, 500.f, 30.f, 30.f, -1, -1); // Initial direction is -1 (left), y-direction is -1 (up)
        smallBoxes[2] = Box(100.f, 500.f, 30.f, 30.f, -1, -1); // Initial direction is -1 (left), y-direction is -1 (up)
        smallBoxes[0].shape.setFillColor(Color::Blue);
    }


    //starting game
    void start_game()
    {
        m.display_menu();
         sf::Music music;
         if(!music.openFromFile("img/SkyFire.ogg"))
         {}
         music.setLoop(true);
         music.play();
        srand(time(0));
        RenderWindow window(VideoMode(780, 980), title);
        // window.setFramerateLimit(60);
        Clock clock;
        float timer = 0;
        float timer2 = 0;
        float timer3 = 10;
        sf::Font font;
        sf::Text text2;
        font.loadFromFile("img/Roboto-Black.ttf");
        text2.setFont(font);
        text2.setCharacterSize(20);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(20.f, 20.f);
       
        bool speed = false;
        int numRed = 0;
        int numGreen = 0;
        int numOrange = 0;
        int numWhite = 0;
        numRed = 72;
        numGreen = 4;
        numOrange = 3;
        numWhite = 2;
        //  Food *F1[numRed];
        F1 = new Food *[numRed];
        F2 = new Food *[numGreen];
        F3 = new Food *[numOrange];
        F4 = new Food *[numWhite];
        
        // Level 1 setup

        if (level == 1)
        {   
            // Initialize RedRectangles
           //food of red colour
            for (int i = 0; i < 8; ++i)
            {
                F1[i] = new RedRectangle(20 + i * 100, 230);
            }
            for (int i = 8; i < 16; ++i)
            {
                F1[i] = new RedRectangle(20, 230 + (16 - i) * 60);
            }
            for (int i = 16; i < 24; ++i)
            {
                F1[i] = new RedRectangle(710, 230 + (24 - i) * 60);
            }
            for (int i = 24; i < 32; ++i)
            {
                F1[i] = new RedRectangle((32 - i) * 80, 730);
            }
            for (int i = 32; i < 38; ++i)
            {
                F1[i] = new RedRectangle(120 + (38 - i) * 80, 300);
            }
            for (int i = 38; i < 44; ++i)
            {
                F1[i] = new RedRectangle(120 + (44 - i) * 80, 670);
            }
            for (int i = 44; i < 48; ++i)
            {
                F1[i] = new RedRectangle(180 + (48 - i) * 80, 365);
            }
            for (int i = 48; i < 52; ++i)
            {
                F1[i] = new RedRectangle(180 + (52 - i) * 80, 610);
            }
            for (int i = 52; i < 54; ++i)
            {
                F1[i] = new RedRectangle(260 + (54 - i) * 80, 415);
            }
            for (int i = 54; i < 56; ++i)
            {
                F1[i] = new RedRectangle(260 + (56 - i) * 80, 550);
            }
            for (int i = 56; i < 61; ++i)
            {
                F1[i] = new RedRectangle(100, 290 + (61 - i) * 60);
            }
            for (int i = 61; i < 66; ++i)
            {
                F1[i] = new RedRectangle(630, 290 + (66 - i) * 60);
            }
            for (int i = 66; i < 69; ++i)
            {
                F1[i] = new RedRectangle(180, 360 + (69 - i) * 60);
            }
            for (int i = 69; i < 72; ++i)
            {
                F1[i] = new RedRectangle(550, 360 + (72 - i) * 60);
            }
            // Initialize GreenCircles = score=20

            F2[0] = new GreenCircle(120, 300);
            F2[1] = new GreenCircle(650, 650);
            F2[2] = new GreenCircle(650, 300);
            F2[3] = new GreenCircle(120, 650);
            // Initialize OrangeHexagons = score = 10, ghost becomes invisible for ten seconds

            F3[0] = new OrangeHexagon(180, 350);
            F3[1] = new OrangeHexagon(180, 600);
            F3[2] = new OrangeHexagon(550, 350);
            // Initialize WhiteTriangles
            //ghost becomes invisible for ten seconds
            F4[0] = new WhiteTriangle(260, 415);
            F4[1] = new WhiteTriangle(490, 550);
        }
        if (!font.loadFromFile("img/Roboto-Black.ttf"))
        {
            std::cout << "Failed to load font" << std::endl;
        }
        font.loadFromFile("img/Roboto-Black.ttf");
        sf::Text text;
        text.setFont(font);
        int score = 0;
        bool ended=false;

        // Game loop

        while (window.isOpen())
        {
            string str1 = to_string(score);
            if (level == 1 && numRed == 0 && numGreen == 0 && numOrange == 0 && numWhite == 0 && lives > 0)
            {
                level = 2;
                timer3 = 10;
                smallBoxes[0].shape.setPosition(200, 300);
                smallBoxes[1].shape.setPosition(400, 500);
                numRed = 72;
                numGreen = 4;
                numOrange = 3;
                numWhite = 2;
                for (int i = 0; i < 8; ++i)
                {
                    F1[i] = new RedRectangle(20 + i * 100, 230);
                }
                for (int i = 8; i < 16; ++i)
                {
                    F1[i] = new RedRectangle(20, 230 + (16 - i) * 60);
                }
                for (int i = 16; i < 24; ++i)
                {
                    F1[i] = new RedRectangle(710, 230 + (24 - i) * 60);
                }
                for (int i = 24; i < 32; ++i)
                {
                    F1[i] = new RedRectangle((32 - i) * 80, 730);
                }
                for (int i = 32; i < 38; ++i)
                {
                    F1[i] = new RedRectangle(120 + (38 - i) * 80, 300);
                }
                for (int i = 38; i < 44; ++i)
                {
                    F1[i] = new RedRectangle(120 + (44 - i) * 80, 670);
                }
                for (int i = 44; i < 48; ++i)
                {
                    F1[i] = new RedRectangle(180 + (48 - i) * 80, 365);
                }
                for (int i = 48; i < 52; ++i)
                {
                    F1[i] = new RedRectangle(180 + (52 - i) * 80, 610);
                }
                for (int i = 52; i < 54; ++i)
                {
                    F1[i] = new RedRectangle(260 + (54 - i) * 80, 415);
                }
                for (int i = 54; i < 56; ++i)
                {
                    F1[i] = new RedRectangle(260 + (56 - i) * 80, 550);
                }
                for (int i = 56; i < 61; ++i)
                {
                    F1[i] = new RedRectangle(100, 290 + (61 - i) * 60);
                }
                for (int i = 61; i < 66; ++i)
                {
                    F1[i] = new RedRectangle(630, 290 + (66 - i) * 60);
                }
                for (int i = 66; i < 69; ++i)
                {
                    F1[i] = new RedRectangle(180, 360 + (69 - i) * 60);
                }
                for (int i = 69; i < 72; ++i)
                {
                    F1[i] = new RedRectangle(550, 360 + (72 - i) * 60);
                }
                F2[0] = new GreenCircle(120, 300);
                F2[1] = new GreenCircle(650, 650);
                F2[2] = new GreenCircle(650, 300);
                F2[3] = new GreenCircle(120, 650);
                F3[0] = new OrangeHexagon(180, 350);
                F3[1] = new OrangeHexagon(180, 600);
                F3[2] = new OrangeHexagon(550, 350);
                F4[0] = new WhiteTriangle(260, 415);
                F4[1] = new WhiteTriangle(490, 550);
            }
            if (level == 2 && numRed == 0 && numGreen == 0 && numOrange == 0 && numWhite == 0 && lives > 0)
            {
                level = 3;
                timer3 = 10;
                smallBoxes[0].shape.setPosition(200, 300);
                smallBoxes[1].shape.setPosition(400, 500);
                numRed = 72;
                numGreen = 4;
                numOrange = 3;
                numWhite = 2;
                for (int i = 0; i < 8; ++i)
                {
                    F1[i] = new RedRectangle(20 + i * 100, 230);
                }
                for (int i = 8; i < 16; ++i)
                {
                    F1[i] = new RedRectangle(20, 230 + (16 - i) * 60);
                }
                for (int i = 16; i < 24; ++i)
                {
                    F1[i] = new RedRectangle(710, 230 + (24 - i) * 60);
                }
                for (int i = 24; i < 32; ++i)
                {
                    F1[i] = new RedRectangle((32 - i) * 80, 730);
                }
                for (int i = 32; i < 38; ++i)
                {
                    F1[i] = new RedRectangle(120 + (38 - i) * 80, 300);
                }
                for (int i = 38; i < 44; ++i)
                {
                    F1[i] = new RedRectangle(120 + (44 - i) * 80, 670);
                }
                for (int i = 44; i < 48; ++i)
                {
                    F1[i] = new RedRectangle(180 + (48 - i) * 80, 365);
                }
                for (int i = 48; i < 52; ++i)
                {
                    F1[i] = new RedRectangle(180 + (52 - i) * 80, 610);
                }
                for (int i = 52; i < 54; ++i)
                {
                    F1[i] = new RedRectangle(260 + (54 - i) * 80, 415);
                }
                for (int i = 54; i < 56; ++i)
                {
                    F1[i] = new RedRectangle(260 + (56 - i) * 80, 550);
                }
                for (int i = 56; i < 61; ++i)
                {
                    F1[i] = new RedRectangle(100, 290 + (61 - i) * 60);
                }
                for (int i = 61; i < 66; ++i)
                {
                    F1[i] = new RedRectangle(630, 290 + (66 - i) * 60);
                }
                for (int i = 66; i < 69; ++i)
                {
                    F1[i] = new RedRectangle(180, 360 + (69 - i) * 60);
                }
                for (int i = 69; i < 72; ++i)
                {
                    F1[i] = new RedRectangle(550, 360 + (72 - i) * 60);
                }
                F2[0] = new GreenCircle(120, 300);
                F2[1] = new GreenCircle(650, 650);
                F2[2] = new GreenCircle(650, 300);
                F2[3] = new GreenCircle(120, 650);
                F3[0] = new OrangeHexagon(180, 350);
                F3[1] = new OrangeHexagon(180, 600);
                F3[2] = new OrangeHexagon(550, 350);
                F4[0] = new WhiteTriangle(260, 415);
                F4[1] = new WhiteTriangle(490, 550);
            }

            if (level == 3 && numRed == 0 && numGreen == 0 && numOrange == 0 && numWhite == 0 && lives > 0)
            {
                level = 4;
                timer3 = 10;
                smallBoxes[0].shape.setPosition(200, 300);
                smallBoxes[1].shape.setPosition(400, 500);
                smallBoxes[2].shape.setPosition(100, 500);
                numRed = 72;
                numGreen = 4;
                numOrange = 3;
                numWhite = 2;
                for (int i = 0; i < 8; ++i)
                {
                    F1[i] = new RedRectangle(20 + i * 100, 230);
                }
                for (int i = 8; i < 16; ++i)
                {
                    F1[i] = new RedRectangle(20, 230 + (16 - i) * 60);
                }
                for (int i = 16; i < 24; ++i)
                {
                    F1[i] = new RedRectangle(710, 230 + (24 - i) * 60);
                }
                for (int i = 24; i < 32; ++i)
                {
                    F1[i] = new RedRectangle((32 - i) * 80, 730);
                }
                for (int i = 32; i < 38; ++i)
                {
                    F1[i] = new RedRectangle(120 + (38 - i) * 80, 300);
                }
                for (int i = 38; i < 44; ++i)
                {
                    F1[i] = new RedRectangle(120 + (44 - i) * 80, 670);
                }
                for (int i = 44; i < 48; ++i)
                {
                    F1[i] = new RedRectangle(180 + (48 - i) * 80, 365);
                }
                for (int i = 48; i < 52; ++i)
                {
                    F1[i] = new RedRectangle(180 + (52 - i) * 80, 610);
                }
                for (int i = 52; i < 54; ++i)
                {
                    F1[i] = new RedRectangle(260 + (54 - i) * 80, 415);
                }
                for (int i = 54; i < 56; ++i)
                {
                    F1[i] = new RedRectangle(260 + (56 - i) * 80, 550);
                }
                for (int i = 56; i < 61; ++i)
                {
                    F1[i] = new RedRectangle(100, 290 + (61 - i) * 60);
                }
                for (int i = 61; i < 66; ++i)
                {
                    F1[i] = new RedRectangle(630, 290 + (66 - i) * 60);
                }
                for (int i = 66; i < 69; ++i)
                {
                    F1[i] = new RedRectangle(180, 360 + (69 - i) * 60);
                }
                for (int i = 69; i < 72; ++i)
                {
                    F1[i] = new RedRectangle(550, 360 + (72 - i) * 60);
                }
                F2[0] = new GreenCircle(120, 300);
                F2[1] = new GreenCircle(650, 650);
                F2[2] = new GreenCircle(650, 300);
                F2[3] = new GreenCircle(120, 650);
                F3[0] = new OrangeHexagon(180, 350);
                F3[1] = new OrangeHexagon(180, 600);
                F3[2] = new OrangeHexagon(550, 350);
                F4[0] = new WhiteTriangle(260, 415);
                F4[1] = new WhiteTriangle(490, 550);
            }
            if (level == 4 && numRed == 0 && numGreen == 0 && numOrange == 0 && numWhite == 0 && lives > 0)
            {
                gamestart=false;
                ended=true;
                // music.stop();
                // sound7.play();
                window.draw(won);
                text.setString("Your Score:");
                text.setCharacterSize(36);
                text.setFillColor(sf::Color::White);
                text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setPosition(sf::Vector2f(300, 100));
                window.draw(text);

                text.setString(str1);
                text.setCharacterSize(33);
                text.setFillColor(sf::Color::Cyan);
                text.setPosition(sf::Vector2f(300, 150));
                window.draw(text);
                if (ended)
                {
                    cout << "Enter your name: ";
                    cin >> name;
                    checkAndReplaceRecord(name, score);
                    // sortRecords();
                    top10Records = getTop10Records();
                    m.scores = top10Records;
                }
                ended = false;
                level=0;
                window.display();
            }

            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            timer2 += time;
            timer3 += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                gamestart = false;
                tex.loadFromFile("img/pause.png");
                pause.setTexture(tex);
                pause.setScale(1.1, 1.2);
                window.draw(pause);
                window.display();
            }
            if (gamestart == false && Keyboard::isKeyPressed(Keyboard::Num9))
            {
                //  music.stop();
                window.close();
                Game G;
                G.start_game();
                return;
            }
            if (gamestart == false && Keyboard::isKeyPressed(Keyboard::Num4))
                exit(0);

            else if (Keyboard::isKeyPressed(Keyboard::Num1))
                gamestart = true;

            FloatRect playerBounds = smallBoxes[0].shape.getGlobalBounds();
            FloatRect enemyBounds = smallBoxes[1].shape.getGlobalBounds();
            FloatRect enemyBounds2 = smallBoxes[2].shape.getGlobalBounds();
            if (gamestart)
            {

                smallBoxes[0].handleInput(smallBoxes[0]);
                

                window.clear(Color::Black);
                window.draw(background);

                for (int i = 0; i < numRed; ++i)
                    window.draw(F1[i]->getSprite());
                for (int i = 0; i < numGreen; ++i)
                    window.draw(F2[i]->getSprite());
                for (int i = 0; i < numOrange; ++i)
                    window.draw(F3[i]->getSprite());
                for (int i = 0; i < numWhite; ++i)
                    window.draw(F4[i]->getSprite());

                FloatRect e3Bounds[72];
                FloatRect greenBounds[4];
                FloatRect orangeBounds[3];
                FloatRect whiteBounds[2];

                for (int i = 0; i < numRed; ++i)
                {
                    e3Bounds[i] = F1[i]->getSprite().getGlobalBounds();
                }
                for (int i = 0; i < numGreen; ++i)
                {
                    greenBounds[i] = F2[i]->getSprite().getGlobalBounds();
                }
                for (int i = 0; i < numOrange; ++i)
                {
                    orangeBounds[i] = F3[i]->getSprite().getGlobalBounds();
                }
                for (int i = 0; i < numWhite; ++i)
                {
                    whiteBounds[i] = F4[i]->getSprite().getGlobalBounds();
                }
                if (timer > 3)
                {
                    for (int i = 0; i < numRed; i++)
                    {
                        if (playerBounds.left < e3Bounds[i].left + e3Bounds[i].width &&
                            playerBounds.left + playerBounds.width > e3Bounds[i].left &&
                            playerBounds.top < e3Bounds[i].top + e3Bounds[i].height &&
                            playerBounds.top + playerBounds.height > e3Bounds[i].top)
                        {
                            for (int k = i; k < numRed - 1; k++)
                            {
                                F1[k] = F1[k + 1];
                            }
                            //  sound3.play();
                            score += 1;
                            numRed--;
                        }
                    }
                }
                for (int i = 0; i < numGreen; i++)
                {
                    if (playerBounds.left < greenBounds[i].left + greenBounds[i].width &&
                        playerBounds.left + playerBounds.width > greenBounds[i].left &&
                        playerBounds.top < greenBounds[i].top + greenBounds[i].height &&
                        playerBounds.top + playerBounds.height > greenBounds[i].top)
                    {
                        for (int k = i; k < numGreen - 1; k++)
                        {
                            F2[k] = F2[k + 1];
                        }
                        //  sound3.play();
                        score += (20);
                        numGreen--;
                        lives++;
                    }
                }
                for (int i = 0; i < numOrange; i++)
                {
                    if (playerBounds.left < orangeBounds[i].left + orangeBounds[i].width &&
                        playerBounds.left + playerBounds.width > orangeBounds[i].left &&
                        playerBounds.top < orangeBounds[i].top + orangeBounds[i].height &&
                        playerBounds.top + playerBounds.height > orangeBounds[i].top)
                    {
                        for (int k = i; k < numOrange - 1; k++)
                        {
                            F3[k] = F3[k + 1];
                        }
                        //  sound3.play();
                        score += 10;
                        numOrange--;
                        timer2 = 0;
                    }
                }

                for (int i = 0; i < numWhite; i++)
                {
                    if (playerBounds.left < whiteBounds[i].left + whiteBounds[i].width &&
                        playerBounds.left + playerBounds.width > whiteBounds[i].left &&
                        playerBounds.top < whiteBounds[i].top + whiteBounds[i].height &&
                        playerBounds.top + playerBounds.height > whiteBounds[i].top)
                    {
                        for (int k = i; k < numWhite - 1; k++)
                        {
                            F4[k] = F4[k + 1];
                        }
                        //  sound3.play();

                        numWhite--;
                        timer3 = 0;
                    }
                }

                // Move and draw small boxes
                for (int i = 0; i < numSmallBoxes; ++i)
                {
                    float speedX;
                    float speedY;
                    if (speed)
                    {
                        speedX = 0.4f;
                        speedY = 0.4f;
                    }
                    else
                    {
                        speedX = 0.4f;
                        speedY = 0.4f;
                    }
                    if (timer > 3)
                    {
                        smallBoxes[0].move(speedX, speedY);
                        smallBoxes[1].move(speedX = 0.4f, speedY = 0.4f);
                        smallBoxes[2].move(speedX = 0.4f, speedY = 0.4f);
                    }
                    // Check for collisions with x-axis boundaries
                    if (smallBoxes[i].shape.getPosition().x + smallBoxes[i].shape.getSize().x > 765 ||
                        smallBoxes[i].shape.getPosition().x < 20)
                    {
                        smallBoxes[i].directionX = -smallBoxes[i].directionX;
                    }

                    // Check for collisions with y-axis boundaries
                    if (smallBoxes[i].shape.getPosition().y + smallBoxes[i].shape.getSize().y > 780 ||
                        smallBoxes[i].shape.getPosition().y < 220)
                    {
                        smallBoxes[i].directionY = -smallBoxes[i].directionY;
                    }

                    window.draw(smallBoxes[0].shape);

                    if (timer3 > 10)
                        window.draw(smallBoxes[1].shape);
                    if (level > 3 && timer3 > 10)
                        window.draw(smallBoxes[2].shape);
                }
                if (timer3 > 10)
                {
                    if (playerBounds.left < enemyBounds.left + enemyBounds.width &&
                        playerBounds.left + playerBounds.width > enemyBounds.left &&
                        playerBounds.top < enemyBounds.top + enemyBounds.height &&
                        playerBounds.top + playerBounds.height > enemyBounds.top)
                    {
                        lives--;
                        smallBoxes[0].shape.setPosition(200, 300);
                        smallBoxes[1].shape.setPosition(400, 500);
                    }
                }
                if (timer3 > 10 && level==4)
                {
                    if (playerBounds.left < enemyBounds2.left + enemyBounds2.width &&
                        playerBounds.left + playerBounds.width > enemyBounds2.left &&
                        playerBounds.top < enemyBounds2.top + enemyBounds2.height &&
                        playerBounds.top + playerBounds.height > enemyBounds2.top)
                    {
                        lives--;
                        smallBoxes[0].shape.setPosition(200, 300);
                        smallBoxes[1].shape.setPosition(400, 500);
                        smallBoxes[2].shape.setPosition(100,500);
                    }
                }
                if (timer2 < 10)
                    speed = true;
                else
                    speed = false;

                string str2 = to_string(lives);
                string str3 = to_string(level);
                text.setString("Score:");
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);
                text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setPosition(sf::Vector2f(700, 100));
                window.draw(text);

                text.setString(str1);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Cyan);
                text.setPosition(sf::Vector2f(700, 120));
                window.draw(text);

                text.setString("lives:");
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Green);
                text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setPosition(sf::Vector2f(10, 100));
                window.draw(text);

                text.setString(str2);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Green);
                text.setPosition(sf::Vector2f(10, 120));
                window.draw(text);

                text.setString("level:");
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::Red);
                text.setStyle(sf::Text::Bold);
                text.setPosition(sf::Vector2f(320, 90));
                window.draw(text);

                text.setString(str3);
                text.setCharacterSize(40);
                text.setFillColor(sf::Color::Red);
                text.setPosition(sf::Vector2f(360, 145));
                window.draw(text);

                if (lives <= 0)
                {
                    gamestart = false;
                    cout << "Enter your name: ";
                    cin >> name;
                    checkAndReplaceRecord(name, score);
                    // sortRecords();
                    top10Records = getTop10Records();
                    m.scores = top10Records;
                    text2.setString(m.scores);
                    window.draw(end);
                }
                if (lives == 0 && Keyboard::isKeyPressed(Keyboard::Num1))
                {
                    Game g;
                    g.start_game();
                    return;
                }

                window.display();
            }
        }
    }
};

void checkAndReplaceRecord(const std::string &playerName, int score)
{

    std::ifstream inputFile("game.txt");

    std::ofstream outputFile("temp.txt");
    std::string line;
    bool recordFound = false;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string name;
        int previousScore;
        iss >> name >> previousScore;

        if (name == playerName)
        {
            recordFound = true;
            if (score > previousScore)
            {
                outputFile << playerName << " " << score << std::endl;
            }
            else
            {
                outputFile << line << std::endl;
            }
        }
        else
        {
            outputFile << line << std::endl;
        }
    }

    if (!recordFound)
    {
        outputFile << playerName << " " << score << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::remove("game.txt");
    std::rename("temp.txt", "game.txt");
    sortRecords();
}

// Function to sort records in the file
void sortRecords()
{
    const int MAX_RECORDS = 100; // Maximum number of records
    PlayerRecord records[MAX_RECORDS];

    int numRecords = 0;

    std::ifstream inputFile("game.txt");
    std::string line;

    // Read records into the array
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        iss >> records[numRecords].playerName >> records[numRecords].score;
        numRecords++;
    }
    inputFile.close();

    // Sort the records
    for (int i = 0; i < numRecords - 1; i++)
    {
        for (int j = 0; j < numRecords - i - 1; j++)
        {
            if (records[j].score < records[j + 1].score)
            {
                PlayerRecord temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }

    // Write the sorted records back to the file
    std::ofstream outputFile("game.txt");
    for (int i = 0; i < numRecords; i++)
    {
        outputFile << records[i].playerName << "\t\t" << records[i].score << std::endl;
    }
    outputFile.close();
}

// Function to retrieve the first 10 records as a string
std::string getTop10Records()
{
    std::ifstream inputFile("game.txt");
    std::string line;
    std::string top10Records;

    for (int i = 0; i < 10 && std::getline(inputFile, line); ++i)
    {
        top10Records += line + "\n";
    }

    inputFile.close();

    return top10Records;
}
