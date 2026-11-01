#include <iostream>
#include "game.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

int main()
{

    Game game = Game(800, 600);
    game.run();

    return 0;
}