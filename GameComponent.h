#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H
#include <ctime> //for use of tm
#pragma once

class DrawableGameComponent;

class GameComponent{

    friend class DrawableGameComponent;
    
public:

    // Constructor
    GameComponent(int id);

    // Update function using const tm* instead of float
    virtual void Update(const tm* eventTime); //Use polymorphism to call the correct Update function (by adding virutal)

    // Destructor
    ~GameComponent();

private:
    int id;
    static int instances;
};

#endif