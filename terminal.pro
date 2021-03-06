QT += widgets serialport
QT += network widgets
TARGET = terminal
TEMPLATE = app
QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O3
QMAKE_CXXFLAGS_RELEASE += -O0        # Release -O0


SOURCES += \
    axistag.cpp \
    cpg_api.cpp \
    main.cpp \
    mainwindow.cpp \
    matlab/CPG2C.cpp \
    matlab/CPG2C_data.cpp \
    matlab/CPG2C_initialize.cpp \
    matlab/CPG2C_terminate.cpp \
    matlab/ode45.cpp \
    matlab/rtGetInf.cpp \
    matlab/rtGetNaN.cpp \
    matlab/rt_nonfinite.cpp \
    network/udp/server.cpp \
    qcustomplot.cpp \
    realtimeplot.cpp \
    serial/mytimer.cpp \
    serial/serialdata.cpp \
    serial/servo.cpp \
    settingsdialog.cpp \
    single.cpp

HEADERS += \
    axistag.h \
    cpg_api.h \
    mainwindow.h \
    matlab/CPG2C.h \
    matlab/CPG2C_data.h \
    matlab/CPG2C_initialize.h \
    matlab/CPG2C_terminate.h \
    matlab/CPG2C_types.h \
    matlab/coder_array.h \
    matlab/ode45.h \
    matlab/rtGetInf.h \
    matlab/rtGetNaN.h \
    matlab/rt_nonfinite.h \
    matlab/rtwtypes.h \
    matlab/tmwtypes.h \
    network/udp/server.h \
    qcustomplot.h \
    realtimeplot.h \
    serial/mytimer.h \
    serial/serialdata.h \
    serial/servo.h \
    settingsdialog.h \
    single.h

FORMS += \
    mainwindow.ui \
    realtimeplot.ui \
    settingsdialog.ui \
    single.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
