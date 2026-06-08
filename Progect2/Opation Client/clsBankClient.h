#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "..//Progect 2//clsString.h"
#include "..//Progect 2//clsUtil.h"
#include "..//Login//Global.h"
using namespace std;

class clsBankClient : public clsPerson
{

public:
    struct stTransfersLog{
         string DataTime;
         string S_AccountNumber;
         string D_AccountNumber;
         float Amount;
         float S_AccountBalance;
         float D_AccountBalance;
         string UserName;
    };
private:
    enum eMode
    {
        eEmptyMod = 1,
        eUpdateMod = 2,
        eAddNewMod = 3
    };

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDalat = false;
    eMode _Mode;
    //! تحويل من لاين الى فيكتور
    static clsBankClient _ConvertLineToClientObject(string Line, string Spertor = "#//#")
    {
        vector<string> vClinet = clsString::Split(Line, Spertor);

        return clsBankClient(eMode::eUpdateMod, vClinet[0], vClinet[1], vClinet[2], vClinet[3], vClinet[4], vClinet[5], (stoi(vClinet[6])));
    }

    //! تحويل من اوبجكت الى سترينج
    static string _ConvertClientObjectToLine(clsBankClient _Clinet, string Spertor = "#//#")
    {
        return _Clinet.GetFirstName() + Spertor + _Clinet.GetLastName() + Spertor + _Clinet.GetEmail() + Spertor + _Clinet.GetPhone() + Spertor + _Clinet.getAccountNumber() + Spertor + _Clinet.GetPinCode() + Spertor + to_string(_Clinet.getAccountBalance());
    }

