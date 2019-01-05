#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#pragma once
#include "pch.h"
#include "DbConnector.h"


class Employee
{
public:
    Employee();

    Employee(int id, std::string login, std::string password);
    ~Employee();

    static Employee login(std::string login, std::string password, DbConnector &db);
    Employee logout();

    int getId();
    std::string getLogin();

    static Employee getEmployee(int id, DbConnector &db);

private:
    int _id;
    std::string _login;
    std::string _password;
};



#endif // EMPLOYEE_H
