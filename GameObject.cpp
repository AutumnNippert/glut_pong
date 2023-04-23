#include "GameObjects.h"

GameObject::GameObject() {}

GameObject::GameObject(float xPos, float yPos, float xLen, float yLen, float xVel, float yVel)
{
    xlen = xLen;
    ylen = yLen;

    xLeftBound = xpos - xLen;
    xRightBound = xpos + xLen;
    yUpperBound = ypos + yLen;
    yLowerBound = ypos - yLen;

    xpos = xPos;
    ypos = yPos;

    xvel = xVel;
    yvel = yVel;

    initialXPos = xpos;
    initialYPos = ypos;
}

GameObject::~GameObject() {}

bool GameObject::isColliding(GameObject other)
{
    float futureXRightBound = xRightBound + xvel;
    float futureXLeftBound = xLeftBound + xvel;
    float futureYUpperBound = yUpperBound + yvel;
    float futureYLowerBound = yLowerBound + yvel;
    if (futureXRightBound >= other.xLeftBound && futureXLeftBound <= other.xRightBound)
    {
        if (futureYUpperBound >= other.yLowerBound && futureYLowerBound <= other.yUpperBound)
        {
            return true;
        }
    }
    return false;
}

void GameObject::update()
{
    xpos += xvel;
    ypos += yvel;

    // update bounds
    xLeftBound = xpos - xlen;
    xRightBound = xpos + xlen;
    yUpperBound = ypos + ylen;
    yLowerBound = ypos - ylen;
}

void GameObject::reset()
{
    xpos = initialXPos;
    ypos = initialYPos;
}