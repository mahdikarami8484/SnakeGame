#pragma once 

#include "object.h"

class Food : public Object
{
public:
    Food();
    void draw() override;
    void erase() override;

protected:
    virtual std::string GetSkin() const override;

private:
    Graphics::Color _color = Graphics::Color::Magenta;
    Graphics::Color _bg_color = Graphics::Color::Black;

};