#pragma once

#include <QWidget>

class QLineEdit;

namespace Presentation
{

/** Provides actions and filtering for the filesystem navigation panel. */
class ActionPanel final : public QWidget
{
    Q_OBJECT

public:
    explicit ActionPanel(QWidget* parent = nullptr);

    QLineEdit* filterEdit() const;

};

} // namespace Presentation
