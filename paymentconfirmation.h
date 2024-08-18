#ifndef PAYMENTCONFIRMATION_H
#define PAYMENTCONFIRMATION_H

#include <QDialog>

namespace Ui {
class PaymentConfirmation;
}

class PaymentConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentConfirmation(QWidget *parent = nullptr);
    ~PaymentConfirmation();

private slots:

    void on_pushButton_confirmation_yes_clicked();

    void on_pushButton_confirmation_no_clicked();

private:
    Ui::PaymentConfirmation *ui;
};

#endif // PAYMENTCONFIRMATION_H
