QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosedatasource.cpp \
    choosesortingmethod.cpp \
    enternumberofpeople.cpp \
    main.cpp \
    mainwindow.cpp \
    persongenerator.cpp \
    sorteddatadisplay.cpp \
    sortingoptionswindow.cpp

HEADERS += \
    DynamicArray.h \
    ISorter.h \
    IndexOutOfRange.h \
    MergeSorter.h \
    MutableArraySequence.h \
    Person.h \
    QuickSorter.h \
    SelectionSorter.h \
    Sequence.h \
    choosedatasource.h \
    choosesortingmethod.h \
    enternumberofpeople.h \
    functions.h \
    mainwindow.h \
    persongenerator.h \
    sorteddatadisplay.h \
    sortingoptionswindow.h

FORMS += \
    choosedatasource.ui \
    choosesortingmethod.ui \
    enternumberofpeople.ui \
    mainwindow.ui \
    sorteddatadisplay.ui \
    sortingoptionswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
