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
    
}

