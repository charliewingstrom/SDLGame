#include "unit.h"

Unit::Unit(std::string name, std::shared_ptr<Actor> unitActor, UnitType unitType)
    :mName(name), mActor(unitActor), mUnitType(unitType)
{}

const std::shared_ptr<Actor> Unit::getActor() const
{
    return mActor;
}
