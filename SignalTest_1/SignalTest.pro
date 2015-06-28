#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T05:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalTest
TEMPLATE = app


SOURCES += main.cpp\
    signalwindow.cpp \
    signaldialog.cpp \
    ../QT/CandyCrush/event.cpp \
    ../QT/CandyCrush/game.cpp \
    ../QT/CandyCrush/main.cpp \
    ../QT/CandyCrush/res.cpp \
    ../QT/CandyCrush/result.cpp \
    cell.cpp \
    game.cpp \
    start.cpp

HEADERS  += signalwindow.h \
    signaldialog.h \
    ../QT/CandyCrush/cell.h \
    ../QT/CandyCrush/event.h \
    ../QT/CandyCrush/game.h \
    ../QT/CandyCrush/result.h \
    ../QT/CandyCrush/start.h \
    cell.h \
    game.h \
    start.h

FORMS    += signalwindow.ui \
    signaldialog.ui \
    ../QT/CandyCrush/cell.ui \
    ../QT/CandyCrush/event.ui \
    ../QT/CandyCrush/game.ui \
    ../QT/CandyCrush/result.ui \
    ../QT/CandyCrush/start.ui \
    cell.ui \
    event.ui \
    game.ui \
    result.ui \
    start.ui

RESOURCES += \
    ../QT/CandyCrush/res.qrc \
    res.qrc

SUBDIRS += \
    CandyCrush.pro

DISTFILES += \
    Thumbs.db \
    CandyCrush.pro.user \
    SignalTest.pro.user \
    12gatu_c_yukidaruma_01_d_05.png \
    BELL.png \
    bell1.png \
    bell2.png \
    CAN.png \
    can1.png \
    can2.png \
    COOKIE.png \
    cookie1.png \
    cookie2.png \
    LEF.png \
    lef1.png \
    lef2.png \
    SNOW.png \
    snow1.png \
    snow2.png \
    start1.png \
    xmas_tool01_d_01.png \
    xmas_tool01_d_02.png \
    xmas_tool01_d_03.png \
    xmas_tool02_d_01.png \
    xmas_tool02_d_02.png \
    xmas_tool02_d_03.png \
    xmas_tool02_d_04.png \
    xmas_tool02_d_05.png \
    xmas_tool05_d_13.png \
    xmas_tool06_d_14.png \
    xmas_tool08_a_01.png \
    xmas_tool09_c_01.png \
    xmas01_d_01.png \
    xmas01_d_02.png \
    BMAX1.tif \
    BMAX2.tif \
    BMAX3.tif
