#pragma once

#include <QTextDocument>

namespace Core
{

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
    QString markdownText() const;
    void    clear();

    QTextDocument* document();
    const QTextDocument* document() const;

    void setHtml(const QString&) = delete;
    QString toHtml() = delete;

    void setPlainText(const QString&) = delete;
    QString toPlainText() = delete;
};

} // namespace Core