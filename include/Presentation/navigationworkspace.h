#pragma once

#include <QWidget>

class QString;

namespace Infrastructure
{
class FileSystemModel;
}

namespace Presentation
{

class ActionPanel;
class FileSystemView;

/** Provides navigation controls and the filesystem view for the main window. */
class NavigationWorkspace final : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationWorkspace(Infrastructure::FileSystemModel* model,
                                 QWidget* parent = nullptr);

    void setRootPath(const QString& path);

private:
    ActionPanel* m_actionPanel = nullptr;
    FileSystemView* m_fileSystemView = nullptr;
    Infrastructure::FileSystemModel* m_model = nullptr;
};

} // namespace Presentation
