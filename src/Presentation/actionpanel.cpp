#include "Presentation/actionpanel.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSize>
#include <QStyle>
#include <QVBoxLayout>

namespace Presentation
{

ActionPanel::ActionPanel(QWidget* parent)
    : QWidget(parent)
{
    auto* layout = new QVBoxLayout(this);
    auto* actionsLayout = new QHBoxLayout;

    const auto buttonWidth = 40;
    const auto buttonHeight = 32;
    const auto iconSize = 24;
    const auto iconFor = [this](const QString& name, QStyle::StandardPixmap fallback) {
        const auto icon = QIcon::fromTheme(name);
        return icon.isNull() ? style()->standardIcon(fallback) : icon;
    };
    const auto addButton = [this, actionsLayout, buttonWidth, buttonHeight, iconSize](
                               const QIcon& icon, const QString& toolTip) {
        auto* button = new QPushButton(icon, QString(), this);
        button->setFixedSize(buttonWidth, buttonHeight);
        button->setIconSize(QSize(iconSize, iconSize));
        button->setFlat(true);
        button->setToolTip(toolTip);
        actionsLayout->addWidget(button);
    };

    addButton(iconFor("text-x-generic", QStyle::SP_FileIcon), "Дерево файлов");

    addButton(iconFor("clock", QStyle::SP_FileDialogContentsView), "Недавние");

    addButton(iconFor("settings", QStyle::SP_FileDialogDetailedView), "Настройки");

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

QLineEdit* ActionPanel::filterEdit() const
{
    return findChild<QLineEdit*>();
}

} // namespace Presentation
