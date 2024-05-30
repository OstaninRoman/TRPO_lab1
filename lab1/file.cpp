#include "file.h"

File::File(const QString Path)
{
    this->path = Path;
    QFileInfo f(path);
    exists = f.exists();
    size = (int)f.size();
}

void File::updateState()
{
    QFileInfo f(path);
    bool ex = f.exists();
    int tempSize = (int)f.size();
    if(ex != exists || tempSize != size)
    {
        exists = ex;
        size = tempSize;
        emit change(this);
    }
}
