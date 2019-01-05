#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <string>
#include <mysql.h>
#include <cstdlib>
typedef char* dbStr;


enum SelectedOption {
    NoOption,
    Visits,
    Doctors,
    Patients,
    Specializations,
    Reports,
    Logout,
    Exit,
    Login
};


#endif // PCH_H
