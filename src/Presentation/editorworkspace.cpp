#include "Presentation/editorworkspace.h"

#include "Presentation/markdowneditor.h"

#include <QHBoxLayout>
#include <QTabWidget>
#include <QVBoxLayout>

namespace Presentation
{

EditorWorkspace::EditorWorkspace(QWidget* parent)
    : QWidget(parent)
{
    m_tabs = new QTabWidget(this);

    auto* editorPage = new QWidget(m_tabs);
    auto* editorLayout = new QHBoxLayout(editorPage);
    m_editor = new MarkdownEditor(editorPage);
    m_editor->setMinimumWidth(700);

    editorLayout->setContentsMargins(0, 0, 0, 0);
    editorLayout->setSpacing(0);
    editorLayout->addStretch(3);
    editorLayout->addWidget(m_editor, 4);
    editorLayout->addStretch(3);

    m_tabs->addTab(editorPage, "Безымянный");

    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_tabs);
}

MarkdownEditor* EditorWorkspace::editor() const
{
    return m_editor;
}

} // namespace Presentation