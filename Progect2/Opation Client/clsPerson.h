#pragma once
#include <iostream>
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _ListName;
    string _Email;
    string _Phone;

public:
  clsPerson( string FirstName,string ListName,string Email,string Phone){
     _FirstName=FirstName;
     _ListName=ListName;
     _Email=Email;
     _Phone=Phone;
  }
    //Property Get
    string setFirstName(string FirstName)
    {
        _FirstName=FirstName;
    }
   //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    //Property Set
    void SetLastName(string LastName)
    {
        _ListName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _ListName;
    }

    //  string FullName(){
    //      return _FirstName+" "+_ListName;      
    // }
    //Property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string GetEmail()
    {
        return _Email;
    }

    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _ListName;
    }
};