#include "getnameform.h"
#include "ui_getnameform.h"

GetNameForm::GetNameForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GetNameForm)
{
    ui->setupUi(this);
}

GetNameForm::~GetNameForm()
{
    delete ui;
}

QString GetNameForm::GetName()
{
  return  ui->lineEdit->text();
}

void GetNameForm::on_pushButton_clicked()
{
    Name = ui->lineEdit->text();
    price = ui->lineEdit_2->text().toDouble();
    CloseEvent();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    this->close();
}
