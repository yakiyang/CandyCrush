#-------------------------------------------------
#
# Project created by QtCreator 2015-06-06T16:06:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CandyCrush
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    game.cpp \
    cell.cpp \
    event.cpp \
    result.cpp

HEADERS  += start.h \
    game.h \
    cell.h \
    event.h \
    result.h

FORMS    += start.ui \
    game.ui \
    cell.ui \
    event.ui \
    result.ui

RESOURCES += \
    res.qrc
