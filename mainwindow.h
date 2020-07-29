#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "getnameform.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>
#include "eventmembers.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_event_triggered();
    bool CreateEvent();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_actionDelete_event_triggered();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_pay_clicked();

private:
    Ui::MainWindow *ui;
    GetNameForm *NameForm = new GetNameForm();
    QMap<QString,EventMembers*> list;  
    double GetTotalPrice(QMap<QString,double>);
protected:
};
#endif // MAINWINDOW_H
