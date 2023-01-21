QT       += core gui
QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boss1_enemy.cpp \
    boss_enemy.cpp \
    bossfinal_enemy.cpp \
    bullets.cpp \
    enemy.cpp \
    equipment.cpp \
    gameover.cpp \
    main.cpp \
    main_char.cpp \
    menuwindow.cpp \
    normal_enemy.cpp \
    spacecraft.cpp \
    widget.cpp

HEADERS += \
    boss1_enemy.h \
    boss_enemy.h \
    bossfinal_enemy.h \
    bullets.h \
    enemy.h \
    equipment.h \
    gameover.h \
    main_char.h \
    menuwindow.h \
    normal_enemy.h \
    spacecraft.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

FORMS += \
    gameover.ui \
    menuwindow.ui
