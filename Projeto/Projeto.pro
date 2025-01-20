TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cjogo.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cjogo.h

