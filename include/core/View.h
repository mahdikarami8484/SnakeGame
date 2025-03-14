#ifndef VIEW_H
#define VIEW_H

#include "core/Config.h"
#include "core/Console.h"

class View 
{
    public:

        virtual ~View() {}

        // Call during runtime
        virtual void start() = 0;

        // Call on every frame
        virtual void update() = 0;
};

#endif