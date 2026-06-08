
#pragma once
#include <iostream>
#include <iomanip>
#include "..//Progect 2//clsUtil.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Opation Client//clsBankClient.h"

using namespace std;

class clsTotalBalances:protected ClsScreen
{
private:
    static void _PrintClientRcordBalance(clsBankClient vclient)
    {
        cout << "| " << left << setw(15) << vclient.FullName();
        cout << "| " << left << setw(15) << vclient.getAccountNumber();
        cout << "| " << left << setw(10) << vclient.getAccountBalance();
        cout << "  ||\n";
    }

public:
    //! حساب مجموع الكلي الرصيد

    static void ShowTotalBalance()
    {

        vector<clsBankClient> vClient = clsBankClient::GetPrintClientList();
        string Title="\t\t\tBalance Client screen";
        string SubTitle="\t\t\tClient ( "+to_string (vClient.size())+" ) ";
        _DrwScreenHeader(Title,SubTitle);
       
        cout << "==================================================\n";
        cout << "| " << left << setw(15) << "Name";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(10) << "Balance";
        cout << "  ||\n";
        cout << "==================================================\n";

        double TotalBalance = 0.0;
        TotalBalance=clsBankClient::GetTotalBalances();

        if (vClient.empty())
        {
            cout << "\nNo Clients Available In the System!" << endl;
        }
        else
        {
            for (clsBankClient &v : vClient)
            {
                _PrintClientRcordBalance(v);
            }
        }
        cout << "==================================================\n";
        cout << "\n\tTotale Balances: " << TotalBalance;

      cout << "\n \t( " << clsUtil::NumberToText(TotalBalance)<<" )";
    }
};
