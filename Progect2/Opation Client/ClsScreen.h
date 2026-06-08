#pragma once
#include <iostream>
using namespace std;

class ClsScreen
{

protected:
    static void _DrwScreenHeader(string Title,string SupTitle="")
    {
        cout << "\t\t\t\t\t_________________________________";
        cout << "\n\n\t\t\t" << Title;
        if(SupTitle !=""){
         cout << "\n\t\t\t" << SupTitle;
        }
        cout << "\n\t\t\t\t\t_________________________________\n";
    }
};
