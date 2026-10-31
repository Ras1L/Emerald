#include "Presentation/navigationworkspace.h"

#include "Infrastructure/filesystemmodel.h"
#include "Presentation/actionpanel.h"
#include "Presentation/filesystemview.h"

#include <QLineEdit>
#include <QStringList>
#include <QVBoxLayout>

namespace Presentation
{

NavigationWorkspace::NavigationWorkspace(Infrastructure::FileSystemModel* model,
                                         QWidget* parent)
    : QWidget(parent)
    , m_actionPanel(new ActionPanel(this))
    , m_fileSystemView(new FileSystemView(this))
    , m_model(model)
{
    m_fileSystemView->setModel(m_model);
    m_fileSystemView->setColumnWidth(0, 200);

    connect(m_actionPanel->filterEdit(), &QLineEdit::textChanged,
            m_model, [this](const QString& text) {
                m_model->setNameFilters(text.isEmpty()
                                            ? QStringList{"*"}
                                            : QStringList{"*" + text + "*"});
                m_model->setNameFilterDisables(false);
            });

    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_actionPanel);
    layout->addWidget(m_fileSystemView);
}

void NavigationWorkspace::setRootPath(const QString& path)
{
    m_model->setRootPath(path);
    m_fileSystemView->setRootIndex(m_model->index(path));
}

} // namespace Presentation
