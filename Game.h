#ifndef GAME_H
#define GAME_H
#include <vector>
#pragma once

// Define the FP typedef representing a type of function that returns void and has no parameters
typedef void (*FP)();

// Forward declaration of GameComponent and DrawableGameComponent classes
class GameComponent;
class DrawableGameComponent;

//declaring Game Class
class Game
{
public:
    //Constructor and destructor
    Game(int maxComponents);
    ~Game();

    // Function to add a new GameComponent object to the components array
    void Add(GameComponent* component);

    // Run Function
    void Run();

    // SetInitialise function to assign the address of a standalone function to the initialise data member
    void SetInitialise(FP initFunc);

    // SetTerminate function to assign the address of a standalone function to the terminate data member
    void SetTerminate(FP termFunc);

private:

    // Declare components as a private member of the Game class
    GameComponent** components;

    // Number of components in the array
    int componentCount;

    // Pointer to a standalone initialisation function
    FP initialise;

    // Pointer to a standalone terminate function
    FP terminate;
};

#endif
