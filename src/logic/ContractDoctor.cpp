#include "ContractDoctor.h"


#include "FullTimeDoctor.h"


ContractDoctor::ContractDoctor(int id, std::string name, std::string surname, double salary, Specialization specialization)
    : Doctor (id, name, surname, salary, DoctorType::ContractDoctor, specialization)
{

}

bool ContractDoctor::checkSpecialization(const Specialization &specialization) {

    //Contract doctors can't be a sexuolog in my hospitals
    if( specialization.getName() == "Kardiologia") {
        return false;
    }
    return true;
}
