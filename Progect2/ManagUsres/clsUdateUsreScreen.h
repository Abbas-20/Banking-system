#pragma once
#include <iostream>
#include "..//Progect 2//clsString.h"
#include "..//Progect 2//clsInputValidate.h"
#include "clsUser.h"
#include "..//Screen Ul//ClsScreen.h"
using namespace std;

class clsUpdatUsresScreen : protected ClsScreen
{
private:
    static void _ReadUsresINfo(clsUser &User)
    {
        cout << "Ernter First Name: ";
        User.setFirstName(clsInputValidate::ReadString());
        cout << "Ernter Last Name: ";
        User.SetLastName(clsInputValidate::ReadString());
        cout << "Ernter Email: ";
        User.SetEmail(clsInputValidate::ReadString());
        cout << "Ernter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());
        cout << "Ernter Passowrd: ";
        User.SetPassword(clsInputValidate::ReadString());
        
        User.SetPermissions(_ReadPermissionsToSet());
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

    static void _PrintUsres(clsUser User)
    {
        cout << "\nUsres Card:";
        cout << "\n___________________";
        cout << "\nFirstName     : " << User.GetFirstName();
        cout << "\nLastName      : " << User.GetLastName();
        cout << "\nFull Name     : " << User.FullName();
        cout << "\nEmail         : " << User.GetEmail();
        cout << "\nPhone         : " << User.GetPhone();
        cout << "\nUsres Name    : " << User.GetUserName();
        cout << "\nPassword      : " << User.GetPassword();
        cout << "\nPermissions   : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    // //! تعديل علي عضو
    static void UpdateClient()
    {
       
        string UsreNmae = "";
        _DrwScreenHeader("\t\t\tUpdat Usre");
        cout << "Please enter  Usres Nmae: ";
        UsreNmae = clsInputValidate::ReadString();
        while (!(clsUser::IsUserExist(UsreNmae)))
        {
            cout << "\nUsre Name nubar is not found choose another one: ";
            UsreNmae = clsInputValidate::ReadString();
        }

        clsUser Usre = clsUser::Find(UsreNmae);
        _PrintUsres(Usre);

        cout << "\n\nUpdate Usre info";
        cout << "\n---------------------\n";

    
        _ReadUsresINfo(Usre);

        clsUser::enSaveResults SaveReuslt;

        SaveReuslt = Usre.Save();

        switch (SaveReuslt)
        {

        case clsUser::enSaveResults::svSucceeded:
            cout << "\nAccunt Update Successfully :-)\n";
            _PrintUsres(Usre);
            break;
        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\nError Usre Name was not save because it is Empty\n";
            break;
        }
    }
};
