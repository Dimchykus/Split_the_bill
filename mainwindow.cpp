#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventmembers.h"
#include <QMap>
#include <QDebug>
#include <QMessageBox>
#include <time.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(NameForm,SIGNAL(CloseEvent()),this,SLOT(CreateEvent()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_event_triggered()
{
    NameForm->show();

}

bool MainWindow::CreateEvent()
{
     QMap<QString,EventMembers*>::iterator it = list.begin();
     for(;it!=list.end();it++)
     {
         if(it.key() == NameForm->Name)
         {
             QMessageBox::critical(this,"Name Error","This name already exists. Pls change it");
             return false;
         }
     }
     ui->listWidget->addItem(NameForm->Name);

     list.insert(NameForm->Name,new EventMembers);
     list.find(NameForm->Name).value()->Price = NameForm->price;
     return true;
}

QString CurrentItem = nullptr;

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
CurrentItem = item->text();
QMap<QString,EventMembers*>::iterator it = list.find(item->text());

ui->lineEdit_price->setText(QString::number(it.value()->Price));
ui->lineEdit_Total_price->setText(QString::number(GetTotalPrice( it.value()->members)));
ui->tableWidget << *(it.value());


}

double MainWindow::GetTotalPrice(QMap<QString,double> event)
{
 double sum = 0;

  QMap<QString,double>::iterator it_member = event.begin();
 for(;it_member!=event.end();it_member++)
 {
     sum += it_member.value();
 }
 return sum;
}

void MainWindow::on_pushButton_add_clicked()
{
    if(CurrentItem == nullptr)
    {
        qDebug() << "Error";
        return;
    }
    QMap<QString,EventMembers*>::iterator it = list.find(CurrentItem);
    it.value()->members.insert(ui->lineEdit_add_name->text(),ui->lineEdit_add_price->text().toDouble());
    ui->tableWidget << *(it.value());
    ui->lineEdit_add_name->setText("");
    ui->lineEdit_add_price->setText("");


    ui->lineEdit_Total_price->setText(QString::number(GetTotalPrice( it.value()->members)));
}
int CurrentMember = -1;

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    CurrentMember = row;
     qDebug() << CurrentMember;
}

void MainWindow::on_pushButton_remove_clicked()
{


if(CurrentMember == -1)
{
    qDebug() << "Error2";
    return;
}
    QMap<QString,EventMembers*>::iterator it_event = list.find(CurrentItem);
    QMap<QString,double>::iterator it_members =  it_event.value()->members.begin();
  qDebug() << "Before loop";
    for (int i = 0;it_members != it_event.value()->members.end();i++,it_members++)
    {
        qDebug() << "Loop" << i;
        if(i == CurrentMember)
        {
            it_event.value()->members.erase(it_members);
             qDebug() << "Deleted";
            break;
        }
     }
      ui->tableWidget << *(list.find(CurrentItem).value());
        qDebug() << "Display";
//CurrentMember = -1;

}



void MainWindow::on_actionDelete_event_triggered()
{
    if(CurrentItem == nullptr)
    {
        qDebug() << "Error1";
        return;
    }
qDebug() <<  ui->listWidget->currentRow();
ui->listWidget->takeItem(ui->listWidget->currentRow());
     QMap<QString,EventMembers*>::iterator it_event = list.find(CurrentItem);
     list.erase(it_event);
}




void MainWindow::on_pushButton_pay_clicked()
{
    if(ui->radioButton_random->isChecked())
    {
        QMap<QString,EventMembers*>::iterator it_event = list.find(CurrentItem);
        QMap<QString,double>::iterator it_members =  it_event.value()->members.begin();
        srand(time(0));
        int num = rand()%it_event.value()->members.size();
        for (int i = 0;it_members != it_event.value()->members.end();i++,it_members++)
        {
            if(i == num)
            {
                break;
            }
         }
        QMessageBox::information(this,"Random person","Today will pay "+it_members.key());
    }
    else  if(ui->radioButton_equal->isChecked())
    {
       double price = ui->lineEdit_price->text().toDouble();
       QMap<QString,EventMembers*>::iterator it_event = list.find(CurrentItem);
       int count =  it_event.value()->members.size();
       int toPay = price / count;
        ui->label_pay_info->setText("Everyone should pay at least: "+QString::number(toPay)+"\n");
       QMap<QString,double>::iterator it_members =  it_event.value()->members.begin();
       QString list[] = {};
       ui->label_pay_info->setText(ui->label_pay_info->text() + "Info:" + "\n");
       int *i = new int;
       *i = 0;
       for (;it_members != it_event.value()->members.end();it_members++)
       {
          if(it_members.value() < toPay)
          {
             ui->label_pay_info->setText(ui->label_pay_info->text() +it_members.key() + " should give " + QString::number(toPay - it_members.value())+ " more"+"\n");
             (*i)++;
          }
       }
       if((*i)==0)
       {
             ui->label_pay_info->setText(ui->label_pay_info->text() +"No info"+"\n");
       }
        delete(i);
    }


}
