#include "Core/markdowndocument.h"

namespace Core
{

MarkdownDocument::MarkdownDocument(QObject* pobj) : QTextDocument(pobj)
{
    QTextDocument::setMarkdown("", MarkdownFeature::MarkdownDialectGitHub);
}

MarkdownDocument::MarkdownDocument(const QString& str, QObject* pobj) : QTextDocument(pobj)
{
    QTextDocument::setMarkdown(str, MarkdownFeature::MarkdownDialectGitHub);
}

MarkdownDocument::MarkdownDocument(const MarkdownDocument& mdoc) {
    QTextDocument::setMarkdown(mdoc.toMarkdown(MarkdownFeature::MarkdownDialectGitHub), MarkdownFeature::MarkdownDialectGitHub);
}

MarkdownDocument::MarkdownDocument(MarkdownDocument&& mdoc) noexcept {
    QTextDocument::setMarkdown(mdoc.toMarkdown(MarkdownFeature::MarkdownDialectGitHub), MarkdownFeature::MarkdownDialectGitHub);
    mdoc.clear();
}

MarkdownDocument& MarkdownDocument::operator=(const MarkdownDocument& mdoc) {
    QTextDocument::setMarkdown(mdoc.toMarkdown(MarkdownFeature::MarkdownDialectGitHub), MarkdownFeature::MarkdownDialectGitHub);
    return *this;
}

MarkdownDocument& MarkdownDocument::operator=(MarkdownDocument&& mdoc) noexcept {
    QTextDocument::setMarkdown(mdoc.toMarkdown(MarkdownFeature::MarkdownDialectGitHub), MarkdownFeature::MarkdownDialectGitHub);
    mdoc.clear();
    return *this;
}

MarkdownDocument::~MarkdownDocument() = default;

void MarkdownDocument::setMarkdownText(const QString& str) {
    QTextDocument::setMarkdown(str, MarkdownFeature::MarkdownDialectGitHub);
}

QString MarkdownDocument::markdownText() const {
    return QTextDocument::toMarkdown(MarkdownFeature::MarkdownDialectGitHub);
}

void MarkdownDocument::clear() {
    this->setMarkdownText("");
}

QTextDocument* MarkdownDocument::document() {
    return this;
}

const QTextDocument* MarkdownDocument::document() const {
    return this;
}

} // namespace Core