QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_services.cpp \
    bookingdestopt.cpp \
    cab_status.cpp \
    change_taxi_fare.cpp \
    customer.cpp \
    customer_services.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    paymentconfirmation.cpp \
    update_cab_status.cpp

HEADERS += \
    admin.h \
    admin_services.h \
    bookingdestopt.h \
    cab_status.h \
    change_taxi_fare.h \
    customer.h \
    customer_services.h \
    global.h \
    mainwindow.h \
    paymentconfirmation.h \
    update_cab_status.h

FORMS += \
    admin.ui \
    admin_services.ui \
    bookingdestopt.ui \
    cab_status.ui \
    change_taxi_fare.ui \
    customer.ui \
    customer_services.ui \
    mainwindow.ui \
    paymentconfirmation.ui \
    update_cab_status.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
