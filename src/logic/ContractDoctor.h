#ifndef CONTRACDOCTOR_H
#define CONTRACDOCTOR_H

#include "pch.h"
#include "Doctor.h"

class ContractDoctor : public Doctor
{
public:
    ContractDoctor(int id, std::string name, std::string surname, double salary, Specialization specialization);

    ~ContractDoctor() override {}

    bool checkSpecialization(const Specialization &specialization) override;
};

#endif // CONTRACDOCTOR_H
