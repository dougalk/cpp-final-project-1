#include "DrawableGameComponent.h"
#include <time.h>


bool printed[] = {false, false};

// Constructor
DrawableGameComponent::DrawableGameComponent(int id, int x, int y) : GameComponent(id), x(x), y(y), direction(Direction::Right)
{
    
}

// Update function
void DrawableGameComponent::Update(std::tm* eventTime)
{
    // Only print the object ID and update time if the ID is odd
    if (id % 2 == 1) {
        std::cout << "Object ID: " << id << ", Update invoked at: " << std::asctime(eventTime);
    }

    // Call ChangeDirection() to update the direction and position
    ChangeDirection();

    // Clamp x and y values
    x = std::max(x, 0);
    y = std::max(y, 0);

    // Call Draw() to print the direction, x, and y
    Draw();
}

//Draw Function
void DrawableGameComponent::Draw()
{
    switch (static_cast<int>(direction))
    {
        case 0: // Up
            std::cout << "Direction: Up | X: " << x << " | Y: " << y << std::endl;
            break;
        case 1: // Down
            std::cout << "Direction: Down | X: " << x << " | Y: " << y << std::endl;
            break;
        case 2: // Left
            std::cout << "Direction: Left | X: " << x << " | Y: " << y << std::endl;
            break;
        case 3: // Right
            std::cout << "Direction: Right | X: " << x << " | Y: " << y << std::endl;
            break;
    }
}

//Change Direction Function
void DrawableGameComponent::ChangeDirection()
{
    Direction newDirection;
    do {
        int random = rand() % 4;
        if (random == 0)
        {
            newDirection = Direction::Up;
        }
        else if (random == 1)
        {
            newDirection = Direction::Down;
        }
        else if (random == 2)
        {
            newDirection = Direction::Left;
        }
        else if (random == 3)
        {
            newDirection = Direction::Right;
        }
    } while (newDirection == direction);

    direction = newDirection;

    switch (static_cast<int>(direction))
    {
        case static_cast<int>(Direction::Up):
            y--;
            break;
        case static_cast<int>(Direction::Down):
            y++;
            break;
        case static_cast<int>(Direction::Left):
            x--;
            break;
        case static_cast<int>(Direction::Right):
            x++;
            break;
    }
}
