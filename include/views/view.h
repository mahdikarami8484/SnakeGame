#pragma once

#include "core/graphics.h"
#include "core/system.h"

class View {
    public:
        virtual ~View() {}

        // Call during runtime
        virtual void start() = 0;

        // Call on every frame
        virtual void update() = 0;

        // Call on loop when game is pasue
        virtual void whenPause() = 0;

    public:
        virtual std::string GetName() const = 0;

    public:
        bool isRunning();
    
    protected:
        void run();
        void pause();
    
    protected:
        bool _run = true;
};