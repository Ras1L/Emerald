#include "Infrastructure/filesystemmodel.h"

namespace Infrastructure
{

FileSystemModel::FileSystemModel(QObject* parent)
    : QFileSystemModel(parent)
{
}

int FileSystemModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent); // certainly unused
    return 1; // only show the name column in the filesystem view
}

} // namespace Infrastructure