#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T15:02:44
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++11

DESTDIR   = ../../bin
INCLUDEPATH += "../../src"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release){
    TARGET = OEasyMessage-Qt5-MinGW-debug
} else {
    TARGET = OEasyMessage-Qt5-MinGW-release
}

TEMPLATE = app


SOURCES += main.cpp\
        oe.cpp \
    ../../src/OE/Message/ax/commonhelper.cpp \
    ../../src/OE/Message/oeprompt.cpp \
    ../../src/OE/Message/oeasymessage.cpp \
    ../../src/OE/Message/oeasywebnotice.cpp \
    ../../src/OE/Message/oeasysms.cpp

HEADERS  += oe.h \
    ../../src/OE/Message/ax/commonhelper.h \
    ../../src/OE/Message/oeprompt.h \
    ../../src/OE/Message/oeasymessage.h \
    ../../src/OE/Message/oeasywebnotice.h \
    ../../src/OE/Message/oeasysms.h
