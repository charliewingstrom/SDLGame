#include "unit.h"

Unit::Unit(Groups::ColGroup colGroup, std::string name, UnitType unitType, const char* texturePath, 
            SDL_Renderer* renderer, int x, int y, int w, int h)
    :Actor(colGroup, texturePath, renderer, x, y, w, h), mName(name), mUnitType(unitType), mSpeed(5)
{}

void Unit::update() 
{
    attack();
}

void Unit::attack()
{
}

void Unit::takeDamage(unsigned int atk)
{
    hp -= atk - def;
}

UnitType Unit::getUnitType() const 
{
    return mUnitType;
}

int Unit::getSpeed() const
{
    return mSpeed;
}
