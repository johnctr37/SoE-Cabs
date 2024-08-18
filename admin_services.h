#ifndef ADMIN_SERVICES_H
#define ADMIN_SERVICES_H

#include <QDialog>
#include "cab_status.h"
#include "change_taxi_fare.h"

namespace Ui {
class Admin_services;
}

class Admin_services : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_services(QWidget *parent = nullptr);
    ~Admin_services();

private slots:

    void on_pushButton_admin_logout_clicked();

    void on_pushButton_admin_changefare_clicked();

    void on_pushButton_admin_cabstatus_clicked();

    void on_pushButton_admin_canceledbookings_clicked();

    void on_pushButton_admin_customerrecord_clicked();

private:
    Ui::Admin_services *ui;
    Cab_status *cab_status;
    change_taxi_fare *changefare;
};

#endif // ADMIN_SERVICES_H
