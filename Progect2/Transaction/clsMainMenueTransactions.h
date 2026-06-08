//#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <iomanip>
#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Screen Ul//ClsMainScren.h"
#include "..//Opation Client//clsBankClient.h"

#include "clsTotalBalances.h"
#include "clsWithdraw.h"
#include "clsDeposit.h"
#include "clsTransferScreen.h"
#include "clsShowTransfersLogScreen.h"
using namespace std;

class clsMainMenueTransactions : protected ClsScreen 
{
private:
    enum _eMenueTransactionsOption
    {
        eWithdrow=1,
        eDepoist=2,
        eTotalBalance=3,
        eShowTransfer=4,
        eTransfersLog=5,
        eMainMenue=6
    };

    static void GoBackToMenueTransactions()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowMainMenueTransactions();
    }

    //! داله ادخال رقم الامر
    static short _ReadMenueTransactionsOptaion()
    {
        cout << setw(37) << left << "" << "Choose what do you wan [1,6]: ";
        short Choose = clsInputValidate::ReadIntNumberBetueen(1, 6, "Eter Choose Number [1,4]: ");
        return Choose;
    }

//?  /////////////////////////////////////////////
//*  دوال عمليات
//? /////////////////////////////////////////////
    //! سحب مبلغ مالي
    static void _ShowWithdrawScreen()
    {
       clsWithdraw::Withdraw();
    }

    //!  ايداع مبلغ مالي 
    static void _ShowDepoistScreen()
    {
        clsDeposit::Deposit();
    }

    //! حساب الرصيد الكلي
    static void _ShowTotaleBalancesScreen()
    {
        clsTotalBalances::ShowTotalBalance();
    }

    //! تحويل من حساب الى اخر
    static void _ShowTransferScreen()
    {
     clsTransferScreen::ShowTransferScreen();
    }
    //! طباعه سجل عمليات تحويل
    static void _ShowTransfersLogScren()
    {
     clsTransfersLogScreen::ShowTransfersLogScreen();
    }
    //! العوده قائمه اساسيه
    static void ShowMainMenueOption1()
    {
      // ClsMainScren::ShowMainMenue();
    }

   


    //! داله تنفيذ معالجه الاوامر
    static void _perfromMenueTransctionOptaion(_eMenueTransactionsOption MenueTransactionsOption)
    {
        system("cls");
        switch (MenueTransactionsOption)
        {
        case _eMenueTransactionsOption::eWithdrow:
           _ShowWithdrawScreen();
            GoBackToMenueTransactions();
            break;
        case _eMenueTransactionsOption::eDepoist:
           _ShowDepoistScreen();
            GoBackToMenueTransactions();
            break;
        case _eMenueTransactionsOption::eTotalBalance:
            _ShowTotaleBalancesScreen();
            GoBackToMenueTransactions();
            break;
        case _eMenueTransactionsOption::eShowTransfer:
            _ShowTransferScreen();
            GoBackToMenueTransactions();
            break;
        case _eMenueTransactionsOption::eTransfersLog:
            _ShowTransfersLogScren();
            GoBackToMenueTransactions();
            break;
        case _eMenueTransactionsOption::eMainMenue:
            ShowMainMenueOption1();
            break;
        }
    }

public:
    static void ShowMainMenueTransactions()
    {
        if(!ChackAccessRigth(clsUser::enPermissions::pTranactions)){
            return;
        }
         system("cls");
        _DrwScreenHeader("\t\t\tMenue Transactions");
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t\t    Menue Transactions\n";
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t[1] whithdrow\n";
        cout << setw(37) << left << "" << "\t[2] Depoist\n";
        cout << setw(37) << left << "" << "\t[3] Totale Balance\n";
        cout << setw(37) << left << "" << "\t[4] Transfer\n";
        cout << setw(37) << left << "" << "\t[5] Transfers Log\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";

        _perfromMenueTransctionOptaion((_eMenueTransactionsOption)_ReadMenueTransactionsOptaion());
    }


};