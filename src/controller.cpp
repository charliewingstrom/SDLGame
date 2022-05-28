#include "controller.h"

Controller::Controller(std::shared_ptr<Unit> controlled, std::shared_ptr<Unit> target)
    :mUnit(controlled), mTarget(target)
{}

Controller::~Controller() 
{
    mUnit = nullptr;
}

void Controller::update(int gameWidth, int gameHeight) 
{
    // find diff in position between mUnit and mTarget
    if (mTarget != nullptr and mUnit != nullptr) {
        int x = (mTarget->getRect()->x - mUnit->getRect()->x) / 100;
        int y = (mTarget->getRect()->y - mUnit->getRect()->y) / 100;
        mUnit->move(x, y, gameWidth, gameHeight);
    }
}

void Controller::setTarget(std::shared_ptr<Unit> target) 
{
    mTarget = target;
}