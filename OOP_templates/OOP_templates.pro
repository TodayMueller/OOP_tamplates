QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstract.cpp \
    body.cpp \
    cars.cpp \
    cosmetic.cpp \
    engine.cpp \
    facade.cpp \
    factory.cpp \
    lists.cpp \
    main.cpp \
    mainwindow.cpp \
    overhaul.cpp \
    owners.cpp \
    painting.cpp \
    registration.cpp

HEADERS += \
    abstract.h \
    body.h \
    cars.h \
    cosmetic.h \
    engine.h \
    facade.h \
    factory.h \
    lists.h \
    mainwindow.h \
    overhaul.h \
    owners.h \
    painting.h \
    registration.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
