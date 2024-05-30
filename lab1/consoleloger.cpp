#include "consoleloger.h"
#include <iostream>

void ConsoleLoger::Write(const QString message)
{
    QTextStream out(stdout);
    out << message << Qt::endl;
}
