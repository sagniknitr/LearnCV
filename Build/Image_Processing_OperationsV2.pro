#-------------------------------------------------
#
# Project created by QtCreator 2020-05-09 T12:18:49
# Author : Sagnik Basu
# Organization : 
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LearnCV V2
TEMPLATE = app


SOURCES += main.cpp\
    proc_functions.cpp \
    uiandmain.cpp \
    parameters.cpp \
    setparameters.cpp \
    paramsetcalls.cpp

HEADERS  += imageproc.h \
    parameters.h \
    setparameters.h

FORMS    += imageproc.ui \
    setparameters.ui

QT += widgets

INCLUDEPATH += F:\\OpenCV-2.4.9\\include

LIBS += -LF:\\OpenCV-2.4.9\\build-qt\\lib \
    -lopencv_core249d \
     -lopencv_highgui249d \
    -lopencv_imgproc249d \
    -lopencv_objdetect249d


DISTFILES +=

win32:RC_ICONS += IconCyborg.ico

RESOURCES += \
    resfile1.qrc
