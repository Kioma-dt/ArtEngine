QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_FILE = images/app_icon.rc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    globalkey/globalkey.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    memoryreader/memoryreader.cpp \
    widgets/filtrwidget.cpp \
    widgets/findwidget.cpp \
    widgets/hotkeywidget.cpp

HEADERS += \
    globalkey/globalkey.h \
    main/mainwindow.h \
    main/ui_mainwindow.h \
    memoryreader/memoryreader.h \
    widgets/filtrwidget.h \
    widgets/findwidget.h \
    widgets/hotkeywidget.h \
    widgets/ui_filtrwidget.h \
    widgets/ui_findwidget.h \
    widgets/ui_hotkeywidget.h


FORMS += \
    main/mainwindow.ui \
    widgets/filtrwidget.ui \
    widgets/findwidget.ui \
    widgets/hotkeywidget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
