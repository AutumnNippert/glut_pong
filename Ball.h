#pragma once

#include "GameObject.h"
#include "Paddle.h"

/**
 * @brief Ball Game Object. Has collision and is a core component of the game
 *
 */
class Ball : public GameObject
{
public:
    typedef GameObject super;
    float rad;

    Ball();

    Ball(float x, float y, float r, float xv, float yv);

    void update(Paddle p1, Paddle p2);
    void draw();
    void reset();

private:
    float initialXPos;
    float initialYPos;
};

