#pragma once

#include <QWidget>

class QLineEdit;

namespace Presentation
{

/** Provides actions and filtering for the filesystem navigation panel. */
class FileSystemToolbar final : public QWidget
{
    Q_OBJECT

public:
    explicit FileSystemToolbar(QWidget* parent = nullptr);

    QLineEdit* filterEdit() const;

signals:
    void refreshRequested();
};

} // namespace Presentation
