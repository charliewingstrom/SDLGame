#ifndef PLAYER_CONTROLLER_H_
#define PLAYER_CONTROLLER_H_
#include "controller.h"

class PlayerController : public Controller
{
public:
    using Controller::Controller;
    virtual void acceptInput(int gameWidth, int gameHeight) const;
    virtual void update(int gameWidth, int gameHeight);
};
#endif // PLAYER_CONTROLLER_H_
