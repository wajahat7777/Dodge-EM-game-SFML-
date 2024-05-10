#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
//#include "game.h"
#include <iostream>
using namespace sf;
class Menu{
public:
bool flag=false;
bool gamestart=false;
bool m=false,h=false,i1=false,i2=false,ex=false;
std :: string scores;
Texture tex,tex1,tex2,tex3,tex4,tex5;
Sprite menu,instructions,score;
//add menu attributes here
Menu()
{
	tex.loadFromFile("img/menu.png");
	tex1.loadFromFile("img/Highscores.png");
	tex2.loadFromFile("img/instructions1.jpg");
	tex3.loadFromFile("img/exit.png");
	tex5.loadFromFile("img/background_19.png");
	menu.setTexture(tex);

//constructors body
}

void display_menu()

{	
//display menu screen here
	RenderWindow window(VideoMode(780, 780),"Master piece");
    Clock clock;
    float timer=0;
    int count =0;
	int count2=0;
	const int MAX_COUNT = 3;
	bool isKeyDown = false; // Flag to track key press
sf::Clock switchTimer; // Timer to track the elapsed time
const sf::Time SWITCH_DELAY = sf::seconds(0.1f); // Delay between texture switches

	 sf::Font font;	
	sf::Font font2;
    if (!font2.loadFromFile("img/Roboto-Black.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
       
    }
	sf:: Text text;
	text.setFont(font2);
    sf::Text text2;
    text2.setFont(font2);
    text2.setCharacterSize(25);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(300.f, 235.f);


    while (window.isOpen())
    {
		
    	

    	window.draw(menu);
    
    	 
    	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
       
		
	

if (switchTimer.getElapsedTime() >= SWITCH_DELAY) {
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        if (!isKeyDown) {
            isKeyDown = true;
            count = (count + 1) % (MAX_COUNT + 1); // Increment count and wrap around
            switchTimer.restart(); // Restart the switch timer
        }
    } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (!isKeyDown) {
            isKeyDown = true;
            count = (count - 1 + MAX_COUNT + 1) % (MAX_COUNT + 1); // Decrement count and wrap around
            switchTimer.restart(); // Restart the switch timer
        }
    } else {
        isKeyDown = false; // Reset the flag when no key is pressed
    }
}

// Set the texture based on the count
if (count == 0) {
    menu.setTexture(tex);
} else if (count == 1) {
    menu.setTexture(tex1);
		if(count==1 && Keyboard::isKeyPressed(Keyboard::Enter)){
			h==true;
			gamestart=false;
			menu.setTexture(tex5);
			text2.setString(scores);
			window.draw(text2);
			text.setString("High Scores:");
         	text.setCharacterSize(30);
         	text.setFillColor(sf::Color::White);
         	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
         	text.setPosition(sf::Vector2f(300,150));
        	 window.draw(text);
		}
		else if(h==true && Keyboard::isKeyPressed(Keyboard::Num7))
		{
			 h=false;
			 menu.setTexture(tex1);
			
		}
		
} else if (count == 2) {
    menu.setTexture(tex2);
	if(count==2 && Keyboard::isKeyPressed(Keyboard::Enter)){
			h==true;
			gamestart=false;
			menu.setTexture(tex4);
			
			
		}
		else if(h==true && Keyboard::isKeyPressed(Keyboard::Num7))
		{
			 h=false;
			 menu.setTexture(tex1);
		}
}
	else if (count == 3) {
    menu.setTexture(tex3);
		if(count==3 && Keyboard::isKeyPressed(Keyboard::Enter))
			exit(0);
}


if (count==0 && Keyboard::isKeyPressed(Keyboard::Enter)) {
    gamestart = true;
 
    window.close();
 
}


		window.display();
   }
 }

};
#endif