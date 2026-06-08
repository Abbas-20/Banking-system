#pragma once
#include <iostream>
//#include <vector>
//#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Progect 2//clsInputValidate.h"

class clsAddnewClientScreen : protected ClsScreen
{
private:
    static void _ReadClientINfo(clsBankClient &Client1)
    {
        cout << "Ernter First Name: ";
        Client1.setFirstName(clsInputValidate::ReadString());
        cout << "Ernter Last Name: ";
        Client1.SetLastName(clsInputValidate::ReadString());
        cout << "Ernter Email: ";
        Client1.SetEmail(clsInputValidate::ReadString());
        cout << "Ernter Phone: ";
        Client1.SetPhone(clsInputValidate::ReadString());
        cout << "Ernter pin Code: ";
        Client1.SetPinCode(clsInputValidate::ReadString());
        cout << "Ernter Balance: ";
        Client1.setAccountBalance(clsInputValidate::ReadFloNumber());
    }

    static void _PrintClient(clsBankClient Client1)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client1.GetFirstName();
        cout << "\nLastName    : " << Client1.GetLastName();
        cout << "\nFull Name   : " << Client1.FullName();
        cout << "\nEmail       : " << Client1.GetEmail();
        cout << "\nPhone       : " << Client1.GetPhone();
        cout << "\nPin code    : " << Client1.GetPinCode();
        cout << "\nAcc. Number : " << Client1.getAccountNumber();
        cout << "\nBalances     : " << Client1.getAccountBalance();
        cout << "\n___________________\n";
    }

public:
    static void AddNewclient()
    {
          if(!ChackAccessRigth(clsUser::enPermissions::pAddNewClient)){
            return;
        }
        
        _DrwScreenHeader("\t\t\tAdd New Client");

        string _AccountNumber;

        cout << "\nEnter is Account nubar: ";
        _AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExsit(_AccountNumber))
        {
            cout << "\nAccount nubar is found choose another one: ";
            _AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client2 = clsBankClient::GetAddaNewClientMode(_AccountNumber);

        _ReadClientINfo(Client2);

        clsBankClient::enSaveReuslts SaveReuslt;

        SaveReuslt = Client2.Save();

        switch (SaveReuslt)
        {

        case clsBankClient::enSaveReuslts::svSucceeded:
            _PrintClient(Client2);
            break;

        case clsBankClient::enSaveReuslts::esFaildEmptyObject:
            cout << "\nError Account was not save because it is Empty\n";
            break;

        case clsBankClient::enSaveReuslts::svFileAccountNumberExists:
            cout << "\nError wos not save because it is Account nubar is found\n";
            break;
        }
    }
};
