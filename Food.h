#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include<string.h>
#include <cmath>

using namespace sf;

class Food
{
public:
      virtual void apply() = 0;
      virtual Sprite& getSprite()=0; 
      virtual ~Food() {}  // Virtual destructor
};



#endif