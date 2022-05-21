#include "unit.h"

Unit::Unit(Groups::ColGroup colGroup, std::string name, UnitType unitType, const char* texturePath, 
            SDL_Renderer* renderer, int x, int y, int w, int h)
    :Actor(colGroup, texturePath, renderer, x, y, w, h), mName(name), mUnitType(unitType)
{}

void Unit::update() 
{
    attack();
}

void Unit::attack()
{
    if (mTarget != nullptr) {
        // attack the target
        mTarget->takeDamage(atk);
    }
}

void Unit::takeDamage(unsigned int atk)
{
    hp -= atk - def;
}