#pragma once

#include <QFileSystemModel>

namespace Infrastructure
{

/** Supplies filesystem data to the notes tree. */
class FileSystemModel final : public QFileSystemModel
{
    Q_OBJECT

public:
    explicit FileSystemModel(QObject* parent = nullptr);
};

} // namespace Infrastructure