#ifndef FULLTIMEDOCTOR_H
#define FULLTIMEDOCTOR_H

#include "pch.h"
#include "Doctor.h"

class FullTimeDoctor : public Doctor
{
public:
    FullTimeDoctor(int id, std::string name, std::string surname, double salary, Specialization specialization);

    ~FullTimeDoctor() override {}

    bool checkSpecialization(const Specialization &specialization) override;

};

#endif // FULLTIMEDOCTOR_H
