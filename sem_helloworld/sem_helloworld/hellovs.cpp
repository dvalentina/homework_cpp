#include <iostream>
#include "profile.h"

int main()
{	LOG_DURATION("test");
	//std::cout << "Hello, VS2015." << std::endl;
    for (int i = 0; i < 10000000; ++i)
    {
        ;
    }
    return 0;
}