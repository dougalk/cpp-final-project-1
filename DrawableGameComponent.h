#ifndef DRAWABLEGAMECOMPONENT_H
#define DRAWABLEGAMECOMPONENT_H
#pragma once
#include "GameComponent.h"
#include <iostream>
#pragma once

// Define the Direction enum
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

// DrawAbleGameComponent is inherited by GameComponent
class DrawableGameComponent : public GameComponent
{
public:
    // Default constructor
    DrawableGameComponent();

    // Constructor with integer arguments
    DrawableGameComponent(int id, int x, int y); //used to be componentId

    // Destructor
    ~DrawableGameComponent();

    // Update function
    void Update(std::tm* eventTime);

    Direction direction;

private:
    int x;
    int y;

    void Draw();
    void ChangeDirection();

};

#endif