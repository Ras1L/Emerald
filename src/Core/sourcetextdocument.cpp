#include "Core/sourcetextdocument.h"

namespace Core
{

SourceTextDocument::SourceTextDocument(QObject* parent)
    : QTextDocument(parent)
{
}

SourceTextDocument::SourceTextDocument(const QString& sourceText, QObject* parent)
    : QTextDocument(parent)
{
    setSourceText(sourceText);
}

SourceTextDocument::~SourceTextDocument() = default;

QString SourceTextDocument::sourceText() const
{
    return toPlainText();
}

void SourceTextDocument::setSourceText(const QString& sourceText)
{
    setPlainText(sourceText);
}

} // namespace Core
