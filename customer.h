#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include "customer_services.h"

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_pushButton_customer_login_clicked();

    void on_pushButton_customer_back_clicked();

private:
    Ui::Customer *ui;
    Customer_services *customer_services;
};

#endif // CUSTOMER_H
