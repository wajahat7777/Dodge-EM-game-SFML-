#ifndef REDRECTANGLE_H
#define REDRECTANGLE_H

#include <SFML/Graphics.hpp>
#include<string.h>
#include <cmath>
#include "Food.h"

using namespace sf;

class RedRectangle:public Food
{
    public:
     Texture tex;
     Sprite bronze;
     RedRectangle()
    {
        // delay=10 + rand()%25;
        tex.loadFromFile("img/redrectangle.png");
        bronze.setTexture(tex);
        bronze.setPosition(1000,1000);
        bronze.setScale(0.2,0.2);
    }
      RedRectangle(float initialX, float initialY)
    {
        // delay=10 + rand()%25;
        tex.loadFromFile("img/redrectangle.png");
        bronze.setTexture(tex);
        bronze.setPosition(initialX,initialY);
        bronze.setScale(0.07,0.07);
    }
    
    void apply() override
    {
      bronze.setPosition(rand()%700,0);
    }
    Sprite& getSprite() override
    {
        return bronze;
    }
};

#endif