#ifndef EVENTINFO_H
#define EVENTINFO_H
#include <QMap>
#include <QMainWindow>
#include <QTableWidget>
namespace Ui {
class EventInfo;
}

class EventInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit EventInfo(QWidget *parent = nullptr);
    EventInfo()
    {

    }
    ~EventInfo();

private:
    Ui::EventInfo *ui;
};

#endif // EVENTINFO_H
