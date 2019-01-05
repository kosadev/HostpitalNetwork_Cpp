#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H


#pragma once
#include "pch.h"
#include "DbConnector.h"
#include "Doctor.h"

class Specialization
{
public:

    Specialization(std::string name="");
    ~Specialization();

    static void showSpecialization(int id, DbConnector &db);
    static void showAllSpecializations(DbConnector &db);
    static int countRecords(DbConnector &db);

    static ModificationResult deleteSpecialization(int id, DbConnector &db);
    static ModificationResult addSpecialization(std::string name, DbConnector db);
    static ModificationResult editSpecialization(int id, std::string name, DbConnector db);

    int getId() const;
    std::string getName() const;

    static Specialization getSpecialization(int id, DbConnector &db);
    static Specialization getSpecialization(std::string name, DbConnector &db);



private:
    int _id = -1;
    std::string _name;

    Specialization(int id, std::string name);//to create instance from result

};


#endif // SPECIALIZATION_H
