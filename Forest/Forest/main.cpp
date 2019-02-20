#include <iostream>
#include "forest.h"

int main()
{
    size_t height = 0;
    size_t width = 0;

    std::cin >> height >> width;

    Forest forest(height, width);
    while (1)
    {
        getchar();
        std::cout << forest << "\n" << std::endl;
        forest.Update();
    }
    return 0;
}