#include "pch.h"
#include "Doctor.h"


Doctor::Doctor(int id, std::string name, std::string surname, double salary, DoctorType type, Specialization specialization) :
    _id(id),
    _name(name),
    _surname(surname),
    _salary(salary),
    _type(type),
    _specialization(specialization)
{
}

void Doctor::showDoctorsBySpecialization(Specialization specialization, DbConnector &db) {
    MYSQL_ROW row;
    MYSQL_RES *res = getDoctorsBySpecialization(specialization, db);
    int resultsAmount = 0;
    while (row = mysql_fetch_row(res))
    {
        resultsAmount++;
        std::cout <<
            "\tID: " << row[0] <<
            ", Name and surname: " << row[1] << row[2] <<
            ", Specialization: " << specialization.getName() <<
            ", Type: ";

        (row[4] == 1 ) ? std::cout << "Full time\n" : std::cout << "Contract\n";
    }

    if (resultsAmount == 0) {
        std::cout << "\tAny doctors with " << specialization.getName() << " specialization" << std::endl;
    }
}

void Doctor::showDoctorsBySurname(std::string surname, DbConnector &db) {
    MYSQL_ROW row;
    MYSQL_RES *res = getDoctorsBySurname(surname, db);
    int resultsAmount = 0;
    while (row = mysql_fetch_row(res))
    {
        resultsAmount++;
        Specialization tmpSpec = Specialization::getSpecialization(atoi(row[5]), db);
        std::cout <<
            "\tID: " << row[0] <<
            ", Name and surname: " << row[1] << row[2] <<
            ", Specialization: " << tmpSpec.getName() <<
            ", Type: ";
        (row[4] == 1 ) ? std::cout << "Full time\n" : std::cout << "Contract\n";
    }

    if (resultsAmount == 0) {
        std::cout << "\tAny doctors with " << surname << " surname" << std::endl;
    }
}

void Doctor::showAllDoctors(DbConnector &db) {
    MYSQL_ROW row;
    MYSQL_RES *res = getAllDoctors(db);
    int resultsAmount = 0;
    while (row = mysql_fetch_row(res))
    {
        resultsAmount++;
        Specialization tmpSpec = Specialization::getSpecialization(atoi(row[5]), db);
        std::cout <<
            "\tID: " << row[0] <<
            ", Name and surname: " << row[1] << row[2] <<
            ", Specialization: " << tmpSpec.getName() <<
            ", Type: ";
        (row[4] == 1 ) ? std::cout << "Full time\n" : std::cout << "Contract\n";
    }

    if (resultsAmount == 0) {
        std::cout << "\tAny doctors" << std::endl;
    }
}



int Doctor::countRecords(DbConnector &db) {
    return db.countRecords("Doctor");
}

ModificationResult Doctor::deleteDoctor(int id, DbConnector &db) {

    if (exists(id, db)) {
        std::string query = "DELETE FROM Doctor WHERE Doctor_ID=" + std::to_string(id);
        db.executeQuery(query);

        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}

ModificationResult Doctor::addDoctor(std::string name, std::string surname, double salary, DoctorType type, Specialization specialization, DbConnector &db) {


    if ( Specialization::getSpecialization(specialization.getId(), db).getId() != -1 ) {
        std::string query = "INSERT INTO Doctor(Name, Surname, Salary, Type, Specialization) Values(\'"
            + name + "\',\'"
            + surname + "\',"
            + std::to_string(salary) + ","
            + std::to_string((int)type) + ","
            + std::to_string(specialization.getId()) + ")";


        db.executeQuery(query);
        if (db.getQueryState() == DbConnector::QueryState::Successed) {
            return ModificationResult::Successed;
        }
    }

    return ModificationResult::Failed;
}

ModificationResult Doctor::editDoctor(int id, std::string name, std::string surname, double salary, DoctorType type, Specialization specialization,  DbConnector &db) {
    std::string query = "SELECT * FROM Doctor WHERE Doctor_ID=" + std::to_string(id);


    //użyj tego w klasach potomnych

//    Doctor tmpDoctor = ;

//    MYSQL_ROW row;
//    MYSQL_RES *res = db.executeQuery(query);
//    if (row = mysql_fetch_row(res))
//    {
//        return true;
//    }

//    if (!name.compare("")) {
//        name = tmpDoctor._title;
//    }
//    if (!kind.compare("")) {
//        kind = tmpDoctor._kind;
//    }
//    if (salary < 0) {
//        salary = tmpDoctor._quantity;
//    }

    if (Specialization::getSpecialization(specialization.getId(), db).getId() != -1 && exists(id, db)) {



        std::string query = "UPDATE Doctor SET Name='" + name + "', Surname='" + surname +
                "', Salary=" + std::to_string(salary) +
                "', Type=" + std::to_string((int)type) +
                "', Specialization=" + std::to_string(specialization.getId()) +
                " WHERE Doctor_ID=" + std::to_string(id);

        db.executeQuery(query);
        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}


MYSQL_RES* Doctor::getDoctorsBySpecialization(Specialization specialization, DbConnector &db) {
    std::string query = "SELECT * FROM Doctor WHERE Specialization=" + std::to_string(specialization.getId());
    return db.executeQuery(query);
}

MYSQL_RES* Doctor::getDoctorsByTitle(std::string surname, DbConnector &db) {
    std::string query = "SELECT * FROM Doctor WHERE Surname=\'" + surname+"\'";
    return db.executeQuery(query);
}

MYSQL_RES* Doctor::getAllDoctors(DbConnector &db) {
    std::string query = "SELECT * FROM Doctor";
    return db.executeQuery(query);
}

int Doctor::getId() const
{
    return _id;
}

std::string Doctor::getName() const
{
    return _name;
}

std::string Doctor::getSurname() const
{
    return _surname;
}

double Doctor::getSalary() const
{
    return _salary;
}

Doctor::DoctorType Doctor::getType() const
{
    return _type;
}

Specialization Doctor::getSpecialization() const
{
    return _specialization;
}

bool Doctor::exists(int id, DbConnector &db) {
    std::string query = "SELECT * FROM Doctor WHERE Doctor_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return true;
    }
    return false;
}
