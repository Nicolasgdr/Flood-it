QT       += core gui
greaterThan(QT_MAJOR_VERSION,5)QT +=widgets

CONFIG += c++20

SOURCES += \
        Controller.cpp \
        Game.cpp \
        Main.cpp \
        Play.cpp \
        Size.cpp

HEADERS += \
    Board.hpp \
    Color.h \
    Controller.h \
    Play.h \
    Game.h \
    Position.hpp \
    Size.h \
    Square.hpp \
    random.hpp

FORMS += \
    Size.ui \
    Play.ui
