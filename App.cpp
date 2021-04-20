#include <iostream>
#include "App.h"

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    ship = new TexRect("images/ship.png", -0.8, -0.6, 0.3, 0.4);
    isMovingUp = false;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;

    background = new TexRect("images/sky.png", -1, 1, 2, 2);
    enemies.push_back(new TexRect("images/monster.png", -0.9, 0.8, 0.3, 0.3));
    enemies.push_back(new TexRect("images/monster.png", -0.5, 0.8, 0.3, 0.3));
    enemies.push_back(new TexRect("images/monster.png", -0.0, 0.8, 0.3, 0.3));
    enemies.push_back(new TexRect("images/monster.png", 0.5, 0.8, 0.3, 0.3));

    alive = true;
    enemyAlive = true;

    inc = 0.02;
}

void App::draw() const {

    background->draw(0.0);

    if (alive){
        ship->draw(0.1);
    }
   
    

    for (auto missile = missiles.begin(); missile != missiles.end(); missile++){
        (*missile)->draw(0.2);
    }

    for (auto i = enemies.begin(); i != enemies.end(); i++){
        (*i)->draw(0.2);
    }
    
    
    
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    else if (key == ' '){
        missiles.push_back(new TexRect("images/shoot.png", ship->getX() + ship->getW()/2 - 0.01, ship->getY()+0.02, 0.045, 0.06));
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    else if (key == 'w'){
        isMovingUp = true;
    }
    else if (key == 'a'){
        isMovingLeft = true;
    }
    else if (key == 's'){
        isMovingDown = true;
    }
    else if (key == 'd'){
        isMovingRight = true;
    }
    redraw();
}

void App::keyUp(unsigned char key, float x, float y){
    if (key == 'w'){
        isMovingUp = false;
    }
    else if (key == 'a'){
        isMovingLeft = false;
    }
    else if (key == 's'){
        isMovingDown = false;
    }
    else if (key == 'd'){
        isMovingRight = false;
    }
    redraw();
}

void App::idle(){
    if (isMovingUp){
        ship->moveUp(inc);
        redraw();
    }
    else if (isMovingDown){
        ship->moveDown(inc);
        redraw();
    }
    else if (isMovingLeft){
        if (ship->getX() > -1){
            ship->moveLeft(inc);
            redraw();
        }
    }
    else if (isMovingRight){
        if (ship->getX() < 0.7){
            ship->moveRight(inc);
            redraw();
        }
    }

    for (auto i = enemies.begin(); i != enemies.end(); i++){
        if ((*i)->didCollide(ship)){
            alive = false;
            redraw();
            break;
        }
    }

    for (auto missile = missiles.begin(); missile != missiles.end(); missile++){
        (*missile)->moveUp(0.1);

        for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
            if ((*enemy)->didCollide(*missile)){
                delete *enemy;
                enemies.erase(enemy);
                break;
            }
        }

        if ((*missile)->getY() > 1){
            delete *missile;
            missiles.erase(missile);
            missile--;
        }
    }

    redraw();
}

App::~App(){   
    delete ship;
    delete background;

    for (auto i = enemies.begin(); i != enemies.end(); i++){
        delete *i;
    }

    for (auto i = missiles.begin(); i != missiles.end(); i++){
        delete *i;
    }
    
    std::cout << "Exiting..." << std::endl;
}
