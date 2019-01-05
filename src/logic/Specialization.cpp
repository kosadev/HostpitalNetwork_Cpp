#include "Specialization.h"


Specialization::Specialization(std::string name) :
    _name(name)
{
}

Specialization::Specialization(int id, std::string name) :
    _id(id),
    _name(name)
{

}


void Specialization::showSpecialization(int id, DbConnector &db) {
    Specialization tmpSpec = getSpecialization(id, db);

    if (tmpSpec._id != -1) {
        std::cout << "\tID: " << tmpSpec._id << ", Name: " << tmpSpec._name << std::endl;
        return;
    }

    std::cout << "\tNo author at this id " << id << std::endl;
}


void Specialization::showAllSpecializations(DbConnector &db) {
    std::string query = "SELECT * FROM Specialization";
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;
        std::cout << "\tID: " << row[0] << ", Name: " << row[1] << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tAny specializations" << std::endl;
    }
}


int Specialization::countRecords(DbConnector &db) {
    return db.countRecords("Specialization");
}


Specialization Specialization::getSpecialization(int id, DbConnector &db) {
    std::string query = "SELECT * FROM Specialization WHERE Specialization_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if(row = mysql_fetch_row(res))
    {
        return Specialization(atoi(row[0]), row[1]);
    }
    return Specialization(-1, "");
}

Specialization Specialization::getSpecialization(std::string name, DbConnector &db) {
    std::string query = "SELECT * FROM Specialization WHERE Specialization_Name='" + name + "'";
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return Specialization(atoi(row[0]), row[1]);
    }
    return Specialization(-1, "");
}

ModificationResult Specialization::deleteSpecialization(int id, DbConnector &db) {
    Specialization tmpSpec=getSpecialization(id, db);


    int counter = 0;
    MYSQL_RES *res = Doctor::getDoctorsBySpecialization(tmpSpec, db);
    MYSQL_ROW row;
    while (row = mysql_fetch_row(res)) {
        counter++;
    }

    if (counter != 0) {
        return ModificationResult::Failed;
    }

    if (tmpSpec._id != -1) {
        std::string query = "DELETE FROM Specialization WHERE Specialization_ID=" + std::to_string(id);
        db.executeQuery(query);
        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}


ModificationResult Specialization::addSpecialization(std::string name, DbConnector db) {
    std::string query = "INSERT INTO Specialization(Specialization_Name) Values(\'" + name + "\')";
    db.executeQuery(query);
    if (db.getQueryState() == DbConnector::QueryState::Successed) {
        return ModificationResult::Successed;
    }
    return ModificationResult::Failed;
}


ModificationResult Specialization::editSpecialization(int id, std::string name, DbConnector db) {
    Specialization tmpSpec = getSpecialization(id, db);

    if (tmpSpec._id != -1) {

        if (!name.compare("")) {
            name = tmpSpec._name;
        }

        std::string query = "UPDATE Specialization SET Specialization_Name='" + name + "' WHERE Specialization_ID=" + std::to_string(id);
        db.executeQuery(query);
        return ModificationResult::Successed;
    }

    return ModificationResult::Failed;
}


int Specialization::getId() {
    return _id;
}

std::string Specialization::getName() {
    return _name;
}

