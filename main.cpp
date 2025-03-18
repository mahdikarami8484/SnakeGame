#include <windows.h>
#include "core/system.h"
#include "views/viewController.h"

int main()
{
    HANDLE event = CreateEvent(NULL, TRUE, FALSE, NULL);

    ViewController viewController;
    viewController.load(viewController.GetViewList().GetViewByName("GameView"));

    WaitForSingleObject(event, INFINITE);
    CloseHandle(event);
    
    return 0;
}