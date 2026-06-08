#pragma once
#include <iostream>
#include <vector>
//#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Progect 2//clsString.h"

class clsClientListScreen : protected ClsScreen
{
private:

    static void _PrintClientList(clsBankClient vclient)
    {
        cout << "| " << left << setw(15) << vclient.GetFirstName();
        cout << "| " << left << setw(15) << vclient.GetLastName();
        cout << "| " << left << setw(15) << vclient.FullName();
        cout << "| " << left << setw(25) << vclient.GetEmail();
        cout << "| " << left << setw(12) << vclient.GetPhone();
        cout << "| " << left << setw(10) << vclient.GetPinCode();
        cout << "| " << left << setw(15) << vclient.getAccountNumber();
        cout << "| " << left << setw(10) << vclient.getAccountBalance();
        cout << "  ||\n";
    }

public:
    static void ShowlClientList()
    {
         if(!ChackAccessRigth(clsUser::enPermissions::pListClients)){
            return;
        }
        
        vector<clsBankClient> vClient = clsBankClient::GetPrintClientList();
        string Title = "\t\t\tClient List Client (S)";
        string SupTitle = "\t\t\t(" + to_string(vClient.size()) + ") Client (S)";
        _DrwScreenHeader(Title, SupTitle);

        cout << "=========================================================================================================================================\n";
        cout << "| " << left << setw(15) << "First Name";
        cout << "| " << left << setw(15) << "List Nmae ";
        cout << "| " << left << setw(15) << "Full Name";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(10) << "pin Code";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(10) << "Balance";
        cout << "  ||\n";
        cout << "=========================================================================================================================================\n";

        if (vClient.empty())
        {
            cout << "\t\t \tNo Clients Available In the System!" << endl;
        }
        else
        {
            for (clsBankClient &v : vClient)
            {
                _PrintClientList(v);
            }
        }
        cout << "=========================================================================================================================================\n";
    }
};
