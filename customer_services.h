#ifndef CUSTOMER_SERVICES_H
#define CUSTOMER_SERVICES_H

#include <QDialog>
#include "cab_status.h"
#include "bookingdestopt.h"
#include "update_cab_status.h"

namespace Ui {
class Customer_services;
}

class Customer_services : public QDialog
{
    Q_OBJECT

public:
    explicit Customer_services(QWidget *parent = nullptr);
    ~Customer_services();

private slots:
    void on_pushButton_customer_booking_clicked();

    void on_pushButton_customer_cabstatus_clicked();

    void on_pushButton_customer_updatestatus_clicked();

    void on_pushButton_customer_logout_clicked();

    void on_pushButton_customer_travelrecord_clicked();

private:
    Ui::Customer_services *ui;
    Cab_status *cab_status;
    bookingdestopt *book;
    Update_cab_status *update_cab_status;
};

#endif // CUSTOMER_SERVICES_H
