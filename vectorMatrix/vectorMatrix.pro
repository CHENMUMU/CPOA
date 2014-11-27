
TARGET = vectorMatrix
TEMPLATE = lib
CONFIG += staticlib

#INCLUDEPATH +=

SOURCES += *.cpp \
    vec2f.cpp \
    vec3f.cpp \
    matrix33f.cpp


HEADERS += *.h *.hpp \
    vectCalc.h \
    vecttempl.h \
    array.h \
    array.hpp \
    vecteur.h \
    vecteur.hpp \
    vec2f.h \
    vec3f.h \
    matrix33f.h \
    Image.h \
    Image.hpp \
    Image2D.h \
    Image2D.hpp \
    Image2Grey.h \
    Image2Grey.hpp



DESTDIR = ../lib

QMAKE_CXXFLAGS += -Wall

