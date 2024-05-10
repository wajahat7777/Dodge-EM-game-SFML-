#ifndef ORANGEHEXAGON_H
#define ORANGEHEXAGON_H

#include <SFML/Graphics.hpp>
#include<string.h>
#include <cmath>
#include "Food.h"

using namespace sf;

class OrangeHexagon:public Food
{
    public:
     Texture tex;
     Sprite bronze;
     OrangeHexagon()
    {
        // delay=10 + rand()%25;
        tex.loadFromFile("img/orangehexagon.png");
        bronze.setTexture(tex);
        bronze.setPosition(1000,1000);
        bronze.setScale(0.2,0.2);
    }
      OrangeHexagon(float initialX, float initialY)
    {
        // delay=10 + rand()%25;
        tex.loadFromFile("img/orangehexagon.png");
        bronze.setTexture(tex);
        bronze.setPosition(initialX,initialY);
        bronze.setScale(0.09,0.09);
    }
    
    void apply() override
    {
      bronze.setPosition(rand()%700,0);
    }
    Sprite& getSprite() override
    {
        return bronze;
    }
    // virtual ~RedRectangle() {}  // Virtual destructors
};

#endif