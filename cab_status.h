#ifndef CAB_STATUS_H
#define CAB_STATUS_H

#include <QDialog>

namespace Ui {
class Cab_status;
}

class Cab_status : public QDialog
{
    Q_OBJECT

public:
    explicit Cab_status(QWidget *parent = nullptr);
    ~Cab_status();

private:
    Ui::Cab_status *ui;
};

#endif // CAB_STATUS_H
