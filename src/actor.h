#ifndef ACTOR_H_
#define ACTOR_H_
#include <SDL2/SDL_image.h>
#include <memory>

class Actor
{
public:
    Actor(const char* texturePath, SDL_Renderer* renderer,
          int x, int y, int w, int h);
    ~Actor();
    Actor(const Actor& other) = delete;

    // gets a copy of mRect
    const SDL_Rect* getRect() const;

    void move(int x, int y, int gameWidth, int gameHeight);
    void draw(SDL_Renderer* renderer) const;

private:
    SDL_Texture*                mTexture;
    std::unique_ptr<SDL_Rect>   mRect;
};

#endif // ACTOR_H_