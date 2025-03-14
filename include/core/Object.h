#ifndef OBJECT_H
#define OBJECT_H

#include <windows.h>
#include <iostream>
#include "Config.h"
#include "Console.h"

class Object 
{
    public:
        std::string skin;

        // Destructor: Called when the object is removed/destroyed from the view.
        virtual ~Object() {}

        // Draw the object on the view.
        virtual void draw() = 0;

        // Erase or clear the object from the view.
        virtual void erase() = 0;

        // Move the object to a new position in the view.
        virtual void move() = 0;

        // Handles keyboard input and processes key events.
        virtual void handler_keys() = 0;
};

#endif