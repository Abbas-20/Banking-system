// #pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <iomanip>
#include "..//Opation Client//clsBankClient.h"
#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "clsUser.h"

#include "clsListUsresScreen.h"
#include "clsAddNewUsresScreen.h"
#include"clsDalatUserScreen.h"
#include"clsUdateUsreScreen.h"
#include"clsFindUsreScreen.h"
using namespace std;

class clsManagUsersMenu : protected ClsScreen
{
private:
    enum _eMainManagUserOption
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6
    };

    static void GoBackToMenueUsres()
    {
        cout << "\n\nPress any key to go back to Menue Usres...";
        system("pause>0");
        ShowMainMenueUsres();
    }

    //! داله ادخال رقم الامر
    static short _ReadManagMenueUsres()
    {
        cout << setw(37) << left << "" << "Choose what do you wan [1,6]: ";
        short Choose = clsInputValidate::ReadIntNumberBetueen(1, 6, "Eter Choose Number [1,6]: ");
        return Choose;
    }


    
    //! طباعه كل المستخدمين
    static void _ShowAllUsresScreen()
    {
        clsListUsresScreen::ShowlUsresList();
    }

    //! اضافه مستخدم جديد
    static void _ShowAddNewUsresScreen()
    {
        clsAddNewUsresScreen::AddNewUsres();
    }

    //! حذف مستخدم
    static void _ShowDalatUsresScreen()
    {
      clsDalatUsreScreen::DalatUsre();
    }

    //! تعديل علئ مستخدم
    static void _ShowUpdateUsresScreen()
    {
        clsUpdatUsresScreen::UpdateClient();
    }

    //! ايجاد مستخدم
    static void _ShowFindUsresScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    // //! العوده للقائمه رئيسيه
    // static void _ShowMainMenuScreen()
    // {
    // }
    
    //! داله تنفيذ معالجه الاوامر
    static void _perfromUsresMenueOptaion(_eMainManagUserOption ManagMenueUsresOption)
    {
        system("cls");
        switch (ManagMenueUsresOption)
        {
        case _eMainManagUserOption::eListUsers:
            _ShowAllUsresScreen();
            GoBackToMenueUsres();
            break;
        case _eMainManagUserOption::eAddNewUser:
            _ShowAddNewUsresScreen();
            GoBackToMenueUsres();
            break;
        case _eMainManagUserOption::eDeleteUser:
            _ShowDalatUsresScreen();
            GoBackToMenueUsres();
            break;
        case _eMainManagUserOption::eUpdateUser:
            _ShowUpdateUsresScreen();
            GoBackToMenueUsres();
            break;
        case _eMainManagUserOption::eFindUser:
            _ShowFindUsresScreen();
            GoBackToMenueUsres();
            break;
        case _eMainManagUserOption::eMainMenue:

            //GoBackToMenueUsres();
            break;
        }
    }

public:
    static void ShowMainMenueUsres()
    {
        if(!ChackAccessRigth(clsUser::enPermissions::pManageUsers)){
            return;
        }
        system("cls");
        _DrwScreenHeader("\t\t\tScreen Usres");
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t\t   Manag Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Secrren Usres \n";
        cout << setw(37) << left << "" << "\t[2] Add New Usres\n";
        cout << setw(37) << left << "" << "\t[3] Dalat Usrs\n";
        cout << setw(37) << left << "" << "\t[4] Updat Usres Info\n";
        cout << setw(37) << left << "" << "\t[5] Find Usres\n";
        cout << setw(37) << left << "" << "\t[6] Mane Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";

        _perfromUsresMenueOptaion((_eMainManagUserOption)_ReadManagMenueUsres());
    }

    // static void Maint(){
    //     cout<<"yse";
    // }
};
