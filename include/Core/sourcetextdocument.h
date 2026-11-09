#pragma once

#include <QTextDocument>

namespace Core
{

class SourceTextDocument final : public QTextDocument
{
    Q_OBJECT

public:
    explicit SourceTextDocument(QObject* parent = nullptr);
    explicit SourceTextDocument(const QString& sourceText, QObject* parent = nullptr);

    SourceTextDocument(const SourceTextDocument&) = delete;
    SourceTextDocument(SourceTextDocument&&) = delete;
    SourceTextDocument& operator=(const SourceTextDocument&) = delete;
    SourceTextDocument& operator=(SourceTextDocument&&) = delete;

    ~SourceTextDocument() override;

    QString sourceText() const;
    void setSourceText(const QString& sourceText);
};

} // namespace Core
