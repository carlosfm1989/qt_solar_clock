#-------------------------------------------------
#
# Project created by QtCreator 2018-01-09T08:02:30
#
#-------------------------------------------------

QT       += core gui  

greaterThan(QT_MAJOR_VERSION, 4): QT += opengl core widgets gui 

TARGET = qt_solar_clock
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include\
	       $$PWD/build/mesa-17.3.3/include/

CONFIG += c++11
SOURCES += \
    src/solarsystem.cpp \
    src/mainwindow.cpp \
    src/main.cpp \
    src/celestialbody.cpp \
    src/orbitaltrack.cpp

HEADERS += \
    include/mainwindow.h \
    include/celestialbody.h \
    include/solarsystem.h \
    include/orbitaltrack.h

FORMS += \
     src/mainwindow.ui

RCC_DIR = build

