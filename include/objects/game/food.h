#pragma once 

#include "object.h"

class Food : public Object
{
    public:
        Food();
        void draw() override;
        void erase() override;
        void handler_keys() override;
    
    private:
        std::string _skin = "*";
        Graphics::Color _color = Graphics::Color::Magenta;
        Graphics::Color _bg_color = Graphics::Color::Black;

};