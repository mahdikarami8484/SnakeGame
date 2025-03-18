#pragma once

#include "graphics.h"
#include "system.h"

class View {
    public:
        virtual ~View() {}

        // Call during runtime
        virtual void start() = 0;

        // Call on every frame
        virtual void update() = 0;

    public:
        virtual std::string GetName() const = 0;
};