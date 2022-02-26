#ifndef CONTROLLER_H_
#define CONTORLLER_H_
#include <memory>
#include <SDL2/SDL.h>

#include "unit.h"

class Controller
{
public:
    Controller() = default;
    Controller(std::shared_ptr<Unit> controlledUnit);
    ~Controller();

    virtual void acceptInput(int gameWidth, int gameHeight, SDL_Event& event) const;
    virtual void acceptInput(int gameWidth, int gameHeight) const;

private:
    std::shared_ptr<Unit> mUnit;
};
#endif // CONTROLLER_H_