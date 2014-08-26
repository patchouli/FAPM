#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T14:22:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FAPM
TEMPLATE = app


SOURCES += main.cpp\
        fapm.cpp \
    net.cpp

HEADERS  += fapm.h \
    net.h

FORMS    += fapm.ui

QT += network
