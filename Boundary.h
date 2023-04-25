#pragma once

#include "GameObject.h"

/**
 * @brief Boundary Game Object. Has collision and acts as a wall for both the ball and the paddles.
 *
 */
class Boundary : public GameObject
{
public:
    typedef GameObject super;

    Boundary();
    Boundary(float x, float y, float xl, float yl, float xv, float yv);

    void draw();
};
