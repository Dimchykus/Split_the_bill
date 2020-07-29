#ifndef EVENTMEMBERS_H
#define EVENTMEMBERS_H
#include <QMap>
#include <QTableWidget>

class EventMembers
{
public:
    EventMembers();
    QMap<QString,double> members;
    double Price = -1;
    //friend bool operator<<(QTableWidget table,EventInfo *obj);
    friend EventMembers* operator<< ( QTableWidget *table,EventMembers obj);
};

#endif // EVENTMEMBERS_H
