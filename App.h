#ifndef App_h
#define App_h
#include <vector>

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"


class App: public GlutApp {

    TexRect* ship;
    std::vector<TexRect*> missiles;

    TexRect* background;
    
    std::vector<TexRect*> enemies;

    bool isMovingUp;
    bool isMovingDown;
    bool isMovingLeft;
    bool isMovingRight;

    bool alive;
    bool enemyAlive;

    float inc;

public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);

    void idle();
    
    ~App();
};

#endif
