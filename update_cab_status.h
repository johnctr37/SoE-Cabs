#ifndef UPDATE_CAB_STATUS_H
#define UPDATE_CAB_STATUS_H

#include <QDialog>

namespace Ui {
class Update_cab_status;
}

class Update_cab_status : public QDialog
{
    Q_OBJECT

public:
    explicit Update_cab_status(QWidget *parent = nullptr);
    ~Update_cab_status();

private slots:
    void on_pushButton_proceed_clicked();

    void on_pushButton_submit_clicked();

    void on_pushButton_ucs_back_clicked();

private:
    Ui::Update_cab_status *ui;
};

#endif // UPDATE_CAB_STATUS_H
