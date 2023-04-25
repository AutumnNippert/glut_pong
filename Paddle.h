#pragma once

#include "GameObject.h"

/**
 * @brief Paddle Game Object. Has collision and is the playable part of the game.
 *
 */
class Paddle : public GameObject
{
public:
    typedef GameObject super;
    float speed = 0.02f;

    Paddle();
    Paddle(float x, float y, float xl, float yl, float xv, float yv);

    void draw();
    void update();
};
