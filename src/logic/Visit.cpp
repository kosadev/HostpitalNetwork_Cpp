#include "Visit.h"


Visit::Visit(int id, time_t visitDateTime, Doctor doctor, Patient patient, Visit::VisitState visitState, std::string description) :
    _id(id),
    _doctor(doctor),
    _patient(patient),
    _visitState(visitState),
    _description(description)
{
}

void Visit::showVisit(int id, DbConnector &db)
{
    std::string query = "SELECT * FROM Visit WHERE Visit_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;

        time_t visitDateTime = atoi(row[1]);
        Patient tmpPatient = Patient::getPatient(atoi(row[3]), db);
        Doctor tmpDoctor = Doctor::getDoctor(atoi(row[2]), db);
        VisitState visitState = (VisitState)atoi(row[4])

        std::cout << "\tID: " << row[0] <<
                     "\n\tVisit date: " << ctime(&visitDateTime) <<
                     "\n\tPatient: " << tmpPatient.getName() << " " << tmpPatient.getSurname() <<
                     "\n\tDoctor: " << tmpDoctor.getName() << " " << tmpDoctor.getSurname();

        std::cout << "\n\tVisit status: ";

        switch (visitState) {
        case Booked:
            std::cout <<  "Booked";
            break;
        case Realized:
            std::cout <<  "Realized";
            break;
        case Unrealized:
            std::cout <<  "Unrealized";
            break;
        }

        if(row[5]!="") {
         std::cout << "\n\tDescription: " << row[5];
        }

        std::cout << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't visit with " << id << " ID" << std::endl;
    }
}

void Visit::showAllVisits(DbConnector &db)
{
    std::string query = "SELECT * FROM Visit";
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;

        time_t visitDateTime = atoi(row[1]);
        Patient tmpPatient = Patient::getPatient(atoi(row[3]), db);
        Doctor tmpDoctor = Doctor::getDoctor(atoi(row[2]), db);
        VisitState visitState = (VisitState)atoi(row[4])

        std::cout << "\tID: " << row[0] <<
                     "\n\tVisit date: " << ctime(&visitDateTime) <<
                     "\n\tPatient: " << tmpPatient.getName() << " " << tmpPatient.getSurname() <<
                     "\n\tDoctor: " << tmpDoctor.getName() << " " << tmpDoctor.getSurname();

        std::cout << "\n\tVisit status: ";

        switch (visitState) {
        case Booked:
            std::cout <<  "Booked";
            break;
        case Realized:
            std::cout <<  "Realized";
            break;
        case Unrealized:
            std::cout <<  "Unrealized";
            break;
        }

        if(row[5]!="") {
         std::cout << "\n\tDescription: " << row[5];
        }

        std::cout << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't visits" << std::endl;
    }
}

void Visit::showAllVisitsByState(Visit::VisitState visitState, DbConnector &db)
{
    std::string query = "SELECT * FROM Visit WHERE VisitState=" + std::to_string((int)visitState);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;

        time_t visitDateTime = atoi(row[1]);
        Patient tmpPatient = Patient::getPatient(atoi(row[3]), db);
        Doctor tmpDoctor = Doctor::getDoctor(atoi(row[2]), db);
        VisitState visitState = (VisitState)atoi(row[4])

        std::cout << "\tID: " << row[0] <<
                     "\n\tVisit date: " << ctime(&visitDateTime) <<
                     "\n\tPatient: " << tmpPatient.getName() << " " << tmpPatient.getSurname() <<
                     "\n\tDoctor: " << tmpDoctor.getName() << " " << tmpDoctor.getSurname();

        std::cout << "\n\tVisit status: ";

        switch (visitState) {
        case Booked:
            std::cout <<  "Booked";
            break;
        case Realized:
            std::cout <<  "Realized";
            break;
        case Unrealized:
            std::cout <<  "Unrealized";
            break;
        }

        if(row[5]!="") {
         std::cout << "\n\tDescription: " << row[5];
        }

        std::cout << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't visits with " << visitState << " visit state" << std::endl;
    }
}

