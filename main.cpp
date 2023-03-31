#include <iostream>
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"


//define the two standalone functions above main
void InitialiseGame()
{
    std::cout << "Game Initialised" << std::endl;
}

void TerminateGame()
{
    std::cout << "Game Finished" << std::endl;
}

// Main
// 1. Create a dynamic instance of Game
// 2. Invoke SetInitialise passing it one of the standalone function addresses.
// 3. Invoke SetTerminate passing it the other standalone function address.
// 4. Add a GameComponent object with an id of 1 to the game object
// 5. Add a DrawableGameComponent object with an id of 2 and a position of x=0,
// y=0 to the game object.
// 6. Invoke the game object’s run member function.

//main function
int main()
{
   // 1. Create a dynamic instance of Game 
    Game* game = new Game(1);

    // 2. Invoke SetInitialise passing it one of the standalone function addresses.
    game->SetInitialise(&InitialiseGame); //remove &?

    // 3. Invoke SetTerminate passing it the other standalone function address.
    game->SetTerminate(&TerminateGame);

    
    // 4. Add a GameComponent object with an id of 1 to the game object
    game->Add(new GameComponent(1));

    // 5. Add a DrawableGameComponent object with an id of 2 and a position of x=0, y=0 to the game object.
    game->Add(new DrawableGameComponent(2, 0, 0));
    

    // 6. Invoke the game object’s run member function.
    game->Run();

    return 0;

}
