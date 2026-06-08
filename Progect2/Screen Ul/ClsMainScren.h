//#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <iomanip>
#include "..//Opation Client//clsBankClient.h"
#include "..//Progect 2//clsInputValidate.h"
#include "ClsScreen.h"


#include "..//Opation Client//clsClientListScreen.h"
#include "..//Opation Client//clsAddnewClientScreen.h"
#include "..//Opation Client//clsUpdatClientScreen.h"
#include "..//Opation Client//clsDalatClient.h"
#include "..//Opation Client//clsFindClient.h"

#include "..//Transaction//clsMainMenueTransactions.h"
#include "..//ManagUsres//clsManagUsersMenu.h"

#include "..//Login//Global.h"
#include "..//ManagUsres//clsUser.h"

#include "..//Login//clsLoginRegisterListScreen.h"
#include "..//Currency//clsCurrencyExchangeMainScreen.h"

using namespace std;

class ClsMainScren : protected ClsScreen
{
private:
    enum _eMainMenueOptaion
    {
        eShowScreen = 1,
        eAddCLient = 2,
        eDalatClient = 3,
        eUpdateClient = 4,
        eFiendClient = 5,
        Transactions = 6,
        eManageusers = 7,
        enLoginRegister=8,
        eCurrency=9,
        eLogout = 10
       
        
    };

    static void GoBackToMainMenue()
    {
        cout << "\n\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowMainMenue();
    }

    //! داله ادخال رقم الامر
    static short _ReadMainMenueOptaion()
    {
        cout << setw(37) << left << "" << "Choose what do you wan [1,10]: ";
        short Choose = clsInputValidate::ReadIntNumberBetueen(1, 10, "Eter Choose Number [1,8]: ");
        return Choose;
    }

    //! طباعه كل المستخدمين
    static void _ShowAllClintScreen()
    {
       clsClientListScreen::ShowlClientList();
    }

    //! اضافه عميل جديد
    static void _ShowAddNewClintScreen()
    {
        clsAddnewClientScreen::AddNewclient();
    }

    //! حذف عميل
    static void _ShowDalatClintScreen()
    {
        clsDalatClient::DalatClient();
    }

    //! تعديل علئ عميل
    static void _ShowUpdateClintScreen()
    {
        clsUpdatClientScreen::UpdateClient();
    }

    //! ايجاد عميل
    static void _ShowFindClintScreen()
    {
        clsFindClient::ShowFindClient();
    }

    //! قائمه عمليات الفلوس
    static void _ShowTransactions()
    {
       clsMainMenueTransactions::ShowMainMenueTransactions();
    }

    //! قائمه عمليات اليوزر
    static void _ShoweManageUsers()
    {
        clsManagUsersMenu::ShowMainMenueUsres();
    }

     //! قائمه تسجيلات الدخول
    static void _ShowLogoutRegister()
    {
       clsLoginRegisterListScreen::ShowlLoginRegisterRecord();
    }

    //! عمليات النقود
    static void _ShowCurrency()
    {
       clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }
    //! قائمه تسجيل الدخول
    static void _ShowLogoutScreen()
    {
       CurrentUsre=clsUser::Find("","");
    }

    //! داله تنفيذ معالجه الاوامر
    static void _perfromMainMenueOptaion(_eMainMenueOptaion MainMenueOption)
    {
        system("cls");
        switch (MainMenueOption)
        {
        case  eShowScreen:
            _ShowAllClintScreen();
            GoBackToMainMenue();
            break;
        case eAddCLient:
            _ShowAddNewClintScreen();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eDalatClient:
            _ShowDalatClintScreen();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eUpdateClient:
            _ShowUpdateClintScreen();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eFiendClient:
            _ShowFindClintScreen();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::Transactions:
            _ShowTransactions();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eManageusers:
             _ShoweManageUsers();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eCurrency:
            _ShowCurrency();
            GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::enLoginRegister:
            _ShowLogoutRegister();
             GoBackToMainMenue();
            break;
        case _eMainMenueOptaion::eLogout:
            _ShowLogoutScreen();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrwScreenHeader("\t\t\tMian Screen");
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t\t   Mane Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Secrren Client \n";
        cout << setw(37) << left << "" << "\t[2] Add New Client\n";
        cout << setw(37) << left << "" << "\t[3] Dalat Client\n";
        cout << setw(37) << left << "" << "\t[4] Updat Client Info\n";
        cout << setw(37) << left << "" << "\t[5] Find Client\n";
        cout << setw(37) << left << "" << "\t[6] Transactions\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users\n";
        cout << setw(37) << left << "" << "\t[8] Show Logout Register\n";
        cout << setw(37) << left << "" << "\t[9] Currency\n";
        cout << setw(37) << left << "" << "\t[10] Logout\n";
        cout << setw(37) << left << "" << "==========================================\n";

        _perfromMainMenueOptaion((_eMainMenueOptaion)_ReadMainMenueOptaion());
    }

};