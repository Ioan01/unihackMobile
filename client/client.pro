QT += quick
QT += network
QT += qml sql
CONFIG += c++11 qmltypes

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        loginscreen.cpp \
        main.cpp \
        network.cpp \
        querymanager.cpp \
        registerscreen.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
CONFIG += qmltypes
QML_IMPORT_NAME = widgets
QML_IMPORT_MAJOR_VERSION = 1

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    JsonLibraries.h \
    loginscreen.h \
    querymanager.h \
    network.h \
    registerscreen.h

ANDROID_ABIS = armeabi-v7a
