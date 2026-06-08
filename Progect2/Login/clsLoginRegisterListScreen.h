#pragma once
#include <iostream>
#include <iomanip>
#include "..//ManagUsres//clsUser.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Screen Ul//ClsMainScren.h"

class clsLoginRegisterListScreen:protected ClsScreen
{
private:
      static void _PrintUsresList(clsUser::stLoginRegisterRecord StLoginRegisterRecord)
    {
        cout << "| " << left << setw(25) << StLoginRegisterRecord.DateTime;
        cout << "| " << left << setw(15) << StLoginRegisterRecord.username;
        cout << "| " << left << setw(15) <<StLoginRegisterRecord.Passowrd;
        cout << "| " << left << setw(12) << StLoginRegisterRecord.Permissions;
        cout << "  ||\n";
    }
public:
    static void ShowlLoginRegisterRecord()
    {
         if(!ChackAccessRigth(clsUser::enPermissions::pShowLoginRegister)){
            return;
        }
        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord =clsUser::GetLoginRegisterList();
        string Title = "\t\t\tRegister List Screen (S)";
        string SupTitle = "\t\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Register (S)";
        _DrwScreenHeader(Title, SupTitle);

        cout << "===============================================================================\n";
        cout << "| " << left << setw(25) << "Data Time";                                 
        cout << "| " << left << setw(15) << "Users Name";
        cout << "| " << left << setw(15) << "Passowrd";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "  ||\n";
        cout << "===============================================================================\n";

        if (vLoginRegisterRecord.empty())
        {
            cout << "\t\t \tNo Register Available In the System!" << endl;
        }
        else
        {
            for (clsUser::stLoginRegisterRecord &v : vLoginRegisterRecord)
            {
                _PrintUsresList(v);
            }
        }
        cout << "===============================================================================\n";
    }

};


