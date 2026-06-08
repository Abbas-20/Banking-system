#pragma once
#include <iostream>
using namespace std;
#include "..//ManagUsres//clsUser.h"
#include "..//Login//Global.h"
#include "..//Progect 2//clsDate.h"
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
        cout << "\n\t\t\t\t\t_________________________________\n\n";

      cout<<"\n\t\t\t\t\t   User: "<<CurrentUsre.GetUserName();
      cout<<"\n\t\t\t\t\t   Date: "<<clsDate::DateToString(clsDate())<<"\n\n";
      
    }

    static bool ChackAccessRigth(clsUser::enPermissions Permissions){
   
        if(!CurrentUsre.CheckAccessPermissions(Permissions)){
           cout<<"\t\t\t\t----------------------------------------------";
           cout<<"\n\n\t\t\t\t\tAccess Deined,contact your Access";
           cout<<"\n\t\t\t\t----------------------------------------------";
           return false;
        }
        else{
            return true;
        }
    }
};
