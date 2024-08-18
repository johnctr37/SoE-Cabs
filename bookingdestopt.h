#ifndef BOOKINGDESTOPT_H
#define BOOKINGDESTOPT_H


#include <QDialog>
#include "paymentconfirmation.h"

namespace Ui {
class bookingdestopt;
}

class bookingdestopt : public QDialog
{
    Q_OBJECT

public:
    explicit bookingdestopt(QWidget *parent = nullptr);
    ~bookingdestopt();

private slots:
    //void on_pushButton_clicked();

    void on_bookbutton_clicked();


    void on_pushbutton_pay_clicked();

private:
    Ui::bookingdestopt *ui;
    PaymentConfirmation *payment_confirmation;
};

#endif // BOOKINGDESTOPT_H
