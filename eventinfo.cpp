#include "eventinfo.h"
#include "ui_eventinfo.h"
#include <QTableWidgetItem>
EventInfo::EventInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EventInfo)
{
    ui->setupUi(this);


EventInfo::~EventInfo()
{
    delete ui;
}

