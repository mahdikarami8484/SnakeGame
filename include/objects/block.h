#pragma once

#include "object.h"

class Block : Object {

    public:
        Block(Point pos);

        virtual void draw() override;
        virtual void erase() override;
        virtual void move() override;

    protected:
        virtual std::string GetSkin() const override;
        virtual Graphics::Color GetForeground() const override;
        virtual Graphics::Color GetBackground() const override;
};