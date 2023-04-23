#include <GL/glut.h>

struct GameObject;
class Ball;
class Paddle;
class Boundary;

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
    ~GameObject();

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