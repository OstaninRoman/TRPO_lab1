#ifndef CONSOLELOGER_H
#define CONSOLELOGER_H
#include "iloger.h"
#include <QDebug>

class ConsoleLoger:public ILoger
{
    Q_OBJECT
public:
    void Write(const QString) override;
};

#endif // CONSOLELOGER_H
