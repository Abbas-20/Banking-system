#pragma once
#include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include "clsPerson.h"
#include "..//Progect 2//clsString.h"
#include "..//Progect 2//clsInputValidate.h"
#include "clsBankclient.h"
#include "..//Screen Ul//ClsScreen.h"
using namespace std;

class clsUpdatClientScreen : protected ClsScreen
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
    // //! تعديل علي عضو
    static void UpdateClient()
    {
         if(!ChackAccessRigth(clsUser::enPermissions::pUpdateClients)){
            return;
        }
        string AccountNumber = "";
        _DrwScreenHeader("\t\t\tUpdat Client");
        cout << "Please enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!(clsBankClient::IsClientExsit(AccountNumber)))
        {
            cout << "\nAccount nubar is not found choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client info";
        cout << "\n---------------------\n";

        //! اذا  تغير غلى قسم واحد
        // Client1.setFirstName("Ali");
        // Client1.Save();

        _ReadClientINfo(Client1);

        clsBankClient::enSaveReuslts SaveReuslt;

        SaveReuslt = Client1.Save();

        switch (SaveReuslt)
        {

        case clsBankClient::enSaveReuslts::svSucceeded:
            cout << "\nAccunt Update Successfully :-)\n";
            _PrintClient(Client1);
            break;
        case clsBankClient::enSaveReuslts::esFaildEmptyObject:
            cout << "\nError Account was not save because it is Empty\n";
            break;
        }
    }
};
