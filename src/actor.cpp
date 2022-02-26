#include "actor.h"

Actor::Actor(const char* texturePath, SDL_Renderer* renderer,
             int x, int y, int w, int h)
{
    SDL_Surface* tmpSurface = IMG_Load(texturePath);
    mTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    mRect.x = x;
    mRect.y = y;
    mRect.w = w;
    mRect.h = h;
}

Actor::~Actor()
{
    SDL_DestroyTexture(mTexture);
}

Actor::Actor(const Actor& other)
{
    mTexture = other.mTexture;
    mRect = other.mRect;
}

const SDL_Rect Actor::getRect() const
{
    return mRect;
}

void Actor::move(int x, int y, int gameWidth, int gameHeight)
{
    if (mRect.x + x < gameWidth - mRect.w and mRect.x + x > 0)
        mRect.x += x;
    if (mRect.y + y < gameHeight - mRect.h and mRect.y + y > 0)
        mRect.y += y;
}

void Actor::draw(SDL_Renderer* renderer) const
{
    SDL_RenderCopy(renderer, mTexture, NULL, &mRect);
}
