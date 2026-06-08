#pragma once
#include <iostream>

#include "..//Progect 2//clsInputValidate.h"
#include "clsBankclient.h"
#include "..//Screen Ul//ClsScreen.h"

using namespace std;

class clsDalatClient : protected ClsScreen
{
private:
    static void _PrintClient(clsBankClient Client1)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName     : " << Client1.GetFirstName();
        cout << "\nLastName      : " << Client1.GetLastName();
        cout << "\nFull Name     : " << Client1.FullName();
        cout << "\nEmail         : " << Client1.GetEmail();
        cout << "\nPhone         : " << Client1.GetPhone();
        cout << "\nPassword      : " << Client1.GetPinCode();
        cout << "\nAccount Number: " << Client1.getAccountNumber();
        cout << "\nBalances      : " << Client1.getAccountBalance();
        cout << "\n___________________\n";
    }

public:
    static void DalatClient()
    {
         if(!ChackAccessRigth(clsUser::enPermissions::pDeleteClient)){
            return;
        }
        
        _DrwScreenHeader("\t\t\tDalat Client");
        string AccountNumber = "";
        cout << "\nEnter is Account nubar: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!(clsBankClient::IsClientExsit(AccountNumber)))
        {
            cout << "\nAccount nubar is found choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client2);

        char Ansur;
        cout << "\nChoose y or n ?";
        cin >> Ansur;
        if (Ansur == 'Y' || Ansur == 'y')
        {

            if (Client2.Dlate())
            {
                cout << "\nyse thim Dalat\n";
                _PrintClient(Client2);
            }
            else
            {
                cout << "No Data";
            }
        }
    }
};
