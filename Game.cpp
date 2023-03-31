#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include <iostream>
#include <vector>

// new constructor using initialisation lists instead oif assingment statements
Game::Game(int maxComponents) : componentCount(0), components(new GameComponent*[maxComponents])
{   
}

//destructor
Game::~Game()
{
    for (int i = 0; i < componentCount; i++)
    {
        // Free the memory used by the components array
        delete components[i];
    }
}

//Add function to allocate memeory for a new GameComponent object and 
//then store a pointer to the new object in the components array
void Game::Add(GameComponent* component) {
    components[componentCount] = component;
    componentCount++;
}

// SetInitialise function to assign the address of a standalone function to the initialise data member
void Game::SetInitialise(FP initFunc){
    initialise = initFunc;
}

// SetTerminate function to assign the address of a standalone function to the terminate data member
void Game::SetTerminate(FP termFunc) {
    terminate = termFunc;
}

// Run function
void Game::Run()
{
    // Display initialization message
    std::cout << "Initializing game..." << std::endl;

    // Invoke initialization function, if one has been set
    if (initialise != nullptr)
    {
        initialise();
    }

    // Initialize timer for Update function
    std::chrono::time_point<std::chrono::system_clock> prevTime = std::chrono::system_clock::now();
    int numUpdates = 0;

    // Game loop
bool isRunning = true;
while (isRunning)
{
    // get current time
    auto currentTime = std::chrono::system_clock::now();

    // Convert the current time to a std::time_t value as currentTime_t
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

    // Convert the std::time_t value to a tm struct
    std::tm* eventTime = std::localtime(&currentTime_t);

    // Update components
    if (numUpdates < 5 && currentTime - prevTime > std::chrono::seconds(1))
    {
        for (int i = 0; i < componentCount; i++)
        {
            components[i]->Update(eventTime);

            // Check if the component is a DrawableGameComponent
            DrawableGameComponent* drawableComponent = dynamic_cast<DrawableGameComponent*>(components[i]);
            if (drawableComponent != nullptr)
            {
                // Call DrawableGameComponent::Update() to display direction information
                drawableComponent->Update(eventTime);
            }
        }
        numUpdates++;
        prevTime = currentTime;
    }

    // Terminate game loop after 5 seconds
    if (currentTime - prevTime > std::chrono::seconds(5))
    {
        isRunning = false;
    }
}

    // Invoke terminate function, if assigned
    if (terminate != nullptr)
    {
        terminate();
    }

    // Display termination message
    std::cout << "Terminating game..." << std::endl;
}