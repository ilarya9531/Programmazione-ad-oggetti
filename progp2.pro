#-------------------------------------------------
#
# Project created by QtCreator 2019-06-19T11:19:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TEMPLATE = app

TARGET = progp2



SOURCES += main.cpp\
    model/difesa.cpp \
    model/attacco.cpp \
    model/exception.cpp \
    model/personaggio.cpp \
    model/eroe.cpp \
    view/window.cpp

HEADERS  += main.h \
    view/window.h\
    model/personaggio.h \
    model/exception.h \
    model/attacco.h \
    model/difesa.h \
    model/eroe.h \
    model/container.h \
    model/deepptr.h

