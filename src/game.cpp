#include "game.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    mWindow     = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gameWidth, gameHeight, 0);
    mRenderer   = SDL_CreateRenderer(mWindow, -1, 0);

}

Game::~Game()
{
}

void Game::startGame()
{   
    mPlayerController = std::make_shared<Controller>(createUnit("player", "assets/player.png", (gameWidth / 2) - 150, (gameHeight / 1.3) - 150, 300, 300));
    
    std::shared_ptr<Unit> enemy = createUnit("enemy", "assets/enemy.png", (gameWidth / 2) - 150, (gameHeight / 3) - 150, 300, 300);
    std::shared_ptr<Controller> enemyController = std::make_shared<Controller>(enemy);
}

void Game::run()
{
    SDL_Event event;
    while (isRunning) {
        frameStart = SDL_GetTicks();
        
        // pre input
        checkCollisions();

        // check for quiting
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                    
                }
            }
        }

        // accept other inputs
        mPlayerController->acceptInput(gameWidth, gameHeight);

        // draw
        SDL_RenderClear(mRenderer);
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

        for (std::shared_ptr<Actor> currActor : mActors) {
            currActor->draw(mRenderer);
        }

        SDL_RenderPresent(mRenderer);

        // check frame rate
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::stopGame()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

std::shared_ptr<Unit> Game::createUnit(std::string name, const char* texturePath, 
                        int x, int y, int w, int h)
{
    std::shared_ptr<Actor> createdActor = std::make_shared<Actor>(texturePath, mRenderer, x, y, w, h);
    mActors.push_back(createdActor);
    std::shared_ptr<Unit> createdUnit = std::make_shared<Unit>(name, createdActor);
    mUnits.push_back(createdUnit);

    return createdUnit;
}

void Game::checkCollisions()
{
    mCollisions.clear();

    for (std::shared_ptr<Actor> currActor : mActors) {
        std::vector<std::shared_ptr<Actor>> collidingActors;
        for (std::shared_ptr<Actor> collidingActor : mActors) {
            if (currActor != collidingActor and checkCollision(currActor, collidingActor)) {
                collidingActors.push_back(collidingActor);
                std::cout << "Collision" << std::endl;
            }
        }
        mCollisions.insert(std::make_pair(currActor, collidingActors));
    }
}

bool Game::checkCollision(const std::shared_ptr<Actor> a1, const std::shared_ptr<Actor> a2) const
{
    return SDL_HasIntersection(a1->getRect(),a2->getRect());
}