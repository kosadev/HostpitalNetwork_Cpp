TEMPLATE = lib
CONFIG += silent static
TARGET = logic

HEADERS += \
    DbConnector.h \
    pch.h \
    Employee.h \
    Specialization.h \
    Doctor.h \
    FullTimeDoctor.h \
    ContractDoctor.h \
    Patient.h

SOURCES += \
    DbConnector.cpp \
    Employee.cpp \
    Specialization.cpp \
    Doctor.cpp \
    FullTimeDoctor.cpp \
    ContractDoctor.cpp \
    Patient.cpp

