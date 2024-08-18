#ifndef CHANGE_TAXI_FARE_H
#define CHANGE_TAXI_FARE_H

#include <QDialog>

namespace Ui {
class change_taxi_fare;
}

class change_taxi_fare : public QDialog
{
    Q_OBJECT

public:
    explicit change_taxi_fare(QWidget *parent = nullptr);
    ~change_taxi_fare();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_taxi_fare *ui;
};

#endif // CHANGE_TAXI_FARE_H
