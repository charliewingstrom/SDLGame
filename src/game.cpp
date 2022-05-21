#include "game.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    mWindow     = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gameWidth, gameHeight, 0);
    mRenderer   = SDL_CreateRenderer(mWindow, -1, 0);
    mEvent      = std::make_unique<SDL_Event>();
}

Game::~Game()
{
}

void Game::startGame()
{   
    createActor(Groups::ColGroup::Background, "assets/space.png", 0, 0, 1920, 1080);
    createUnit(Groups::ColGroup::Unit, UnitType::player, "player", "assets/player.png", (gameWidth / 2) - 150, (gameHeight / 1.3) - 150, 100, 100);
    createUnit(Groups::ColGroup::Unit, UnitType::enemy, "enemy", "assets/enemy.png", (gameWidth / 2) - 150, (gameHeight / 3) - 150, 100, 100);
}

void Game::run()
{
    while (isRunning) {
        frameStart = SDL_GetTicks();
        
        acceptInput();
        
        update();

        draw();

        // check frame rate
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::update() 
{
    // pre input
    checkCollisions();

    // check for quiting
    while (SDL_PollEvent(mEvent.get()))
    {
        switch (mEvent->type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            switch(mEvent->key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                
            }
        }
    }
}

void Game::acceptInput()
{
    mPlayerController->acceptInput(gameWidth, gameHeight);

}

void Game::draw()
{
    // draw
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    for (std::shared_ptr<Actor> currActor : mActors) {
        currActor->draw(mRenderer);
    }

    SDL_RenderPresent(mRenderer);
}

void Game::stopGame()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

void Game::createUnit(Groups::ColGroup colGroup, UnitType unitType, std::string name, const char* texturePath, 
                        int x, int y, int w, int h)
{
    std::shared_ptr<Unit> createdUnit;
    createdUnit = std::make_shared<Unit>(colGroup, name, unitType, texturePath, mRenderer, x, y, w, h);
    mUnits.push_back(createdUnit);
    mActors.push_back(createdUnit);
    switch (unitType)
    {
    case UnitType::player:
        mPlayerController = std::make_shared<Controller>(createdUnit);
        break;

    case UnitType::enemy:
        mEnemyController.push_back(std::make_shared<Controller>(createdUnit));
        break;
    case UnitType::npc:
        mNpcController.push_back(std::make_shared<Controller>(createdUnit));
        break;


    //default:
        // TODO log here
        //break;
    }
}

void Game::createActor(Groups::ColGroup colGroup, const char* texturePath, int x, int y, int w, int h)
{
    mActors.push_back(std::make_shared<Actor>(colGroup, texturePath, mRenderer, x, y, w, h));
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

    // undo movements for players that are colliding
    for (auto const& [actor, colliders] : mCollisions) {
        for (auto const& collidingActor : colliders) {
            collidingActor->revertLastMove();
        }
    }
}

bool Game::checkCollision(const std::shared_ptr<Actor> a1, const std::shared_ptr<Actor> a2) const
{
    return SDL_HasIntersection(a1->getRect(),a2->getRect()) and (a1->getColGroup() == a2->getColGroup());
}