#-------------------------------------------------
#
# Project created by QtCreator 2012-06-18T17:13:38
#
#-------------------------------------------------

QT       += core gui
TARGET = CodeZ
TEMPLATE = app


SOURCES = main.cpp \
        mainwindow.cpp \
        highlighter.cpp \
        json.cpp \
        functions.cpp \
    category.cpp \
    codeeditor.cpp \
    aboutwindow.cpp \
    langagewindow.cpp \
    log.cpp \
    coloration.cpp \
    dictionnary.cpp \
    snippet.cpp \
    langage.cpp \
    categorywindow.cpp \
    snippetlistwidget.cpp

HEADERS = mainwindow.h \
          main.h \
          highlighter.h \
          json.h \
          functions.h \
    constant.h \
    category.h \
    codeeditor.h \
    aboutwindow.h \
    langagewindow.h \
    main.h \
    log.h \
    coloration.h \
    dictionnary.h \
    snippet.h \
    langage.h \
    categorywindow.h \
    snippetlistwidget.h


FORMS    +=

RESOURCES += \
    skin.qrc

OTHER_FILES += \
    icon.rc \
    style.qss

RC_FILE = icon.rc
