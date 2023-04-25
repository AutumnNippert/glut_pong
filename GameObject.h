#pragma once

#include <GL/glut.h>

/**
 * @brief A struct that represents a game object. (everything on the screen)
 *
 */
struct GameObject
{
private:
    float initialXPos;
    float initialYPos;

public:
    // default values
    float xpos = 0.0f;
    float ypos = 0.0f;

    float xvel = 0.0f;
    float yvel = 0.0f;

    float xlen = 0.0f;
    float ylen = 0.0f;

    float xLeftBound;
    float xRightBound;
    float yUpperBound;
    float yLowerBound;

    float red;
    float green;
    float blue;

    GameObject();
    GameObject(float xPos, float yPos, float xLen, float yLen, float xVel, float yVel);
    virtual ~GameObject();

    /**
     * @brief Function to draw the object on the screen.
     *
     */
    virtual void draw();

    /**
     * @brief Function to update the object's position and variables.
     *
     */
    void update();

    /**
     * @brief Function to reset the object to its initial position.
     *
     */
    void reset();

    /**
     * @brief Function to check if the object is colliding with another object.
     *
     * @param other The other object to check collision with.
     * @return true if is colliding
     * @return false if not colliding
     */
    bool isColliding(GameObject other);
};
