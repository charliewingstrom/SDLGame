#ifndef UNIT_H_
#define UNIT_H_
#include "actor.h"
#include <memory>

class Controller;

enum UnitType
{
    enemy,
    player,
    npc
};

class Unit
{
public:
    Unit() = delete;
    Unit(std::string name, std::shared_ptr<Actor> unitActor, UnitType unitType);
    // Unit(std::string name, const char* texturePath, SDL_Renderer* renderer, 
    //     int x, int y, int w, int h);
    ~Unit() = default;

    const std::shared_ptr<Actor> getActor() const;


private:
    UnitType     mUnitType;

    unsigned int hp;
    unsigned int maxHp;
    unsigned int atk;
    
    std::string mName;
    std::shared_ptr<Actor> mActor;
    std::shared_ptr<Unit> mTarget;
};
#endif // UNIT_H_