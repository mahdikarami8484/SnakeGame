#pragma once

#include "object.h"

class Block : Object {

    public:
        Block(Point const &pos) : Object(pos) {};

    protected:
        virtual std::string GetSkin() const override;
        virtual Graphics::Color GetForeground() const override;
        virtual Graphics::Color GetBackground() const override;
};