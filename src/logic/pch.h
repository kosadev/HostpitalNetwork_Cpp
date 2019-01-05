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

enum ModificationResult {
    Successed,
    Failed
};

#endif // PCH_H
