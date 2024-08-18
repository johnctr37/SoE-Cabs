#include "cab_status.h"
#include "ui_cab_status.h"
#include "global.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>



Cab_status::Cab_status(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cab_status)
{
    ui->setupUi(this);
    QDir dir=QDir::current();
    QString filePath=dir.filePath("Cab_status.txt");
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    QMessageBox::warning(this,"Warning","File not open");
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

Cab_status::~Cab_status()
{
    delete ui;
}
