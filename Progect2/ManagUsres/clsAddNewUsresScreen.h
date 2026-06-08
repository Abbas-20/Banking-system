#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "..//Screen Ul//ClsScreen.h"
#include "..//Progect 2//clsInputValidate.h"

class clsAddNewUsresScreen : protected ClsScreen
{
private:
    static void _ReadUsresIonf(clsUser &Usres)
    {
        cout << "Ernter First Name: ";
        Usres.setFirstName(clsInputValidate::ReadString());
        cout << "Ernter Last Name: ";
        Usres.SetLastName(clsInputValidate::ReadString());
        cout << "Ernter Email: ";
        Usres.SetEmail(clsInputValidate::ReadString());
        cout << "Ernter Phone: ";
        Usres.SetPhone(clsInputValidate::ReadString());
        cout << "Ernter Passowrd: ";
        Usres.SetPassword(clsInputValidate::ReadString());
       
        Usres.SetPermissions(_ReadPermissionsToSet());
    }
    static void _PrintUsres(clsUser Usres)
    {
        cout << "\nUsres Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Usres.GetFirstName();
        cout << "\nLastName    : " << Usres.GetLastName();
        cout << "\nFull Name   : " << Usres.FullName();
        cout << "\nEmail       : " << Usres.GetEmail();
        cout << "\nPhone       : " << Usres.GetPhone();
        cout << "\nUsres Name  : " << Usres.GetUserName();
        cout << "\nPassowrd    : " << Usres.GetPassword();
        cout << "\nPermissions : " << Usres.GetPermissions();
        cout << "\n___________________\n";
    }

     static int _ReadPermissionsToSet()
    {

        
        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nShow Login Register ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLoginRegister;
        }

        return Permissions;
    }

public:
    static void AddNewUsres()
    {
      
        _DrwScreenHeader("\t\t\tAdd New Usres");

        string UsresName;

        cout << "\nEnter is Usres Name nubar: ";
        UsresName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UsresName))
        {
            cout << "\nUsres nubar is found choose another one: ";
            UsresName = clsInputValidate::ReadString();
        }

        clsUser Usres = clsUser::GetAddNewUserObject(UsresName);

        _ReadUsresIonf(Usres);

        clsUser::enSaveResults SaveReuslt;

        SaveReuslt = Usres.Save();

        switch (SaveReuslt)
        {

        case clsUser::enSaveResults::svSucceeded:
            _PrintUsres(Usres);
            break;

        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\nError Opgect Usres was not save because it is Empty\n";
            break;

        case clsUser::enSaveResults::svFaildUserExists:
            cout << "\nError wos not save because it is Usres Name nubar is found\n";
            break;
        }
    }
};