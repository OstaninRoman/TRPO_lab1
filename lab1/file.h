#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QFileInfo>

class File:public QObject
{
    Q_OBJECT
private:
    bool exists;
    int size;
    QString path;
public:
    File(const QString);
    void updateState();
    bool getExists(){return exists;}
    int getSize(){return size;}
    QString getPath() const {return path;}
signals:
    void change(File*);
};
#endif // FILE_H
