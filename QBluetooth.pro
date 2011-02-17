
HEADERS += \
    qbluetooth.hpp \
    bluetoothdevice.hpp \
	bluetoothrfcomm.hpp \
    bluetoothdisplaytable.hpp \
	primitive.hpp \
	line.hpp \
	rectangle.hpp \
	rectdialog.hpp

SOURCES += \
    qbluetooth.cpp \
    main.cpp \
    bluetoothdisplaytable.cpp \
	primitive.cpp \
	line.cpp \
	rectangle.cpp \
	rectdialog.cpp

FORMS += \
    qbluetooth.ui

RESOURCES += \
    qbluetooth.qrc

linux-g++ {
	message("Linux")
	SOURCES += bluetoothdevice_linux.cpp \
		bluetoothrfcomm_linux.cpp
	INCLUDEPATH += /usr/include
	LIBS += -lbluetooth
}

macx-g++ {
	message("Mac OS X")
	QMAKE_CXXFLAGS += -xobjective-c++
	SOURCES +=	bluetoothdevice_macx.cpp \
		bluetoothrfcomm_macx.cpp
	INCLUDEPATH += /System/Library/Frameworks/Foundation.framework/Headers \
		/System/Library/Frameworks/IOBluetooth.framework/Headers
	QMAKE_LFLAGS += -F/System/Library/Frameworks
	LIBS += -lobjc \
		-framework Foundation \
		-framework IOBluetooth
}
