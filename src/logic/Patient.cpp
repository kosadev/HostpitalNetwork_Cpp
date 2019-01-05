#include "Patient.h"


Patient::Patient(int id, std::string name, std::string surname) :
    _id(id),
    _name(name),
    _surname(surname)
{
}

void Patient::showPatient(int id, DbConnector &db) {
    std::string query = "SELECT * FROM Patient WHERE Patient_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;
        std::cout << "\tID: " << row[0] << ", Name & Surname: " << row[1] << row[2] std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't patient with " << id << " ID" << std::endl;
    }
}

void Patient::showAllPatients(DbConnector &db)
{
    std::string query = "SELECT * FROM Patient";
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;
        std::cout << "\tID: " << row[0] << ", Name & Surname: " << row[1] << row[2] std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tAny patient" << std::endl;
    }
}

int Patient::countRecords(DbConnector &db)
{
    return db.countRecords("Patient");
}

ModificationResult Patient::deletePatient(int id, DbConnector &db)
{
    Patient tmpPatient=getPatient(id, db);




    if (exists(id, db)) {
        std::string query = "DELETE FROM Patient WHERE Patient_ID=" + std::to_string(id);
        db.executeQuery(query);
        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}

ModificationResult Patient::addPatient(std::string name, std::string surname, DbConnector &db)
{
    std::string query = "INSERT INTO Patient(Name, Surname) Values(\'" + name + "\', \'" + surname + "\')";
    db.executeQuery(query);
    if (db.getQueryState() == DbConnector::QueryState::Successed) {
        return ModificationResult::Successed;
    }
    return ModificationResult::Failed;
}

ModificationResult Patient::editPatient(int id, std::string name, std::string surname, DbConnector &db) {
    Patient tmpPatient = getPatient(id, db);

    if (exists(id, db)) {

        if (!name.compare("")) {
            name = tmpPatient._name;
        }

        if (!surname.compare("")) {
            surname = tmpPatient._surname;
        }

        std::string query = "UPDATE Patient SET Name='" + name + "', Surname='"+ surname +"' WHERE Specialization_ID=" + std::to_string(id);
        db.executeQuery(query);
        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}

Patient Patient::getPatient(int id, DbConnector &db)
{
    std::string query = "SELECT * FROM Patient WHERE Patient_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return Patient(atoi(row[0]), row[1], row[2]);
    }
    return Patient(-1, "", "");
}

bool Patient::exists(int id, DbConnector &db)
{
    std::string query = "SELECT * FROM Patient WHERE Patient_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return true;
    }
    return false;
}

std::string Patient::getName() const
{
    return _name;
}

std::string Patient::getSurname() const
{
    return _surname;
}
