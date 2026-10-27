#pragma once

#include <QTextEdit>

namespace Presentation
{

class MarkdownEditor : public QTextEdit
{
    Q_OBJECT

public:
    explicit MarkdownEditor(QWidget *parent = nullptr);
};

} // namespace Presentation