#pragma once 

#include "object.h"

class Food : public Object
{
public:
    Food(Point const &pos);

    void draw() override;
    
    void erase() override;

protected:
    virtual std::string GetSkin() const override;
    virtual Graphics::Color GetForeground() const override;
    virtual Graphics::Color GetBackground() const override;
};