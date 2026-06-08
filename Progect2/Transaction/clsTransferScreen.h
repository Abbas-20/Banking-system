#pragma once
#include <iostream>
#include <iomanip>
#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Opation Client//clsBankClient.h"
#include "..//Login//Global.h"
class clsTransferScreen : protected ClsScreen{

    private:
      static void _PrintClient(clsBankClient Client1)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name     : " << Client1.FullName();
        cout << "\nAccount Number: " << Client1.getAccountNumber();
        cout << "\nBalances      : " << Client1.getAccountBalance();
        cout << "\n___________________\n";
    }

  static string _ReadAccountNumber(){
        string AccountNumber = "";
        cout << "\nPlease Enter Account nubar To Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!(clsBankClient::IsClientExsit(AccountNumber)))
        {
            cout << "\nAccount nubar is not found choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
  }

    static float _ReadAmount(clsBankClient SourceClient){
         cout << "Please enter Transfer Amount? ";
        double Amount = clsInputValidate::ReadDblNumber();
        while(Amount>SourceClient.getAccountBalance()){ 
            cout << "Please enter Transfer Amount? ";
            double Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }
    public:

    static void ShowTransferScreen(){

        _DrwScreenHeader("\t\t\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);

        clsBankClient DestrinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestrinationClient);
         
        float Amount=_ReadAmount(SourceClient);
        char Choees;
        cout << "\n\nAre you usr yoe want to perform this transaction? ";
        cin >> Choees;

        if (Choees == 'y' || Choees == 'Y')
        {
            if(SourceClient.Transfer(Amount,DestrinationClient,CurrentUsre.GetUserName())){
                    cout<<"\nTransfer don successfully\n";
            }
        }
        else
        {
            cout << "\nOpration was canclled\n ";
        }

        _PrintClient(SourceClient);
        _PrintClient(DestrinationClient);
        //clsBankClient::_AddDataLineToFile(Amount,SourceClient,DestrinationClient);
    }

};