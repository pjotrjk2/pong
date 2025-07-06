#include <raylib.h>
#include "game.h"

class Game;

main()
{
    Game game(true);
    game.StartGame();

    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }

    game.End();
    return 0;
}
