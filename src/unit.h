#ifndef UNIT_H_
#define UNIT_H_
#include "actor.h"
#include <memory>
#include "col_groups.h"
class Controller;

enum UnitType
{
    enemy,
    player,
    npc
};

class Unit : public Actor
{
public:
    Unit() = delete;
    Unit(Groups::ColGroup colGroup, std::string name, UnitType unitType, const char* texturePath, 
            SDL_Renderer* renderer, int x, int y, int w, int h);
    ~Unit() = default;

    void update();
    void takeDamage(unsigned int str);

private:
    void attack();

    UnitType     mUnitType;

    unsigned int hp;
    unsigned int maxHp;
    unsigned int atk;
    unsigned int def;
    
    std::string mName;
    std::shared_ptr<Unit> mTarget;
};
#endif // UNIT_H_