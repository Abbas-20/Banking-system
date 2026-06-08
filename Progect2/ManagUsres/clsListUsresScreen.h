#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "..//Screen Ul//ClsScreen.h"

class clsListUsresScreen:protected ClsScreen
{
private:
      static void _PrintUsresList(clsUser vUsers)
    {
        cout << "| " << left << setw(10) << vUsers.GetUserName();
        cout << "| " << left << setw(15) << vUsers.FullName();
        cout << "| " << left << setw(25) << vUsers.GetEmail();
        cout << "| " << left << setw(12) << vUsers.GetPhone();
    
        cout << "| " << left << setw(12) << vUsers.GetPassword();
        cout << "| " << left << setw(12) << vUsers.GetPermissions();
        cout << "  ||\n";
    }
public:
    static void ShowlUsresList()
    {
       
        vector<clsUser> vUser = clsUser::GetUsersList();
        string Title = "\t\t\tUsers List Screen (S)";
        string SupTitle = "\t\t\t(" + to_string(vUser.size()) + ") Useres (S)";
        _DrwScreenHeader(Title, SupTitle);

        cout << "======================================================================================================\n";
        cout << "| " << left << setw(10) << "Users Name";

        cout << "| " << left << setw(15) << "Full Name";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(12) << "Phone";

        cout << "| " << left << setw(12) << "Passowrd";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "  ||\n";
        cout << "======================================================================================================\n";

        if (vUser.empty())
        {
            cout << "\t\t \tNo Users Available In the System!" << endl;
        }
        else
        {
            for (clsUser &v : vUser)
            {
                _PrintUsresList(v);
            }
        }
        cout << "======================================================================================================\n";
    }

};


