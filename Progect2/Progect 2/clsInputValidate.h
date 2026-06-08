//? /////////////////////////////////////////////////////////////
//! مكتبه تخص ادخال وعمليات تحقق من الارقام  والارقام التي تقع بين فترات
//? /////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include "clsDate.h"

class clsInputValidate
{

public:
    static bool IsNumberBetween(int Num, int From, int To)
    {
        return (Num <= To && Num >= From) ? true : false;
    }

    static bool IsNumberBetween(short Num, int From, int To)
    {
        return (Num <= To && Num >= From) ? true : false;
    }

    static bool IsNumberBetween(double Num, int From, int To)
    {
        return (Num <= To && Num >= From) ? true : false;
    }

    static bool IsNumberBetween(float Num, int From, int To)
    {
        return (Num <= To && Num >= From) ? true : false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1AfterDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1BeforeDate2(Date, To)))
        {
            return true;
        }

        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1AfterDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1BeforeDate2(Date, From)))
        {
            return true;
        }
        return false;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static float ReadFloNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        float Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static string ReadString()
	{
		string  S1="";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

    static short ReadIntNumberBetueen(int From, int To, string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int number = ReadIntNumber();
        while (!(IsNumberBetween(number, From, To)))
        {
            cout << ErrorMessage;
            number = ReadIntNumber();
        }

        return number;
    }

    static double ReadDblNumberBetueen(int From, int To, string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double number = ReadDblNumber();
        while (!(IsNumberBetween(number, From, To)))
        {
            cout << ErrorMessage;
            number = ReadDblNumber();
        }

        return number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
};