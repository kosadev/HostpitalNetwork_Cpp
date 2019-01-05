TARGET = TestCarRental

QT += testlib
TEMPLATE = app
SOURCES += main.cpp
CONFIG += build
CONFIG += testcase

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/logic/debug/ -llogic

INCLUDEPATH += $$PWD/../../src/logic
DEPENDPATH += $$PWD/../../src/logic

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/logic/release/liblogic.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/logic/debug/liblogic.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/logic/release/logic.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/logic/debug/logic.lib


