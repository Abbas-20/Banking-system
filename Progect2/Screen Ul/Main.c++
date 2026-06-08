#include <iostream>

#include "ClsMainScren.h"
#include "..//Login//clsLoginScreen.h"
#include "..//Login//clsLoginScreen.h"

using namespace std;

int main()
{

    while (true)
    {
        if (!clsLoginScreen::ShowLogingScreen())
        {
            break;
        }
    }
}
