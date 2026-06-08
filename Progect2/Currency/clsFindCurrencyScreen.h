#pragma once

#include<iostream>
#include<string>
#include <vector>
#include "..//Progect 2//clsInputValidate.h"
#include "..//Screen Ul//ClsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen:public ClsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

   static void _ShowResults(clsCurrency currency ){
    if(!currency.IsEmpty()){
        cout << "\nCurrency Found :-)\n";
        _PrintCurrency(currency);
    }else{
        cout << "\nCurrency Was not Found :-(\n";
    }
   }
 

public:


    static void ShowFindCurrencScreen()
    {
        string Title = "\t\t\tCurrencies List Screen";
        string SubTitle = "\t\t\t Currency.";

        _DrwScreenHeader(Title, SubTitle);

        short Answer=1;  
        cout << "\nFind By: [1] Code or [2] Country ? ";
        cin>>Answer;
        if(Answer==1){
            cout << "\nPlease Enter Currency Code: ";
            string CurrencyCode=clsInputValidate::ReadString();
            clsCurrency Currency=clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else{
            cout << "\nPlease Enter Currency Nmae: ";
            string CurrencyCode=clsInputValidate::ReadString();
            clsCurrency Currency=clsCurrency::FindByCountry(CurrencyCode);
            _ShowResults(Currency);
            
        }
        

      

    }

};
