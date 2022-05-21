#ifndef ACTOR_H_
#define ACTOR_H_
#include <SDL2/SDL_image.h>
#include <memory>
#include "col_groups.h"
class Actor
{
public:
    Actor(Groups::ColGroup colGroup, const char* texturePath, SDL_Renderer* renderer,
          int x, int y, int w, int h);
    ~Actor();
    Actor(const Actor& other) = delete;

    // gets a copy of mRect
    const SDL_Rect* getRect() const;
    const Groups::ColGroup getColGroup() const;

    void move(int x, int y, int gameWidth, int gameHeight);
    void revertLastMove();
    
    void draw(SDL_Renderer* renderer) const;

private:
    // last movement
    int prevX = 0;
    int prevY = 0;
    
    SDL_Texture*                mTexture;
    std::unique_ptr<SDL_Rect>   mRect;
    Groups::ColGroup            mColGroup;
};

#endif // ACTOR_H_