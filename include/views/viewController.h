#pragma once 

#include "core/system.h"
#include "view.h"

class ViewController {

    protected:
        class ViewList {
            public:
                void addView(std::string const &name, std::shared_ptr<View> view);
                void GetViewByName(std::string const &name);
            
            protected:
                std::vector<std::shared_ptr<View>> views;
                std::unordered_map<std::string, std::shared_ptr<View>> name_map;
        };

    public:
        ViewController();

    public:
        void load(ViewList view) const;
        void GetCurrentView() const;
        void loadNextView() const;

    public:
        void GetViewList() const;

    protected:
        ViewList _viewList;

};