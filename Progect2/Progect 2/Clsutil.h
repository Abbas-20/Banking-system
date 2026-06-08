#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {

        case SamallLetter:
            return RandomNumber(97, 122);

        case CapitalLetter:
            return RandomNumber(65, 90);

        case Digit:
            return RandomNumber(48, 57);

        case SpecialCharacter:
            return RandomNumber(33, 47);

        defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string word = "";

        for (int i = 0; i < Length; i++)
        {
            word = word + GetRandomCharacter(CharType);
        }
        return word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";
        Key = GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }
    static void GenerateKeys(short Count, enCharType CharType = CapitalLetter)
    {
        for (int i = 0; i < Count; i++)
        {
            cout << "\n[" << i << "]" << GenerateKey(CharType);
        }
    }

    static void Swap(int &A, int &B)
    {
        int Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double &A, double &B)
    {
        double Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string &A, string &B)
    {
        string Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(char &A, char &B)
    {
        char Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool &A, bool &B)
    {
        bool Temp = A;
        A = B;
        B = Temp;
    }

    static string NumberToText(int num)
    {

        if (num == 0)
        {
            return "";
        }
        if (num >= 1 && num <= 19)
        {
            string arr[] = {"", "One", "Two",
                            "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Eleven", "Twelve",
                            "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                            "Seventeen", "Nineteen"};
            return arr[num];
        }
        if (num >= 20 && num <= 99)
        {
            string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                            "Sixty", "Seventy", "Eighty", "Ninety"};
            return arr[num / 10] + " " + NumberToText(num % 10);
        }
        if (num >= 100 && num <= 199)
        {
            return " One Hundred " + NumberToText(num % 100);
        }
        if (num >= 200 && num <= 999)
        {
            return NumberToText(num / 100) + " " + " Hundred " + " " + NumberToText(num % 100);
        }
        if (num >= 1000 && num <= 1999)
        {
            return " One Thousand " + NumberToText(num % 1000);
        }
        if (num >= 2000 && num <= 999999)
        {
            return NumberToText(num / 1000) + " Thousands " + NumberToText(num % 1000);
        }
    }
    static void Swap(clsDate &A, clsDate &B)
    {
        clsDate::SwapDates(A, B);
    }
    static void ShufflArray(int arrae[100], int ArraLangth)
    {

        for (int i = 0; i < ArraLangth; i++)
        {
            Swap(arrae[(RandomNumber(1, ArraLangth)) - 1], arrae[(RandomNumber(1, ArraLangth)) - 1]);
        }
    }

    static void ShufflArray(string arrae[100], int ArraLangth)
    {

        for (int i = 0; i < ArraLangth; i++)
        {
            Swap(arrae[(RandomNumber(1, ArraLangth)) - 1], arrae[(RandomNumber(1, ArraLangth)) - 1]);
        }
    }
    static void FallArraWithRandomNumbers(int Arra[100], int ArraLangth, int From, int To)
    {
        for (int i = 0; i < ArraLangth; i++)
        {
            Arra[i] = RandomNumber(From, To);
        }
    }
    static void FallArraWithRandomWords(string Arra[100], int ArraLangth, enCharType CharType, int WordLength)
    {
        for (int i = 0; i < ArraLangth; i++)
        {
            Arra[i] = GenerateWord(CharType, WordLength);
        }
    }
    static void FallArraWithRandomKeys(string Arra[100], int ArraLangth, enCharType CharType)
    {
        for (int i = 0; i < ArraLangth; i++)
        {
            Arra[i] = GenerateKey(CharType);
        }
    }

    static string Taps(int NumberOfTabs)
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
        }
        return t;
    }

    static string EncryptText(string Text, int EncryptKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(int(Text[i]) + EncryptKey);
        }
        return Text;
    }
    static string DecryptText(string Text, int DecryptText)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(int(Text[i]) - DecryptText);
        }
        return Text;
    }

    
    static string  EncryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }
};