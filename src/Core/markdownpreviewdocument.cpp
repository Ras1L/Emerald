#include "Core/markdownpreviewdocument.h"

namespace Core
{

MarkdownPreviewDocument::MarkdownPreviewDocument(QObject* parent)
    : QTextDocument(parent)
{
    setMarkdown({}, MarkdownFeature::MarkdownDialectGitHub);
}

MarkdownPreviewDocument::MarkdownPreviewDocument(
    const QString& markdown,
    QObject* parent
)
    : QTextDocument(parent)
{
    setMarkdown(markdown, MarkdownFeature::MarkdownDialectGitHub);
}

MarkdownPreviewDocument::~MarkdownPreviewDocument() = default;

} // namespace Core