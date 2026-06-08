#pragma once

#include "..//ManagUsres//clsUser.h"
#include "..//Screen Ul//ClsScreen.h"
#include "Global.h"
#include "..//Screen Ul//ClsMainScren.h"
class clsLoginScreen : protected ClsScreen
{
private:
    static bool _Login()
    {
        bool LoginFild = false;
        string UsreName;
        string Passowrd;

        short FildLogincount = 0;
        do
        {
            if (LoginFild)
            {
                FildLogincount++;

                cout << "\nInvaled Usre/Passowrd:";
                cout << "\n You hav (s) [ " << (3 - FildLogincount) << "] trails to login\n\n";
            }
            if (FildLogincount == 3)
            {
                cout << "you are loked after three faild t  trails";
                return false;
            }
            cout << "Enter UsreNmae: ";
            cin >> UsreName;
            cout << "Enter Passowrd: ";
            cin >> Passowrd;

            CurrentUsre = clsUser::Find(UsreName, Passowrd);

            LoginFild = CurrentUsre.IsEmpty();

        } while (LoginFild);
         CurrentUsre.RegisterLogin();
        ClsMainScren::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLogingScreen()
    {

        _DrwScreenHeader("\t\t\t Login Screen");
        return _Login();
    }
};
