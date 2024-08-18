#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "admin_services.h"

namespace Ui
{
   class Admin;
}

class Admin : public QDialog
{
   Q_OBJECT

public:
   explicit Admin(QWidget *parent = nullptr);
   ~Admin();

private slots:
   void on_pushButton_admin_login_clicked();

   void on_pushButton_admin_back_clicked();

private:
   Ui::Admin *ui;
   Admin_services *admin_services;
};

#endif // ADMIN_H
