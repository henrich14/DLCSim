#ifndef TIMESYNCDIALOG_H
#define TIMESYNCDIALOG_H

#include <QDialog>

namespace Ui {
class TimeSyncDialog;
}

class TimeSyncDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TimeSyncDialog(QWidget *parent = 0);
    ~TimeSyncDialog();
    
private:
    Ui::TimeSyncDialog *ui;

signals:
    void setTime_signal(const QString &timeValue);

private slots:
    void setTime_slot();
};

#endif // TIMESYNCDIALOG_H
