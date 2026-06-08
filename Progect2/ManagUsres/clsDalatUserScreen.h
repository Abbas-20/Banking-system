#pragma once
#include <iostream>

#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "clsUser.h"
using namespace std;

class clsDalatUsreScreen : protected ClsScreen
{
private:
    static void _PrintUsres(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName     : " << User.GetFirstName();
        cout << "\nLastName      : " << User.GetLastName();
        cout << "\nFull Name     : " << User.FullName();
        cout << "\nEmail         : " << User.GetEmail();
        cout << "\nPhone         : " << User.GetPhone();
        cout << "\nUsres Name    : " << User.GetUserName();
        cout << "\nPassowrd      : " << User.GetPassword();
        cout << "\nPermissions   : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    static void DalatUsre()
    {
       
        _DrwScreenHeader("\t\t\tDalat Usres");
        string UsersName = "";
        cout << "\nEnter is Usres Name: ";
        UsersName = clsInputValidate::ReadString();
        while (!(clsUser::IsUserExist(UsersName)))
        {
            cout << "\nUsres Name nubar is found choose another one: ";
            UsersName = clsInputValidate::ReadString();
        }

        clsUser Usres = clsUser::Find(UsersName);
        _PrintUsres(Usres);

        char Ansur;
        cout << "\nChoose y or n ?";
        cin >> Ansur;
        if (Ansur == 'Y' || Ansur == 'y')
        {

            if (Usres.Delete())
            {
                cout << "\nyse thim Dalat\n";
                _PrintUsres(Usres);
            }
            else
            {
                cout << "No Data";
            }
        }
    }
};
