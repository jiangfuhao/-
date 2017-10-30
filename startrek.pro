TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c
LIBS += -L/usr/lib -lallegro -lallegro_primitives -lallegro_color -lallegro_font -lallegro_main -lallegro_ttf -lallegro_acodec -lallegro_audio -lallegro_image
INCLUDEPATH += -I/usr/include/allegro
HEADERS += \
    game.h

