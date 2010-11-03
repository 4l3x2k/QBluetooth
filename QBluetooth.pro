
HEADERS += \
    qbluetooth.hpp \
    bluetooth.hpp

SOURCES += \
    qbluetooth.cpp \
    main.cpp \
    bluetooth.cpp

FORMS += \
    qbluetooth.ui

unix: LIBS += -lbluetooth
