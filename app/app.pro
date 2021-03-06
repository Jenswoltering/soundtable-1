#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T13:01:54
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    a/projectafactory.cpp \
    b/projectbfactory.cpp \
    abstractprojectinfo.cpp \
    abstractprojectwidget.cpp \
    abstractprojectfactory.cpp

HEADERS  += mainwindow.h \
    a/projectafactory.h \
    b/projectbfactory.h \
    projectinfo.h \
    abstractprojectinfo.h \
    projectwidget.h \
    abstractprojectwidget.h \
    abstractprojectfactory.h

FORMS    += mainwindow.ui
