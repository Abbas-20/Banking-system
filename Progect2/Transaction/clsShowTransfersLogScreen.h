#pragma once
#include <iostream>
#include <iomanip>
#include "..//ManagUsres//clsUser.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Screen Ul//ClsMainScren.h"
#include "..//Opation Client//clsBankClient.h"

class clsTransfersLogScreen:protected ClsScreen
{
private:
      static void _PrintTransferLog(clsBankClient::stTransfersLog StTransferLog)
    {
        cout << "| " << left << setw(25) << StTransferLog.DataTime;
        cout << "| " << left << setw(15) << StTransferLog.S_AccountNumber;
        cout << "| " << left << setw(15) <<StTransferLog.D_AccountNumber;
        cout << "| " << left << setw(12) << StTransferLog.Amount;
        cout << "| " << left << setw(15) << StTransferLog.S_AccountBalance;
        cout << "| " << left << setw(15) <<StTransferLog.D_AccountBalance;
        cout << "| " << left << setw(12) << StTransferLog.UserName;
        cout << "  ||\n";
    }
public:
    static void ShowTransfersLogScreen()
    {
     
        vector<clsBankClient::stTransfersLog> vTransferLog =clsBankClient::GetTransferLogList();
        string Title = "\t\t\tShow Transfer List Screen (S)";
        string SupTitle = "\t\t\t(" + to_string(vTransferLog.size()) + ") Register (S)";
        _DrwScreenHeader(Title, SupTitle);

        cout << "===============================================================================================================================\n";
        cout << "| " << left << setw(25) << "Data Time";                                 
        cout << "| " << left << setw(15) << "S.Account";
        cout << "| " << left << setw(15) << "D.Account";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "S.Balancse";
        cout << "| " << left << setw(15) << "D.Balancse";
        cout << "| " << left << setw(12) << "User Name";
        cout << "  ||\n";
        cout << "===============================================================================================================================\n";

        if (vTransferLog.empty())
        {
            cout << "\t\t \tNo Transfer Available In the System!" << endl;
        }
        else
        {
            for (clsBankClient::stTransfersLog &v : vTransferLog)
            {
                _PrintTransferLog(v);
            }
        }
        cout << "===============================================================================================================================\n";
    }

};


