#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "file.h"
#include "consoleloger.h"
#include <QDir>

class FileManager:public QObject
{
    Q_OBJECT
private:
    QVector<File*> trackFiles;
    ILoger* loger;

    FileManager(ILoger*);
    ~FileManager();
    FileManager(const FileManager&);
    FileManager& operator=(const FileManager&);
public:
    static FileManager& Instance(ILoger* lg){
        static FileManager fm(lg);
        return fm;
    }
    void addFile(const QString);
    void deleteFile(const QString);
    void FileState();
    void updateFileState();
public slots:
    void filechange(File*);
};

#endif // FILEMANAGER_H
