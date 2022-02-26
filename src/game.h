#ifndef GAME_H_
#define GAME_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include <iostream>
#include "controller.h"
#include "unit.h"
#include "actor.h"

class Game
{
public:
    Game();
    ~Game();

    void startGame();

    void run();

    void stopGame();
private:
    std::shared_ptr<Unit> createUnit(std::string name, const char* texturePath, 
                    int x, int y, int w, int h);
    void checkCollisions();
    bool checkCollision(const std::shared_ptr<Actor> a1, const std::shared_ptr<Actor> a2) const;

    bool isRunning = true;

    const static int gameHeight = 1080;
    const static int gameWidth  = 1920;
    const static int fps        = 60;
    const static int frameDelay = 1000 / fps;

    int     frameTime   = 0;
    Uint32  frameStart  = 0;

    SDL_Window*     mWindow;
    SDL_Renderer*   mRenderer;

    std::shared_ptr<Controller>                 mPlayerController;
    std::vector<std::shared_ptr<Controller>>    mNpcController;
    std::vector<std::shared_ptr<Controller>>    mEnemyController;
    std::vector<std::shared_ptr<Actor>>         mActors;
    std::vector<std::shared_ptr<Unit>>          mUnits;
    std::map<std::shared_ptr<Actor>, std::vector<std::shared_ptr<Actor>>> mCollisions;
};

#endif // GAME_H_