#include "GameComponent.h"
#include <iostream>

// Initialise the static member variable
int GameComponent::instances = 0;

// Constructor
GameComponent::GameComponent(int id)
{
    instances++;
    this->id = instances;
}

// Destructor
GameComponent::~GameComponent()
{
    instances--;
}

void GameComponent::Update(const tm* eventTime)
{
    // Display the object's ID and the time at which Update was invoked
    std::cout << "Object ID: " << id << ", Update invoked at: " << asctime(eventTime);
}