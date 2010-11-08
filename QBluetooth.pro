
HEADERS += \
    qbluetooth.hpp \
    bluetoothrfcomm.hpp \
    bluetoothdevice.hpp

SOURCES += \
    qbluetooth.cpp \
    main.cpp \
    bluetoothrfcomm.cpp \
    bluetoothdevice.cpp

FORMS += \
    qbluetooth.ui

unix: LIBS += -lbluetooth
RESOURCES += \
    qbluetooth.qrc
