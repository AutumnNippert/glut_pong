#include "GameObjects.h"

typedef GameObject super;

Boundary::Boundary() {}

Boundary::Boundary(float x, float y, float xl, float yl, float xv, float yv) : GameObject(x, y, xl, yl, xv, yv)
{
    red = 1.0f;
    green = 0.5f;
    blue = 0.5f;
}

void Boundary::draw()
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