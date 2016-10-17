TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ./list_src/list_tf.cpp

HEADERS += \
    ./list_src/list_tf.h \
    list_err.h
