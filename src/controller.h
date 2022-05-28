#ifndef CONTROLLER_H_
#define CONTORLLER_H_
#include <memory>
#include <SDL2/SDL.h>

#include "unit.h"

class Controller
{
public:
    Controller() = default;
    Controller(std::shared_ptr<Unit> controlledUnit, std::shared_ptr<Unit> targetUnit = nullptr);
    ~Controller();

    virtual void update(int gameWidth, int gameHeight);

    void setTarget(std::shared_ptr<Unit> target);

protected:
    std::shared_ptr<Unit> mUnit;
    std::shared_ptr<Unit> mTarget;
};
#endif // CONTROLLER_H_