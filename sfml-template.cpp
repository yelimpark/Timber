#include "Framework/GameFramework.h"
#include <iostream>

int main()
{
    GameFramework gameFramework;
    if (!gameFramework.Init()) {
        std::cout << "Initialize Failed." << std::endl;
        return -1;
    }

    return gameFramework.Run();
}