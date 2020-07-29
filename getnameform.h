#ifndef GETNAMEFORM_H
#define GETNAMEFORM_H

#include <QMainWindow>

namespace Ui {
class GetNameForm;
}

class GetNameForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit GetNameForm(QWidget *parent = nullptr);
    ~GetNameForm();
    QString GetName();
    QString Name = nullptr;
    double price = -1;
private slots:
    void on_pushButton_clicked();

signals:
    bool CloseEvent();
private:
    Ui::GetNameForm *ui;

};

#endif // GETNAMEFORM_H
