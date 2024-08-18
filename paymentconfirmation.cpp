#include "paymentconfirmation.h"
#include "global.h"
#include "ui_paymentconfirmation.h"
#include <QMessageBox>
#include<QFile>
#include<QDir>
PaymentConfirmation::PaymentConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentConfirmation)
{
    ui->setupUi(this);
}

PaymentConfirmation::~PaymentConfirmation()
{
    delete ui;
}

void PaymentConfirmation::on_pushButton_confirmation_yes_clicked()
{

    QDir dir=QDir::current();
    QString Path_payconfirm=dir.filePath("PaymentReceipt.txt");
    int i;
    for(i=0;i<no_of_cabs;i++)
    {
       if(a.cabs[i]==1)
       {
           break;
       }
    }
    a.cabs[i]=0;
    //QMessageBox::information(this,"Confirmation","Booking has been confirmed.");
    QFile file(Path_payconfirm);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file for reading: " + file.errorString());
            return;
        }

        QTextStream in(&file);
        QString str_num = QString::number(i);
        QString text = in.readAll()+ "Cab ID: " +str_num ;
        file.close();

        QMessageBox::information(this, "Booking Confirmed!", text);
    close();
}


void PaymentConfirmation::on_pushButton_confirmation_no_clicked()
{
    QDir dir1=QDir::current();
    QString Path_payconfirm=dir1.filePath("PaymentReceipt.txt");
    QDir dir2=QDir::current();
    QString Path_cancelrec=dir2.filePath("cancelledrecords.txt");
    QMessageBox::information(this,"Payment Status","Payment Failed");
    QFile sourcefile(Path_payconfirm);
    if (!sourcefile.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file for reading: " + sourcefile.errorString());
        return;
    }
    QFile targetfile(Path_cancelrec);
    if(!targetfile.open(QFile::Append | QFile::Text))
    {
        QMessageBox::warning(this,"title","File is not opened");
    }
    QTextStream in(&sourcefile);
    QTextStream out(&targetfile);

    out << in.readAll();

    sourcefile.close();
    targetfile.close();
    close();
}

