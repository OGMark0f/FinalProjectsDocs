QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += /home/linuxbrew/.linuxbrew/Cellar/poppler/21.03.0_1/include/poppler/qt5
INCLUDEPATH += /home/mark0f/DuckX/include/
INCLUDEPATH += /home/mark0f/pugixml/src/
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lpoppler-qt5
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lQt5Core
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lQt5Widgets
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lQt5Gui
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lQt5Xml
LIBS += -L/home/mark0f/DuckX/build/ -lduckx
LIBS += -L/home/mark0f/pugixml/build/ -lpugixml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
