#include "Ball.h"
#include <cmath>

float randInRange(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float getRandomBallSpeed(float min1, float max1, float min2, float max2)
{
    // get random 0 or 1
    int randNum = rand() % 2;

    if (randNum == 0)
    {
        return randInRange(min1, max1);
    }
    else
    {
        return randInRange(min2, max2);
    }
}

Ball::Ball() {}

Ball::Ball(float x, float y, float r, float xv, float yv) : GameObject(x, y, r, r, xv, yv)
{
    rad = r;

    red = 1.0f;
    green = 1.0f;
    blue = 1.0f;
}

void Ball::draw()
{
    glPushMatrix();
    glTranslatef(xpos, ypos, 0.0f);
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159 / 180;
        glVertex2f(rad * cos(theta), rad * sin(theta));
    }
    glEnd();
    glPopMatrix();
}

void Ball::update(Paddle p1, Paddle p2)
{
    super::update();

    // Check for collision with the edges of the window
    if (ypos > 1.0f || ypos < -1.0f)
    {
        yvel *= -1.1f;
    }

    // Check for collision with the paddles
    if (isColliding(p1) || isColliding(p2))
    {
        xvel *= -1.1f;
        yvel *= 1.1f;
    }
}

void Ball::reset()
{
    super::reset();

    // rand float between -0.1f and 0.1f
    xvel = getRandomBallSpeed(-0.03, -0.015f, 0.015f, 0.03f);
    yvel = getRandomBallSpeed(-0.02, -0.005f, 0.005f, 0.02f);
}
