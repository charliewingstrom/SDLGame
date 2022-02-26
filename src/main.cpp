#include "game.h"

int main(int argv, char** args)
{
    Game g;

    g.startGame();

    g.run();
    
    g.stopGame();

    return 0;
}