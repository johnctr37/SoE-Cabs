#include <QMessageBox>
#include "change_taxi_fare.h"
#include "ui_change_taxi_fare.h"
#include "admin_services.h"
#include "global.h"

change_taxi_fare::change_taxi_fare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_taxi_fare)
{
    ui->setupUi(this);
}

change_taxi_fare::~change_taxi_fare()
{
    delete ui;
}

void change_taxi_fare::on_pushButton_clicked()
{
    if(ui->radioButton_dec_2->isChecked()){
        charge_per_km -= 2;
    }
    else if(ui->radioButton_dec_3->isChecked()){
        charge_per_km -= 3;
    }
    else if(ui->radioButton_dec_5->isChecked()){
        charge_per_km -= 5;
    }
    else if(ui->radioButton_inc_3->isChecked()){
        charge_per_km += 3;
    }
    else if(ui->radioButton_inc_5->isChecked()){
        charge_per_km += 5;
    }
    else if(ui->radioButton_inc_2->isChecked()){
        charge_per_km += 2;
    }
    QMessageBox::information(this,"Fare information","Fare changed successfully");
    close();
}


void change_taxi_fare::on_pushButton_2_clicked()
{
    close();

}

