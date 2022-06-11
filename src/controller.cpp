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
    // create a vector len == 1 
    if (mTarget != nullptr and mUnit != nullptr) {
        float a = mTarget->getRect()->x - mUnit->getRect()->x;
        float b = mTarget->getRect()->y - mUnit->getRect()->y;

        float c = sqrt(a*a + b*b);
        
        float x = a / c;
        float y = b / c;

        x *= mUnit->getSpeed();
        y *= mUnit->getSpeed();

        mUnit->move(x, y, gameWidth, gameHeight);
    }
}

void Controller::setTarget(std::shared_ptr<Unit> target) 
{
    mTarget = target;
}