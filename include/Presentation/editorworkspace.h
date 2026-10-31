#pragma once

#include <QWidget>

class QTabWidget;

namespace Presentation
{

class MarkdownEditor;

/** Provides the tabbed workspace for Markdown documents. */
class EditorWorkspace final : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWorkspace(QWidget* parent = nullptr);

    MarkdownEditor* editor() const;

private:
    QTabWidget* m_tabs = nullptr;
    MarkdownEditor* m_editor = nullptr;
};

} // namespace Presentation