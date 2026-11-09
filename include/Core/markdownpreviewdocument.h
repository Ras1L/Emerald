#pragma once

#include <QTextDocument>

namespace Core
{

class MarkdownPreviewDocument final : public QTextDocument
{
    Q_OBJECT

public:
    explicit MarkdownPreviewDocument(QObject* parent = nullptr);
    explicit MarkdownPreviewDocument(
        const QString& markdown,
        QObject* parent = nullptr
    );

    ~MarkdownPreviewDocument() override;
};

} // namespace Core