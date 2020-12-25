QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    src/core/calculator.cpp \
    src/core/calculatorservice.cpp \
    src/gui/inputscreen.cpp \
    src/core/inputvalidation.cpp \
    main.cpp \
    src/gui/mainwindow.cpp \
    src/utils/utils.cpp

HEADERS += \
    header/core/calculator.h \
    header/core/calculatorservice.h \
    header/gui/inputscreen.h \
    header/core/inputvalidation.h \
    header/gui/mainwindow.h \
    header/utils/utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets/images.qrc \
    assets/styles.qrc
