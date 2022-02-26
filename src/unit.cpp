#include "unit.h"

Unit::Unit(std::string name, std::shared_ptr<Actor> unitActor)
    :mName(name), mActor(unitActor)
{}

// Unit::Unit(std::string name, const char* texturePath, SDL_Renderer* renderer, 
//         int x, int y, int w, int h)
//     :mName(name)
// {
//     mActor = std::make_shared<Actor>(new Actor(texturePath, renderer, x, y, w, h));
// }

const std::shared_ptr<Actor> Unit::getActor() const
{
    return mActor;
}
