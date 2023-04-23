#include "GameObjects.h"

Paddle::Paddle() {}

Paddle::Paddle(float x, float y, float xl, float yl, float xv, float yv) : GameObject(x, y, xl, yl, xv, yv)
{
    red = 1.0f;
    green = 1.0f;
    blue = 1.0f;
}

void Paddle::draw()
{
    glPushMatrix();
    glTranslatef(xpos, ypos, 0.0f);
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(-xlen, -ylen);
    glVertex2f(-xlen, ylen);
    glVertex2f(xlen, ylen);
    glVertex2f(xlen, -ylen);
    glEnd();
    glPopMatrix();
}

void Paddle::update()
{
    if (yUpperBound > 1.0f)
    {
        yvel = 0.0f;
        ypos = 1.0f - ylen;
    }

    if (yLowerBound < -1.0f)
    {
        yvel = 0.0f;
        ypos = -1.0f + ylen;
    }

    super::update();
}