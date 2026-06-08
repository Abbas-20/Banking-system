#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "..//Opation Client//clsPerson.h"
#include "..//Progect 2//clsString.h"
#include "..//Progect 2//clsUtil.h"

using namespace std;

using namespace std;
class clsUser : public clsPerson
{
    public:
    struct stLoginRegisterRecord{
        string DateTime;
        string username;
        string Passowrd;
        int Permissions;
    };
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;


    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                       vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.GetFirstName() + Seperator;
        UserRecord += User.GetLastName() + Seperator;
        UserRecord += User.GetEmail() + Seperator;
        UserRecord += User.GetPhone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += clsUtil::EncryptText(User.GetPassword()) + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;
    }

    static vector<clsUser> _ConvertLinetoVector(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

       // return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
         //              vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
    }
    //! تقره السجل
    static vector<clsUser> _LoadRigestrDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }


    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser &U : _vUsers)
        {
            if (U.GetUserName() == GetUserName())
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareLoginRecord(string Seperator="#//#"){
        string LoginRecord="";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += _UserName+ Seperator;
        LoginRecord += clsUtil::EncryptText(_Password) + Seperator;
        LoginRecord += to_string(_Permissions);

        return LoginRecord;
    }
 ///////////////////////////////////////////////////////////////////
////////////////////? سجلات  ////////////////////
///////////////////////////////////////////////////////////////////
   // struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLinetoRegister(string Line,string Seperator = "#//#"){
     vector<string> vRegster=clsString::Split(Line, Seperator);
     stLoginRegisterRecord stRegster;
     stRegster.DateTime=vRegster[0];
     stRegster.username=vRegster[1];
     stRegster.Passowrd=clsUtil::DecryptText(vRegster[2]);
     stRegster.Permissions=stoi(vRegster[3]);
     return stRegster;
    }
public:
    enum enPermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTranactions = 32,
        pManageUsers = 64,
        pShowLoginRegister=128
    };

    clsUser(enMode Mode, string FirstName, string LastName,
            string Email, string Phone, string UserName, string Password,
            int Permissions) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool CheckAccessPermissions(enPermissions Pemissions)
    {

        if (this->GetPermissions() == enPermissions::eAll)
        {
            return true;
        }

        if ((Pemissions & this->GetPermissions()) == Pemissions)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    void RegisterLogin()
    {
        string FildLogin = _PrepareLoginRecord();

        fstream MyFile;
        MyFile.open("D:\\InfoRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << FildLogin << endl;
            MyFile.close();
        }
    }
    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("D:\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildUserExists = 2
    };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            // This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                // We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser &U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
///////////////////////////////////////////////////////////////////
////////////////////? سجلات  ////////////////////
///////////////////////////////////////////////////////////////////
    // struct stLoginRegisterRecord{
    //     string DateTime;
    //     string username;
    //     string Passowrd;
    //     int Permissions;
    // };


    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vStRegster;

        fstream MyFile;
        MyFile.open("D:\\InfoRegister.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                stLoginRegisterRecord StRegster =_ConvertLinetoRegister(Line);

                vStRegster.push_back(StRegster);
            }
            MyFile.close();
        }
        return vStRegster;
    }
};
