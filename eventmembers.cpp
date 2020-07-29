#include "eventmembers.h"

EventMembers::EventMembers()
{

}

EventMembers *operator<<(QTableWidget *table, EventMembers obj)
{

    QMap<QString,double>::iterator it = obj.members.begin();
table->setColumnCount(2);
table->setRowCount(obj.members.size());
    for(int i = 0;i<obj.members.size();i++)
    {
        table->setItem(i,0,new QTableWidgetItem);
        table->setItem(i,1,new QTableWidgetItem);
    }
   for(int i = 0;i<obj.members.size();i++,it++)
   {

        table->item(i,0)->setText(it.key());
        table->item(i,1)->setText(QString::number(it.value()));
   }
   return &obj;
}
