#include "update_cab_status.h"
#include "ui_update_cab_status.h"
#include "customer_services.h"
#include "global.h"
#include <QMessageBox>
#include <QDir>

Update_cab_status::Update_cab_status(QWidget *parent) : QDialog(parent),
                                                        ui(new Ui::Update_cab_status)
{
   ui->setupUi(this);
   ui->pushButton_submit->setVisible(false);
   ui->label_rate->setVisible(false);
   ui->label_enter_cabid->setVisible(false);
   ui->radioButton_1star->setVisible(false);
   ui->radioButton_2star->setVisible(false);
   ui->radioButton_3star->setVisible(false);
   ui->radioButton_4star->setVisible(false);
   ui->radioButton_5star->setVisible(false);
   ui->lineEdit_ente_cab_id->setVisible(false);
   QPixmap pic1(":/resources/img/rating.jpg");
   ui->img_rating->setPixmap(pic1.scaled(1000, 450));
}

Update_cab_status::~Update_cab_status()
{
   delete ui;
}

void Update_cab_status::on_pushButton_proceed_clicked()
{
   if (ui->radioButton_Yes->isChecked())
   {
      ui->img_rating->setVisible((false));
      ui->label_haveureached->setVisible(false);
      ui->radioButton_Yes->setVisible(false);
      ui->radioButton_No->setVisible(false);
      ui->pushButton_submit->setVisible(true);
      ui->label_rate->setVisible(true);
      ui->label_enter_cabid->setVisible(true);
      ui->radioButton_1star->setVisible(true);
      ui->radioButton_2star->setVisible(true);
      ui->radioButton_3star->setVisible(true);
      ui->radioButton_4star->setVisible(true);
      ui->radioButton_5star->setVisible(true);
      ui->lineEdit_ente_cab_id->setVisible(true);
      ui->pushButton_proceed->setVisible(false);
   }
   else if (ui->radioButton_No->isChecked())
   {
      QMessageBox::information(this, "Status", "Feedback is considered after you've reached your destination");
      close();
      Customer_services *cs;
      cs = new Customer_services(this);
      cs->show();
   }
   else
   {
      QMessageBox::warning(this, "Status", "Circle one of the above options");
   }
}

void Update_cab_status::on_pushButton_submit_clicked()
{
   if (ui->lineEdit_ente_cab_id->text().isEmpty() || !(ui->radioButton_1star->isChecked() || ui->radioButton_2star->isChecked() || ui->radioButton_3star->isChecked() || ui->radioButton_4star->isChecked() || ui->radioButton_5star->isChecked()))
   {
      QMessageBox::warning(this, "Status", "Make sure you have entered the cab id and feedback.");
   }
   else
   {
      bool ok;
      int cab_id = ui->lineEdit_ente_cab_id->text().toInt(&ok);
      if (ok)
      {
         qDebug() << "The entered integer is: " << cab_id;
      }
      else
      {
         qDebug() << "Invalid input";
      }
      a.cabs[cab_id] = 1;

      QDir dir = QDir::current();
      QString filePath = dir.filePath("CabRatings.txt");
      QFile MyFile(filePath); // Creating Object Due To Which we Write On File
      QTextStream out(&MyFile);
      if (!MyFile.open(QFile::Append | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      QString cab_id_entered = ui->lineEdit_ente_cab_id->text();
      out << "******************************" << '\n';
      out << "Cab_id :" << cab_id_entered << '\n';
      if (ui->radioButton_1star->isChecked())
      {
         out << "Customer rated 1 star to this cab ID" << '\n';
      }
      else if (ui->radioButton_2star->isChecked())
      {
         out << "Customer rated 2 stars to this cab ID" << '\n';
      }
      else if (ui->radioButton_3star->isChecked())
      {
         out << "Customer rated 3 stars to this cab ID" << '\n';
      }
      else if (ui->radioButton_4star->isChecked())
      {
         out << "Customer rated 4 stars to this cab ID" << '\n';
      }
      else
      {
         out << "Customer rated 5 stars to this cab ID" << '\n';
      }
      out << "******************************" << '\n';

      MyFile.flush();
      MyFile.close();

      QMessageBox::information(this, "Thank you", "Thank you for your feedback");
      close();
      Customer_services *cs;
      cs = new Customer_services(this);
      cs->show();
   }
}

void Update_cab_status::on_pushButton_ucs_back_clicked()
{
   close();
   Customer_services *cs;
   cs = new Customer_services(this);
   cs->show();
}
