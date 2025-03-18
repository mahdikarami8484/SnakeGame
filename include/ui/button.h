#pragma once

#include "objects/object.h"

class Button : public Object {
    public:
        Button(
            std::string text, 
            Graphics::Property property, 
            Point point,
            Size size
        );

    public:
        std::string GetText() const;
    protected:
        void SetText(std::string const &text);
    protected:
        std::string _text;

    public:
        Graphics::Property GetProperty() const;
        void SetProperty(Graphics::Property const &property);
    protected:
        Graphics::Property _property;
    
    public:
        Point GetStartPoint() const;
    protected:
        void SetStartPoint(Point const &point);
    protected:
        Point _startPoint;

    public:
        Size GetSize() const;
    protected:
        void SetSize(Size const &size);
    protected:    
        Size _size;
    
    public:
        Point CurrentPoint() const;
        void SetCurrentPoint(Point const &value);
    
    protected:
        virtual std::string GetSkin() const override;
        virtual Graphics::Color GetForeground() const override;
        virtual Graphics::Color GetBackground() const override;
};