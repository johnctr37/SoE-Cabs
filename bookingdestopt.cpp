#include "bookingdestopt.h"
#include "ui_bookingdestopt.h"
#include <QRadioButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <string>
#include <QDir>
#include "global.h"

bookingdestopt::bookingdestopt(QWidget *parent) : QDialog(parent),
                                                  ui(new Ui::bookingdestopt)
{
   ui->setupUi(this);
   ui->farelab->setVisible(false);
   ui->distancelab->setVisible(false);
   ui->distanceop->setVisible(false);
   ui->fareop->setVisible(false);
   QPixmap pic(":/resources/img/bookingimg.jpg");
   ui->label_bookingimg->setPixmap(pic.scaled(1000, 300));
}

bookingdestopt::~bookingdestopt()
{
   delete ui;
}

void bookingdestopt::on_bookbutton_clicked()
{
   QDir dir = QDir::current();
   QString filePath = dir.filePath("BookingRecords.txt");
   QString Path_payconfirm = dir.filePath("PaymentReceipt.txt");
   if (ui->Mandavi->isChecked() && !(ui->passengername->text().isEmpty()))
   {
      ui->label_bookingimg->setVisible(false);

      QFile MyFile(filePath); // Creating Object Due To Which we Write On File
      QTextStream out(&MyFile);
      if (!MyFile.open(QFile::Append | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ///
      QFile payfile(Path_payconfirm); // Creating Object Due To Which we Write On File
      QTextStream outfile(&payfile);
      if (!payfile.open(QFile::WriteOnly | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ////
      float Distance = 5;                                   // Declaration
      float Charges;                                        // Initializing
      Charges = Distance * charge_per_km - Distance * 0.10; // Computing Charges
      QString Name = ui->passengername->text();
      ui->farelab->setVisible(true);
      ui->distancelab->setVisible(true);
      ui->distanceop->setVisible(true);
      ui->fareop->setVisible(true);

      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';
      outfile << '\n'
              << "Name: " << Name << '\n'
              << "From: Damodar To: Mandavi" << '\n'
              << "Fare: " << Charges << '\n';
      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';

      QString d = QString::number(Distance);
      ui->distanceop->setPlainText(d);
      QString f = QString::number(Charges);
      ui->fareop->setPlainText(f);
      out << "**********" << '\n';
      out << "Name: " << Name << '\n'
          << "From: Damodar To: Mandavi" << '\n'
          << "Fare: " << Charges << '\n';
      out << "**********" << '\n';
      payfile.flush();
      payfile.close();
      MyFile.flush();
      MyFile.close();
   }

   else if (ui->Jhelum->isChecked() && !(ui->passengername->text().isEmpty()))
   {
      ui->label_bookingimg->setVisible(false);
      QFile MyFile(filePath); // Creating Object Due To Which we Write On File     // Creating Object Due To Which we Write On File
      QTextStream out(&MyFile);
      if (!MyFile.open(QFile::Append | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ///
      QFile payfile(Path_payconfirm); // Creating Object Due To Which we Write On File
      QTextStream outfile(&payfile);
      if (!payfile.open(QFile::WriteOnly | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ////
      float Distance = 10;                                  // Declaration
      float Charges;                                        // Initializing
      Charges = Distance * charge_per_km - Distance * 0.10; // Computing Charges
      QString Name = ui->passengername->text();
      ui->farelab->setVisible(true);
      ui->distancelab->setVisible(true);
      ui->distanceop->setVisible(true);
      ui->fareop->setVisible(true);

      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';
      outfile << '\n'
              << "Name: " << Name << '\n'
              << "From: Damodar To: Jhelum" << '\n'
              << "Fare: " << Charges << '\n';
      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';

      QString d = QString::number(Distance);
      ui->distanceop->setPlainText(d);
      QString f = QString::number(Charges);
      ui->fareop->setPlainText(f);
      out << "**********" << '\n';
      out << "Name: " << Name << '\n'
          << "From: Damodar To: Jhelum" << '\n'
          << "Fare: " << Charges << '\n';
      out << "**********" << '\n';
      payfile.flush();
      payfile.close();
      MyFile.flush();
      MyFile.close();
   }
   else if (ui->Periyar->isChecked() && !(ui->passengername->text().isEmpty()))
   {
      ui->label_bookingimg->setVisible(false);
      QFile MyFile(filePath); // Creating Object Due To Which we Write On File     // Creating Object Due To Which we Write On File
      QTextStream out(&MyFile);
      if (!MyFile.open(QFile::Append | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ///
      QFile payfile(Path_payconfirm); // Creating Object Due To Which we Write On File
      QTextStream outfile(&payfile);
      if (!payfile.open(QFile::WriteOnly | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ////
      float Distance = 25;                                  // Declaration
      float Charges;                                        // Initializing
      Charges = Distance * charge_per_km - Distance * 0.10; // Computing Charges
      QString Name = ui->passengername->text();
      ui->farelab->setVisible(true);
      ui->distancelab->setVisible(true);
      ui->distanceop->setVisible(true);
      ui->fareop->setVisible(true);

      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';
      outfile << '\n'
              << "Name: " << Name << '\n'
              << "From: Damodar To: Periyar" << '\n'
              << "Fare: " << Charges << '\n';
      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';

      QString d = QString::number(Distance);
      ui->distanceop->setPlainText(d);
      QString f = QString::number(Charges);
      ui->fareop->setPlainText(f);
      out << "**********" << '\n';
      out << "Name: " << Name << '\n'
          << "From: Damodar To: Periyar" << '\n'
          << "Fare: " << Charges << '\n';
      out << "**********" << '\n';
      payfile.flush();
      payfile.close();
      MyFile.flush();
      MyFile.close();
   }

   else if (ui->Shipra->isChecked() && !(ui->passengername->text().isEmpty()))
   {
      ui->label_bookingimg->setVisible(false);

      QFile MyFile(filePath); // Creating Object Due To Which we Write On File     // Creating Object Due To Which we Write On File
      QTextStream out(&MyFile);
      if (!MyFile.open(QFile::Append | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ///
      QFile payfile(Path_payconfirm); // Creating Object Due To Which we Write On File
      QTextStream outfile(&payfile);
      if (!payfile.open(QFile::WriteOnly | QFile::Text))
      {
         QMessageBox::warning(this, "title", "File is not opened");
      }
      ////
      float Distance = 40;                                  // Declaration
      float Charges;                                        // Initializing
      Charges = Distance * charge_per_km - Distance * 0.10; // Computing Charges
      QString Name = ui->passengername->text();
      ui->farelab->setVisible(true);
      ui->distancelab->setVisible(true);
      ui->distanceop->setVisible(true);
      ui->fareop->setVisible(true);

      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';
      outfile << '\n'
              << "Name: " << Name << '\n'
              << "From: Damodar To: Shipra" << '\n'
              << "Fare: " << Charges << '\n';
      // outfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n';

      QString d = QString::number(Distance);
      ui->distanceop->setPlainText(d);
      QString f = QString::number(Charges);
      ui->fareop->setPlainText(f);
      out << "**********" << '\n';
      out << "Name: " << Name << '\n'
          << "From: Damodar To: Shipra" << '\n'
          << "Fare: " << Charges << '\n';
      out << "**********" << '\n';
      payfile.flush();
      payfile.close();
      MyFile.flush();
      MyFile.close();
   }
   else
   {
      QMessageBox::information(this, "Fill", "Please enter the name and destination");
   }
}

void bookingdestopt::on_pushbutton_pay_clicked()
{
   payment_confirmation = new PaymentConfirmation(this);
   payment_confirmation->show();

   close();
}
