#include "Employee.h"

Employee::Employee() :
    _id(-1),
    _login(""),
    _password("")
{

}

Employee::Employee(int id, std::string login, std::string password) :
    _id(id),
    _login(login),
    _password(password)
{
}


Employee::~Employee()
{
}

Employee Employee::login(std::string login, std::string password, DbConnector &db) {
    std::string query = "SELECT * FROM Employee WHERE Login='" + login +"' AND Password='" + password +"'";
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return Employee(atoi(row[0]), row[1], row[2]);
    }
    return Employee(-1, "", "");
}

Employee Employee::logout() {

    this->_id = -1;
    this->_login = "";
    this->_password = "";
    return Employee(-1, "", "");
}

int Employee::getId() {
    return _id;
}

std::string Employee::getLogin() {
    return _login;
}

Employee Employee::getEmployee(int id, DbConnector &db) {
    std::string query = "SELECT * FROM Employee WHERE Employee_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return Employee(atoi(row[0]), row[1], row[2]);
    }
    return Employee(-1, "", "");
}
