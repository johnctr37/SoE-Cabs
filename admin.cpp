// johann
#include "admin.h"
#include "ui_admin.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "QPixmap"

Admin::Admin(QWidget *parent) : QDialog(parent),
                                ui(new Ui::Admin)
{
   ui->setupUi(this);
   QPixmap pic(":/resources/img/admin.jpg");
   ui->label_admin->setPixmap(pic.scaled(500, 470));
}

Admin::~Admin()
{
   delete ui;
}

void Admin::on_pushButton_admin_login_clicked()
{
   QString username = ui->lineEdit_admin_username->text();
   QString password = ui->lineEdit_admin_password->text();

   if (username == "admin" && password == "admin")
   {
      hide();
      admin_services = new Admin_services(this);
      admin_services->show();
      // QMessageBox::about(this,"Status","Logged in");
   }
   else
   {
      QMessageBox::about(this, "Status", "Wrong credentials");
   }
}

void Admin::on_pushButton_admin_back_clicked()
{
   close();
   MainWindow *w;
   w = new MainWindow(this);
   w->show();
}
