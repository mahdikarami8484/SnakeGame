#pragma once 

#include "core/system.h"
#include "view.h"

class viewController {

    public:

        void load(int const view) const;
        

        void GetCurrentView() const;

    protected:

    protected:
        int _currentView;
        std::map<int, View> _views;
};