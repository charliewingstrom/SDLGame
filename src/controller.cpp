#include "controller.h"

Controller::Controller(std::shared_ptr<Unit> controlledUnit)
{
    mUnit = controlledUnit;
}

Controller::~Controller() 
{
    mUnit = nullptr;
}

void Controller::acceptInput(int gameWidth, int gameHeight, SDL_Event& event) const
{
}

void Controller::acceptInput(int gameWidth, int gameHeight) const
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    int xMov = 0;
    int yMov = 0;

    if (state[SDL_SCANCODE_UP]) {
        yMov -= 10;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        yMov += 10;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        xMov -= 10;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        xMov += 10;
    }

    mUnit->move(xMov, yMov, gameWidth, gameHeight);
}