#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T13:35:40
#
#-------------------------------------------------


QT      += core sql
QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLN_1_UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        scientist.cpp \
        computer.cpp \
        connected.cpp \
        service.cpp \
        servicecomputer.cpp \
        serviceconnected.cpp\
        database.cpp \

HEADERS += mainwindow.h\
        scientist.h \
        computer.h \
        connected.h \
        service.h \
        servicecomputer.h \
        serviceconnected.h \
        database.h \

FORMS    += mainwindow.ui
