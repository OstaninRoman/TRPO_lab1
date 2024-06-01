#ifndef ILOGER_H
#define ILOGER_H
#include <QObject>


class ILoger: public QObject
{
    Q_OBJECT
public:
    virtual void Write(const QString)=0;
};

#endif // ILOGER_H