void Visit::showAllVisitsByPatient(Patient &patient, DbConnector &db)
{
    std::string query = "SELECT * FROM Visit WHERE Patient_ID=" + std::to_string(patient.getId());
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;

        time_t visitDateTime = atoi(row[1]);
        Patient tmpPatient = Patient::getPatient(atoi(row[3]), db);
        Doctor tmpDoctor = Doctor::getDoctor(atoi(row[2]), db);
        VisitState visitState = (VisitState)atoi(row[4])

        std::cout << "\tID: " << row[0] <<
                     "\n\tVisit date: " << ctime(&visitDateTime) <<
                     "\n\tPatient: " << tmpPatient.getName() << " " << tmpPatient.getSurname() <<
                     "\n\tDoctor: " << tmpDoctor.getName() << " " << tmpDoctor.getSurname();

        std::cout << "\n\tVisit status: ";

        switch (visitState) {
        case Booked:
            std::cout <<  "Booked";
            break;
        case Realized:
            std::cout <<  "Realized";
            break;
        case Unrealized:
            std::cout <<  "Unrealized";
            break;
        }

        if(row[5]!="") {
         std::cout << "\n\tDescription: " << row[5];
        }

        std::cout << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't visit of " << patient.getName() << " " << patient.getSurname() << " patient" << std::endl;
    }
}

void Visit::showAllVisitsByDoctor(Doctor &doctor, DbConnector &db)
{
    std::string query = "SELECT * FROM Visit WHERE Doctor_ID=" + std::to_string(doctor.getId());
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    int resultsAmount = 0;
    while(row = mysql_fetch_row(res))
    {
        resultsAmount++;

        time_t visitDateTime = atoi(row[1]);
        Patient tmpPatient = Patient::getPatient(atoi(row[3]), db);
        Doctor tmpDoctor = Doctor::getDoctor(atoi(row[2]), db);
        VisitState visitState = (VisitState)atoi(row[4])

        std::cout << "\tID: " << row[0] <<
                     "\n\tVisit date: " << ctime(&visitDateTime) <<
                     "\n\tPatient: " << tmpPatient.getName() << " " << tmpPatient.getSurname() <<
                     "\n\tDoctor: " << tmpDoctor.getName() << " " << tmpDoctor.getSurname();

        std::cout << "\n\tVisit status: ";

        switch (visitState) {
        case Booked:
            std::cout <<  "Booked";
            break;
        case Realized:
            std::cout <<  "Realized";
            break;
        case Unrealized:
            std::cout <<  "Unrealized";
            break;
        }

        if(row[5]!="") {
         std::cout << "\n\tDescription: " << row[5];
        }

        std::cout << std::endl;
    }
    if (resultsAmount == 0) {
        std::cout << "\tThere isn't visit of " << doctor.getName() << " " << doctor.getSurname() << " doctor" << std::endl;
    }
}

int Visit::countRecordsByPatient(Patient &patient, DbConnector &db)
{
    return db.countRecords("Visit WHERE Patient_ID="+std::to_string(patient.getId()));
}

int Visit::countRecordsByDoctor(Doctor &doctor, DbConnector &db)
{
    return db.countRecords("Visit WHERE Doctor_ID="+std::to_string(doctor.getId()));
}

int Visit::countRecords(DbConnector &db)
{
    return db.countRecords("Visit");
}

Visit Visit::getVisit(int id, DbConnector &db)
{
    std::string query = "SELECT * FROM Visit WHERE Visit_ID=" + std::to_string(id);
    MYSQL_ROW row;
    MYSQL_RES *res = db.executeQuery(query);
    if (row = mysql_fetch_row(res))
    {
        return Visit(atoi(row[0]), row[1], row[2]);
        return Visit(atoi(row[0]), atoi(row[1]), Doctor::getDoctor(atoi(row[2]), db), Patient::getPatient(atoi(row[3]), db), (VisitState)atoi(row[4]), row[5]);
    }
    return Visit(-1, NULL, Doctor(-1, "", "", 0, Doctor::DoctorType::NoType, Specialization("")), Patient(-1, "", ""), VisitState::Unrealized, "");
}


ModificationResult Visit::editVisitState(int id, Visit::VisitState visitState, DbConnector &db)
{
    Visit tmpVisit = getVisit(id, db);
    std::cout <<"\nType in description to this visit: ";

    std::string description;

    getline(std::cin, description);

     while (description.length()==0 )
         getline(std::cin, description);


     if (tmpVisit.getId() != -1) {

         std::string query = "UPDATE Visit SET VisitState='" + std::to_string((int)visitState) + "', Description='"+ description +"' WHERE Visit_ID=" + std::to_string(id);
         db.executeQuery(query);
         return ModificationResult::Successed;
     }

     return ModificationResult::Failed;

}

time_t Visit::getVisitDateTime() const
{
    return _visitDateTime;
}

int Visit::getId() const
{
    return _id;
}

Doctor Visit::getDoctor() const
{
    return _doctor;
}

Patient Visit::getPatient() const
{
    return _patient;
}

Visit::VisitState Visit::getVisitState() const
{
    return _visitState;
}

std::string Visit::getDescription() const
{
    return _description;
}
