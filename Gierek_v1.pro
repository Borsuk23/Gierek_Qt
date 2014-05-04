#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T18:12:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gierek_v1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AI.cpp \
    Client.cpp \
    CoalDeposit.cpp \
    Game.cpp \
    HeatingPlant.cpp \
    Ironworks.cpp \
    Market.cpp \
    Mine.cpp \
    Miner.cpp \
    Order.cpp \
    Player.cpp \
    PowerStation.cpp \
    Storehouse.cpp

HEADERS  += mainwindow.h \
    AI.h \
    Client.h \
    CoalDeposit.h \
    Game.h \
    HeatingPlant.h \
    Ironworks.h \
    Market.h \
    Mine.h \
    Miner.h \
    Order.h \
    Player.h \
    PowerStation.h \
    Storehouse.h

FORMS    += mainwindow.ui
