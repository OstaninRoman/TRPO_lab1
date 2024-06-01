#include <QCoreApplication>
#include "filemanager.h"
#include "consoleloger.h"
#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ILoger* l = new ConsoleLoger;

    Q_ASSERT_X(l != nullptr, "main.cpp", "Logger not initilize");

    std::cout << "Enter file(s) path(s), then enter end " << std::endl;
    QTextStream in(stdin);
    QVector<QString> paths;
    QString str;
    while(str != "end"){
        str = "";
        in >> str;
        paths.push_back(str);
    }
    if(!paths.isEmpty())
        paths.removeLast();

    FileManager::Instance(l);

    for(QString path : paths)
        FileManager::Instance(l).addFile(path);

    FileManager::Instance(l).FileState();

    while(true){
        FileManager::Instance(l).updateFileState();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
