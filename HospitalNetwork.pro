TEMPLATE = subdirs
CONFIG += ordered
CONFIG += c++11
CONFIG += console
CONFIG += build

SUBDIRS = src tests

tests.depends = src;
