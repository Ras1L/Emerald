#include "Presentation/filesystemtoolbar.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QStyle>
#include <QVBoxLayout>

namespace Presentation
{

FileSystemToolbar::FileSystemToolbar(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* actionsLayout = new QHBoxLayout;

    const auto buttonHeight = 32;
    const auto addButton = [this, actionsLayout, buttonHeight](const QIcon& icon,
                                                               const QString& text) {
        auto* button = new QPushButton(icon, text, this);
        button->setFixedHeight(buttonHeight);
        actionsLayout->addWidget(button);
    };

    addButton(style()->standardIcon(QStyle::SP_FileIcon), "Новый");

    auto* refreshButton = new QPushButton(style()->standardIcon(QStyle::SP_BrowserReload),
                                          "Обновить", this);
    refreshButton->setFixedHeight(buttonHeight);
    connect(refreshButton, &QPushButton::clicked, this, &FileSystemToolbar::refreshRequested);
    actionsLayout->addWidget(refreshButton);

    auto* settingsButton = new QPushButton(style()->standardIcon(QStyle::SP_FileDialogDetailedView),
                                           "Вид", this);
    settingsButton->setFixedHeight(buttonHeight);
    actionsLayout->addWidget(settingsButton);
    actionsLayout->addStretch();

    auto* edit = new QLineEdit(this);
    edit->setPlaceholderText("Фильтр...");
    edit->setFixedHeight(32);
    edit->setClearButtonEnabled(true);

    layout->setContentsMargins(8, 8, 8, 8);
    layout->setSpacing(8);
    layout->addLayout(actionsLayout);
    layout->addWidget(edit);
    setFixedHeight(96);
}

QLineEdit* FileSystemToolbar::filterEdit() const
{
    return findChild<QLineEdit*>();
}

} // namespace Presentation
