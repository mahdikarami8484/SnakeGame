#pragma once 

#include "object.h"

class Food : public Object
{
public:
    Food();
    void Draw() override;
    void Erase() override;

protected:
    virtual std::string GetSkin() const override;
    virtual Graphics::Color GetForeground() const override;
    virtual Graphics::Color GetBackground() const override;
};