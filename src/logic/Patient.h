#ifndef PATIENT_H
#define PATIENT_H


#pragma once
#include "pch.h"
#include "DbConnector.h"

class Patient
{
public:


    Patient(int id, std::string name, std::string surname);

    ~Patient() {}

    static void showPatient(int id, DbConnector &db);
    static void showAllPatients(DbConnector &db);

    static int countRecords(DbConnector &db);

    static ModificationResult deletePatient(int id, DbConnector &db);
    static ModificationResult addPatient(std::string name, std::string surname, DbConnector &db);
    static ModificationResult editPatient(int id, std::string name, std::string surname, DbConnector &db);

    static Patient getPatient(int id, DbConnector &db);

    static bool exists(int id, DbConnector &db);



    std::string getName() const;

    std::string getSurname() const;

private:
    int _id = -1;
    std::string _name;
    std::string _surname;



};


#endif // PATIENT_H
