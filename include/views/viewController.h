#pragma once 

#include "core/system.h"
#include "view.h"

class ViewController {

    protected:
    void SetCurrentView(std::shared_ptr<View> view);

    public:
        class ViewList {
            public:
                void addView(std::string const &name, std::shared_ptr<View> view);
                std::shared_ptr<View> GetViewByName(std::string const &name) const;
            
            protected:
                std::vector<std::shared_ptr<View>> views;
                std::unordered_map<std::string, std::shared_ptr<View>> name_map;
        };

    public:
        ViewController();

    public:
        void load(std::shared_ptr<View> view);
        void unLoad();

        std::shared_ptr<View> GetCurrentView() const;
        bool isViewLoaded() const;

        void loadNextView() const;

    public:
        ViewList GetViewList() const;


    protected:
        ViewList _viewList;
        std::shared_ptr<View> _currentView;
        bool _viewLoaded;
};