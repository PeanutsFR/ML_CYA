#-------------------------------------------------
#
# Project created by QtCreator 2014-06-03T16:37:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ardrone/video.cpp \
    ardrone/version.cpp \
    ardrone/udp.cpp \
    ardrone/tcp.cpp \
    ardrone/navdata.cpp \
    ardrone/config.cpp \
    ardrone/command.cpp \
    ardrone/ardrone.cpp \
    dialog.cpp \
    mldata.cpp

HEADERS  += mainwindow.h \
    ardrone/uvlc.h \
    ardrone/ardrone.h \
    dialog.h \
    mldata.h \
    traintestsplit.h

FORMS    += mainwindow.ui \
    dialog.ui

INCLUDEPATH += -D__STDC_CONSTANT_MACROS
INCLUDEPATH += \\usr\\local\\include
INCLUDEPATH += \\home\\bouazime\\Documents\\stage_drone_cmi\\algorithmes\\ml_cya_git
INCLUDEPATH += \\usr\\include

LIBS += -L\\usr\\local\\lib \
    -lavcodec \
    -lopencv_calib3d \
    -lopencv_contrib \
    -lopencv_core \
    -lopencv_features2d \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_legacy \
    -lopencv_ml \
    -lopencv_objdetect \
    -lopencv_ocl \
    -lopencv_video \
    -lopencv_videostab \
    -lm \
    -lpthread \
    -lavutil \
    -lavformat \
    -lswscale
