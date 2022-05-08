#ifndef ACTOR_H_
#define ACTOR_H_
#include <SDL2/SDL_image.h>
#include <memory>

class Unit;

class Actor
{
public:
    Actor(const char* texturePath, SDL_Renderer* renderer,
          int x, int y, int w, int h, std::shared_ptr<Unit> unit = nullptr);
    ~Actor();
    Actor(const Actor& other) = delete;

    // gets a copy of mRect
    const SDL_Rect* getRect() const;
    const std::shared_ptr<Unit> getUnit() const;

    void move(int x, int y, int gameWidth, int gameHeight);
    void revertLastMove();
    void draw(SDL_Renderer* renderer) const;

private:
    // last movement
    int prevX = 0;
    int prevY = 0;
    
    SDL_Texture*                mTexture;
    const std::shared_ptr<Unit> mUnit;
    std::unique_ptr<SDL_Rect>   mRect;
};

#endif // ACTOR_H_