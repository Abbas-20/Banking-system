#pragma once
#include <iostream>
#include <iomanip>
#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Opation Client//clsBankClient.h"
class clsDeposit : protected ClsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
    static void Deposit()
    {

        _DrwScreenHeader("\t\t\t Deposit Balances");

        cout << "Enter is Account Number? ";
        string AccountNumber = _ReadAccountNumber();

        while (!(clsBankClient::IsClientExsit(AccountNumber)))
        {
            cout << "\nAccount nubar is not found choose another one: ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Please enter Deposit Amount? ";
        double Amount = clsInputValidate::ReadDblNumber();

        char Choees;
        cout << "\n\nAre you usr yoe want to perform this transaction? ";
        cin >> Choees;
        if (Choees == 'y' || Choees == 'Y')
        {
            Client1.Deposit(Amount);
            cout << "\n\nNew Balanace: " << Client1.getAccountBalance();
        }
        else
        {
            cout << "\nOpration was canclled\n ";
        }
    }
};
