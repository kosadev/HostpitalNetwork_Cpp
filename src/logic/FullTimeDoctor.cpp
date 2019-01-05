#include "FullTimeDoctor.h"


FullTimeDoctor::FullTimeDoctor(int id, std::string name, std::string surname, double salary, Specialization specialization)
    : Doctor (id, name, surname, salary, DoctorType::FullTimeDoctor, specialization)
{

}

bool FullTimeDoctor::checkSpecialization(const Specialization &specialization) {

    //Full time doctors can't be a sexuolog in my hospitals
    if( specialization.getName() == "Seksuologia") {
        return false;
    }
    return true;
}
