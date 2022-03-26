#include "unit.h"

Unit::Unit(std::string name, std::shared_ptr<Actor> unitActor)
    :mName(name), mActor(unitActor)
{}

const std::shared_ptr<Actor> Unit::getActor() const
{
    return mActor;
}
