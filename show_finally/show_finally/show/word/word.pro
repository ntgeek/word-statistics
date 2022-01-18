#-------------------------------------------------
#
# Project created by QtCreator 2022-01-15T17:07:17
#
#-------------------------------------------------

QT       += core gui
RC_ICONS = geek.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = word
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    new_main.cpp \
    tnoded.cpp \
    double_link_list.cpp \
    hashtable.cpp

HEADERS += \
        mainwindow.h \
    new_main.h \
    tnoded.h \
    double_link_list.h \
    hashtable.h


FORMS += \
        mainwindow.ui \
    new_main.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

