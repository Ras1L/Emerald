#pragma once

#include <QTreeView>

namespace Presentation
{

/** Displays folders and Markdown files in the navigation panel. */
class FileSystemView final : public QTreeView
{
    Q_OBJECT

public:
    explicit FileSystemView(QWidget* parent = nullptr);
};

} // namespace Presentation
