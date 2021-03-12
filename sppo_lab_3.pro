QT     += core gui widgets charts

CONFIG += c++1z charts
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abstractadapter.cpp \
        abstractcalculation.cpp \
        abstractchartadapter.cpp \
        barchartadapter.cpp \
        contentfortableview.cpp \
        filecalculation.cpp \
        main.cpp \
        mainwindow.cpp \
        piechartadapter.cpp \
        tableadapter.cpp \
        typecalculation.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractadapter.h \
    abstractcalculation.h \
    abstractchartadapter.h \
    barchartadapter.h \
    contentfortableview.h \
    filecalculation.h \
    mainwindow.h \
    piechartadapter.h \
    tableadapter.h \
    typecalculation.h

FORMS += \
    mainwindow.ui
