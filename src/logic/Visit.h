#ifndef VISIT_H
#define VISIT_H

#pragma once
#include "pch.h"
#include "DbConnector.h"
#include "Employee.h"
#include "Doctor.h"
#include "ContractDoctor.h"
#include "FullTimeDoctor.h"
#include "Patient.h"
//#include "Bra


class Visit
{
public:

    enum VisitState {
        Booked,
        Realized,
        Unrealized,
    };

    Visit(int id, time_t visitDateTime, Doctor doctor, Patient patient, VisitState visitState, std::string description);

    static void showVisit(int id, DbConnector &db);
    static void showAllVisits(DbConnector &db);
    static void showAllVisitsByState(VisitState visitState,DbConnector &db);
    static void showAllVisitsByPatient(Patient &patient, DbConnector &db);
    static void showAllVisitsByDoctor(Doctor &doctor, DbConnector &db);

    static int countRecordsByPatient(Patient &patient, DbConnector &db);
    static int countRecordsByDoctor(Doctor &doctor, DbConnector &db);
    static int countRecords(DbConnector &db);


    static Visit getVisit(int id, DbConnector &db);
    static ModificationResult editVisitState(int id, VisitState visitState, DbConnector &db);

    time_t getVisitDateTime() const;

    int getId() const;

    Doctor getDoctor() const;

    Patient getPatient() const;

    VisitState getVisitState() const;

    std::string getDescription() const;

private:
    int _id = -1;
    time_t _visitDateTime;
    Doctor _doctor;
    Patient _patient;
    VisitState _visitState;
    std::string _description = "";

};

#endif // VISIT_H
