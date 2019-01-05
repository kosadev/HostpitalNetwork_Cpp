#ifndef DOCTOR_H
#define DOCTOR_H


#pragma once
#include "pch.h"
#include "DbConnector.h"
#include "Specialization.h"

class Doctor
{
public:

    enum DoctorType {
        NoType,
        FullTimeDoctor,
        ContractDoctor
    };

    Doctor(int id, std::string name, std::string surname, double salary, DoctorType type, Specialization specialization);

    virtual ~Doctor() {}

    static void showDoctorsBySpecialization(Specialization specialization, DbConnector &db);
    static void showDoctorsBySurname(std::string surname, DbConnector &db);
    static void showAllDoctors(DbConnector &db);

    static int countRecords(DbConnector &db);

    static ModificationResult deleteDoctor(int id, DbConnector &db);
    static ModificationResult addDoctor(std::string name, std::string surname, double salary, DoctorType type, Specialization specialization, DbConnector &db);
    static ModificationResult editDoctor(int id, std::string name, std::string surname, double salary, DoctorType type, Specialization specialization,  DbConnector &db);

    static Doctor getDoctor(int id, DbConnector &db);

    static bool exists(int id, DbConnector &db);

    static MYSQL_RES* getDoctorsBySpecialization(Specialization specialization, DbConnector &db);
    static MYSQL_RES* getDoctorsBySurname(std::string surname, DbConnector &db);
    static MYSQL_RES* getAllDoctors(DbConnector &db);

    int getId() const;

    std::string getName() const;

    std::string getSurname() const;

    double getSalary() const;

    DoctorType getType() const;

    Specialization getSpecialization() const;

    virtual bool checkSpecialization(const Specialization &specialization) {

    }

protected:
    int _id = -1;
    std::string _name;
    std::string _surname;
    double _salary;
    DoctorType _type;
    Specialization _specialization;



};



#endif // DOCTOR_H