    //! ارجاع اوبجكت فارغ اذا ما لكه شي
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(eMode::eEmptyMod, "", "", "", "", "", "", 0);
    }

    //! قرائه البيانات من ملف وارجاعها في فيكتور من نوع  كلاس
    static vector<clsBankClient> _LoadClientsDataFromFile()
    {

        vector<clsBankClient> _vClient;
        fstream File;
        File.open("D:\\Clients.txt", ios::in);

        if (File.is_open())
        {
            string Line = "";

            while (getline(File, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                _vClient.push_back(Client);
            }

            File.close();
        }
        return _vClient;
    }

    //! تخزين البيانات في الملف
    void _SaveClientsDateToFile(vector<clsBankClient> _vClient)
    {
        fstream MyFile;
        MyFile.open("D:\\Clients.txt", ios::out);

        if (MyFile.is_open())
        {

            string DataLine;
            for (clsBankClient C : _vClient)
            {
                if (C._MarkedForDalat == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    //! تخزين العضو الجديد في الملف
    void _SaveClientsDateToFiles(string NewClient)
    {
        fstream MyFile;
        MyFile.open("D:\\Clients.txt", ios::app);

        if (MyFile.is_open())
        {
            MyFile << "\n"
                   << NewClient;
            MyFile.close();
        }
    }

    //! تبديل البيانات المعدله في الملف
    void _Udate()
    {
        vector<clsBankClient> _vClient = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClient)
        {
            if (C.getAccountNumber() == getAccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDateToFile(_vClient);
    }

    //! اضافه عضو جديد
    void _AddNew()
    {
        _SaveClientsDateToFiles(_ConvertClientObjectToLine(*this));
    }
//! ///////////////////////////////////////////////
//////////////? السجلات ////////////////////////
//! //////////////////////////////////////////////
    string _PrepareTransferLogRecord(float Amount,clsBankClient DestrinationClient,string Username,string Seperator="#//#"){
        string LoginRecord="";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord+=getAccountNumber()+Seperator;
        LoginRecord+=DestrinationClient.getAccountNumber()+Seperator;
        LoginRecord+=to_string(Amount)+Seperator;
        LoginRecord +=to_string(DestrinationClient.getAccountBalance())+ Seperator;
        LoginRecord +=to_string(getAccountBalance())+ Seperator;
        LoginRecord +=Username;
        return LoginRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {

        string stDataLine = _PrepareTransferLogRecord( Amount,  DestinationClient,  UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
//? /////////////////////////////////////////////
////////////!      القرائه         ///////////////
//? /////////////////////////////////////////////
    static stTransfersLog _ConvertLinetoTransfer(string Line,string Seperator = "#//#"){
     vector<string> vTransfer=clsString::Split(Line, Seperator);
     stTransfersLog sTransfer;
     sTransfer.DataTime=vTransfer[0];
     sTransfer.S_AccountNumber=vTransfer[1];
     sTransfer.D_AccountNumber=vTransfer[2];
     sTransfer.Amount=stoi(vTransfer[3]);
     sTransfer.S_AccountBalance=stoi(vTransfer[4]);
     sTransfer.D_AccountBalance=stoi(vTransfer[5]);
     sTransfer.UserName=vTransfer[6];
     return sTransfer;
    }
    static vector<stTransfersLog> _GetTransfertLog()
    {
        vector<stTransfersLog> vTransfer;

        fstream MyFile;
        MyFile.open("D:\\TransferLog.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                stTransfersLog STransfer =_ConvertLinetoTransfer(Line);

                vTransfer.push_back(STransfer);
            }
            MyFile.close();
        }
        return vTransfer;
    }

public:
    //! كونستركيت
    clsBankClient(eMode mode, string FirstName, string ListName, string Email, string Phone, string AccountNumber, string PinCode,
                  float AccountBalance) : clsPerson(FirstName, ListName, Email, Phone)
    {
        _Mode = mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    //! تحقق اذا موجود شخص لو لا
    bool IsEmpty()
    {
        return (_Mode == eMode::eEmptyMod);
    }
    //!  خواص ال  get and set
    string getAccountNumber()
    {
        return _AccountNumber;
    }

    void setAccountBalance(float Balance)
    {
        _AccountBalance = Balance;
    }

    float getAccountBalance()
    {
        return _AccountBalance;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    void Deposit(double Amount)
    {

        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    //! دهاله طباعه البيانات
    // void Print()
    // {
    //     cout << "\nClient Card:";
    //     cout << "\n___________________";
    //     cout << "\nFirstName   : " << GetFirstName();
    //     cout << "\nLastName    : " << GetLastName();
    //     cout << "\nFull Name   : " << FullName();
    //     cout << "\nEmail       : " << GetEmail();
    //     cout << "\nPhone       : " << GetPhone();
    //     cout << "\nAcc. Number : " << _AccountNumber;
    //     cout << "\nPassword    : " << _PinCode;
    //     cout << "\nBalance     : " << _AccountBalance;
    //     cout << "\n___________________\n";
    // }



    //! بحث عن المستخدم في الملف واذا نوجد يتم ارجاعه اوبجيكت
    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClient;

        fstream File;
        File.open("D:\\Clients.txt", ios::in);

        if (File.is_open())
        {
            string Line = "";

            while (getline(File, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client._AccountNumber == AccountNumber)
                {
                    File.close();
                    return Client;
                }
                //   vClient.push_back(Client);
            }

            File.close();
        }

        return _GetEmptyClientObject();
    }
    //! نفس شغل قبلها ولكن استخدام رقم حساب مع بن كود
    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClient;

        fstream File;
        File.open("D:\\Clients.txt", ios::in);

        if (File.is_open())
        {
            string Line = "";

            while (getline(File, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
                {
                    File.close();
                    return Client;
                }
                vClient.push_back(Client);
            }

            File.close();
        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExsit(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return (!(Client.IsEmpty()));
    }

    //! حذف عضو
    bool Dlate()
    {
        vector<clsBankClient> vClient = _LoadClientsDataFromFile();

        for (clsBankClient &C : vClient)
        {
            if (C._AccountNumber == getAccountNumber())
            {
                C._MarkedForDalat = true;
            }
        }
        _SaveClientsDateToFile(vClient);
        *this = _GetEmptyClientObject();
        return true;
    }

    static vector<clsBankClient> GetPrintClientList()
    {
        return _LoadClientsDataFromFile();
    }

    //! حساب مجموع الرصيد الكلي
    static double GetTotalBalances()
    {
        double Total = 0.0;
        vector<clsBankClient> vClient = _LoadClientsDataFromFile();
        for (clsBankClient &C : vClient)
        {
            Total += C.getAccountBalance();
        }
        return Total;
    }

    //! عليمه حفظ بيانات بعد تعديل وتحقق اذا يتم حفظ او لا اذا كان فارغ
    enum enSaveReuslts
    {
        svSucceeded = 0,
        esFaildEmptyObject = 1,
        svFileAccountNumberExists = 2
    };
    enSaveReuslts Save()
    {

        switch (_Mode)
        {

        case eMode::eEmptyMod:
        {
            if (IsEmpty())
            {
                return enSaveReuslts::esFaildEmptyObject;
            }
        }

        case eMode::eUpdateMod:
        {
            _Udate();
            return enSaveReuslts::svSucceeded;
        }

        case eMode::eAddNewMod:
        {
            if (clsBankClient::IsClientExsit(getAccountNumber()))
            {
                return enSaveReuslts::svFileAccountNumberExists;
            }
            else
            {
                _AddNew();
            }
        }
        }
    }

    static clsBankClient GetAddaNewClientMode(string AccountNumber)
    {
        return clsBankClient(eMode::eAddNewMod, "", "", "", "", AccountNumber, "", 0);
    }


    bool Transfer(float Amount,clsBankClient &DestrinationClient,string UserName){
        if(Amount>_AccountBalance){
            return false;
        }
        else{
            Withdraw(Amount);
            DestrinationClient.Deposit(Amount);
            _RegisterTransferLog(Amount,DestrinationClient,UserName);
            return true;
        }
    }

    static vector<stTransfersLog> GetTransferLogList(){
       return _GetTransfertLog();
    }
};