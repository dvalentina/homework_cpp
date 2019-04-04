#include <iostream>
#include "Forest.h"
#include "matrix_struct.h"
#include "Game.h"

int main()
{
    Game game;
    game.Run();
    /*size_t height = 0;
    size_t width = 0;

    std::cin >> height >> width;

    Forest forest(height, width);
    while (1)
    {
        getchar();
        std::cout << forest << "\n" << std::endl;
        forest.Update();
    }*/
    return 0;
}