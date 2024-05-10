#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"
using namespace sf;

class Box
{
public:
    RectangleShape shape;
    int directionX; // Direction of movement for the x-axis
    int directionY; // Direction of movement for the y-axis
    Food* F;
    // Default constructor
    Box() : directionX(0), directionY(0) {}

    // Parameterized constructor
    Box(float x, float y, float width, float height, int initialDirectionX, int initialDirectionY)
        : directionX(initialDirectionX), directionY(initialDirectionY)
    {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::Red);
    }

    void move(float speedX, float speedY)
    {
        shape.move(speedX * directionX, speedY * directionY);
    }
void handleInput(Box& smallBoxes)
{
    // Check if the player is within the specified boundaries
    sf::FloatRect globalBounds = smallBoxes.shape.getGlobalBounds();


    if ((globalBounds.left + globalBounds.width < 100 || globalBounds.left + globalBounds.width > 720) &&
        ((globalBounds.top >= 260 && globalBounds.top <= 440) || (globalBounds.top >= 510 && globalBounds.top <= 730)))
    {
        // Player is within the first set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            smallBoxes.directionX = 0;
            smallBoxes.directionY = -1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            smallBoxes.directionX = 0;
            smallBoxes.directionY = 1;
        }
    }
    else if ((globalBounds.left + globalBounds.width < 170 || globalBounds.left + globalBounds.width > 630) &&
            ((globalBounds.top >= 310 && globalBounds.top <= 440) || (globalBounds.top >= 510 && globalBounds.top <= 650)))
    {
        // Player is within the second set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            smallBoxes.directionX = 0;
            smallBoxes.directionY = -1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            smallBoxes.directionX = 0;
            smallBoxes.directionY = 1;
        }
    }
    else if (((globalBounds.left >= 40 && globalBounds.left < 340) || (globalBounds.left >= 410 && globalBounds.left < 710)) &&
            ((globalBounds.top < 250 ) ))
    {
        // Player is within the second set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            smallBoxes.directionX = -1;
            smallBoxes.directionY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            smallBoxes.directionX = 1;
            smallBoxes.directionY = 0;
        }
    }
    else if (((globalBounds.left > 40 && globalBounds.left < 340) || (globalBounds.left >= 410 && globalBounds.left < 710)) &&
            (globalBounds.top > 720 ) )
    {
        // Player is within the second set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            smallBoxes.directionX = -1;
            smallBoxes.directionY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            smallBoxes.directionX = 1;
            smallBoxes.directionY = 0;
        }
    }
    else if (((globalBounds.left >= 110 && globalBounds.left < 340) || (globalBounds.left >= 410 && globalBounds.left < 630)) &&
            ((globalBounds.top < 320 ) ))
    {
        // Player is within the second set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            smallBoxes.directionX = -1;
            smallBoxes.directionY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            smallBoxes.directionX = 1;
            smallBoxes.directionY = 0;
        }
    }
     else if (((globalBounds.left > 110 && globalBounds.left < 340) || (globalBounds.left >= 410 && globalBounds.left < 630)) &&
            (globalBounds.top > 650 ) )
    {
        // Player is within the second set of boundaries (left and right keys won't work)
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            smallBoxes.directionX = -1;
            smallBoxes.directionY = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            smallBoxes.directionX = 1;
            smallBoxes.directionY = 0;
        }
    }
    else
    {
       

    // Player is outside the specified boundaries, handle input normally
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        smallBoxes.directionX = 0;
        smallBoxes.directionY = -1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        smallBoxes.directionX = 0;
        smallBoxes.directionY = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        smallBoxes.directionX = -1;
        smallBoxes.directionY = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        smallBoxes.directionX = 1;
        smallBoxes.directionY = 0;
    }
   }
  }
  void useFood()
  {
    F->apply();
  }
};
