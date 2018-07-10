# Author: Gary Huang <gh.nctu+code@gmail.com>
TARGET = main

HEADERS = particle.h
SOURCES = main.cpp

QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#CONFIG += console
#CONFIG += debug
CONFIG -= debug_and_release debug_and_release_target

processing_dir = ./thirdparty/libProcessing

LIBS += -L$${processing_dir}/lib -lProcessing
INCLUDEPATH += $${processing_dir}/include

PRE_TARGETDEPS += $${processing_dir}/lib/libProcessing.a
QMAKE_EXTRA_TARGETS += processing clean distclean extraclean extradistclean

clean.depends = extraclean
extraclean.commands = cd $${processing_dir}/src && make clean

distclean.depends = extradistclean
extradistclean.commands = cd $${processing_dir}/src && make distclean

processing.target = $${processing_dir}/lib/libProcessing.a
processing.depends = FORCE
processing.commands = cd $${processing_dir}/src && qmake && make
