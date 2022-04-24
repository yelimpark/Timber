#include "Framework/GameFramework.h"
#include <iostream>

int main()
{
    GameFramework gameFramework;

    gameFramework.Init();

    return gameFramework.Run();
}