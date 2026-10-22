#pragma once

#include <QTextDocument>

class MarkdownDocument final : public QTextDocument
{
Q_OBJECT
public:
    MarkdownDocument(QObject* pobj = nullptr);
    MarkdownDocument(const QString& markdown, QObject* pobj = nullptr);

    MarkdownDocument(const MarkdownDocument& mdoc);
    MarkdownDocument(MarkdownDocument&& mdoc) noexcept;

    MarkdownDocument& operator=(const MarkdownDocument& mdoc);
    MarkdownDocument& operator=(MarkdownDocument&& mdoc) noexcept;

    ~MarkdownDocument();

    void    setMarkdownText(const QString& str);
    QString markdownText();
    void    clear();
};