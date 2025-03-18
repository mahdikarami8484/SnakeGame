#include "core/system.h"
#include "views/viewController.h"

int main()
{
    ViewController viewController;
    viewController.load(viewController.GetViewList().GetViewByName("GameView"));
    
    return 0;
}