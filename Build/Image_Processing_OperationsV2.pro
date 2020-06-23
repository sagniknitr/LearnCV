#-------------------------------------------------
#
# Project created by QtCreator 2020-05-09 T12:18:49
# Author : Sagnik Basu
# Organization : 
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LearnCV
TEMPLATE = app


SOURCES += Source\\main.cpp\
    Source\\proc_functions.cpp \
    Source\\uiandmain.cpp \
    Source\\parameters.cpp \
    Source\\setparameters.cpp \
    Source\\paramsetcalls.cpp

HEADERS  += Include\\imageproc.h \
    Include\\parameters.h \
    Include\\setparameters.h

FORMS    += Build\\imageproc.ui \
    Build\\setparameters.ui

QT += widgets

INCLUDEPATH += /usr/local/include/opencv4\
               Include

LIBS += $(shell pkg-config opencv --libs)



DISTFILES +=

win32:RC_ICONS += Resources\\Sagnik.ico

RESOURCES += \
   Build\\resfile1.qrc
