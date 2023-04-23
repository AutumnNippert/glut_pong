#include <iostream>

#include <cstdlib> // rand()

#include "GameObjects.h"

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720
#define SCREEN_FPS 60

class GameController
{
public:
    Paddle paddle;
    int score = 0;

    GameController() {}

    GameController(Paddle p)
    {
        paddle = p;
    }

    void update(Ball ball)
    {
        paddle.update();
    }

    void draw()
    {
        paddle.draw();
    }

    void moveUp()
    {
        paddle.yvel = paddle.speed;
    }

    void moveDown()
    {
        paddle.yvel = -paddle.speed;
    }

    void reset()
    {
        paddle.reset();
    }
};

class PlayerController : public GameController
{
public:
    typedef GameController super;

    PlayerController() {}

    PlayerController(Paddle p)
    {
        paddle = p;
    }
};

class AIController : public GameController
{
public:
    typedef GameController super;

    AIController() {}

    AIController(Paddle p)
    {
        paddle = p;
    }

    void update(Ball ball)
    {
        // brain
        // if ball above paddle, move up
        // if ball below paddle, move down

        if (ball.ypos > paddle.ypos)
        {
            moveUp();
        }
        else if (ball.ypos < paddle.ypos)
        {
            moveDown();
        }

        super::update(ball);
    }

    void draw()
    {
        paddle.draw();
    }

    void moveUp()
    {
        paddle.yvel = paddle.speed;
    }

    void moveDown()
    {
        paddle.yvel = -paddle.speed;
    }

    void reset()
    {
        paddle.reset();
    }
};

class Game
{
public:
    Boundary gameBounds;

    PlayerController p1;
    AIController p2;
    Ball ball;

    Game()
    {
        gameBounds = Boundary(0.0f, 0.0f, 0.95f, 0.95f, 0.0f, 0.0f);

        p1 = PlayerController(Paddle(-0.85f, 0.0f, 0.05f, 0.3f, 0.0f, 0.0f));
        p2 = AIController(Paddle(0.85f, 0.0f, 0.05f, 0.3f, 0.0f, 0.0f));
        ball = Ball(0.0f, 0.0f, 0.05f, 0.01f, 0.01f);

        // for random ball spawns basically
        reset();
    }

    void update()
    {
        p1.update(ball);
        p2.update(ball);
        ball.update(p1.paddle, p2.paddle);

        // check if the ball is out of bounds
        // check if ball collide with upperBound or lowerBound
        if (ball.yUpperBound >= gameBounds.yUpperBound || ball.yLowerBound <= gameBounds.yLowerBound)
        {
            ball.yvel = -ball.yvel;
        }

        // check if ball collide with rightBound
        if (ball.xRightBound <= gameBounds.xLeftBound)
        {
            p2.score++;
            std::cout << "Player 2 scored!" << std::endl;
            reset();
        }

        // check if ball collide with leftBound
        if (ball.xLeftBound >= gameBounds.xRightBound)
        {
            p1.score++;
            std::cout << "Player 1 scored!" << std::endl;
            reset();
        }
    }

    void draw()
    {
        p1.draw();
        p2.draw();
        ball.draw();
    }

    void reset()
    {
        p1.reset();
        p2.reset();
        ball.reset();
    }
};

Game game = Game(); // global game object

void processNormalKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        game.p1.moveUp();
        break;
    case 's':
        game.p1.moveDown();
        break;
    case 'q':
        exit(0);
    }
}

void processSpecialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        game.p1.moveUp();
        break;
    case GLUT_KEY_DOWN:
        game.p1.moveDown();
        break;
    }
}

void display()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the game
    game.draw();

    // Swap the front and back buffers (double buffering)
    glutSwapBuffers();
}

void update(int value)
{
    // Update the object's position
    game.update();

    // Redraw the scene
    glutPostRedisplay();

    // Call update() again after 16 milliseconds (60 frames per second)
    int ms = 1000 / SCREEN_FPS;
    glutTimerFunc(ms, update, 0);
}

int main(int argc, char **argv)
{
    srand(time(0));

    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Pong");

    // Set up the display and update callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutTimerFunc(0, update, 0);

    // Start the main loop
    glutMainLoop();

    return 0;
}