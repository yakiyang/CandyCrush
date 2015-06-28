#-------------------------------------------------
#
# Project created by QtCreator 2015-06-28T21:05:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candy
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    cell.cpp \
    event.cpp \
    game.cpp \
    result.cpp

HEADERS  += start.h \
    cell.h \
    event.h \
    game.h \
    result.h

FORMS    += start.ui \
    cell.ui \
    event.ui \
    game.ui \
    result.ui

RESOURCES += \
    res.qrc
