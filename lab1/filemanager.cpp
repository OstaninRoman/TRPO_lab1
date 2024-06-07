#include "filemanager.h"


FileManager::FileManager(ILoger* lg)
{
    loger = lg;
}

void FileManager::addFile(const QString path)
{
    for(File* file : trackFiles){
        QDir dir(file->getPath()), temp_dir(path);
        if(dir.absolutePath() == temp_dir.absolutePath()){
            if(loger)
                loger->Write(QString(QString("File with path: ") + file->getPath()) + QString(" already exists"));
            else
                qWarning("Logger not initialized");
            return;
        }
    }

    File* f = new File(path);

    if(loger)
        loger->Write(QString("File with path: ") + f->getPath() + QString(" added"));
    else
        qWarning("Logger not initialized");

    if(f){
        connect(f, &File::change, this, &FileManager::filechange);
        trackFiles.push_back(f);
    }
}

void FileManager::deleteFile(const QString path)
{
    File** f = trackFiles.begin();
    while(f != trackFiles.end()){
        if((*f)->getPath() == path){
            trackFiles.erase(f);
            break;
        }
    }
}

void FileManager::FileState()
{
    for(File* f : trackFiles){
        QString info = "";
        if(f->getExists()) {
            info += (QString("File with path: ") + f->getPath() + QString(" exists "));
            QString tempsize;
            tempsize.setNum(f->getSize());
            info += (QString("size " + tempsize + " b"));
        }else{
            info = QString("File with path: ") + f->getPath() + QString(" not exists ");
        }
        if(loger)
            loger->Write(info);
        else
            qWarning("Logger not initialized");
    }
}

void FileManager::updateFileState()
{
    for(File* f : trackFiles)
        f->updateState();
}

void FileManager::filechange(File* f)
{
    QString info = "";
    if(f->getExists()) {
        info += (QString("File with path: ") + f->getPath() + QString(" exists "));
        QString tempsize;
        tempsize.setNum(f->getSize());
        info += (QString("size " + tempsize + " b"));
    }else{
        info = QString("File with path: ") + f->getPath() + QString(" not exist");
    }
    if(loger)
        loger->Write(info);
    else
        qWarning("Logger not initialized");
}

FileManager::~FileManager()
{
    for(File* file : trackFiles){
        delete file;
        file = nullptr;
    }
}
