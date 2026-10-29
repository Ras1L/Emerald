#include "Presentation/mainwindow.h"

#include <QMenuBar>
#include <QStyle>
#include <QToolBar>

namespace Presentation
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Emerald");
    resize(1280, 800);
    createMenuBar();
    createToolBar();
}

MainWindow::~MainWindow() = default;

void MainWindow::createMenuBar()
{
    auto* fileMenu = menuBar()->addMenu("Файл");
    fileMenu->addAction("Новый файл");
    fileMenu->addSeparator();
    fileMenu->addAction("Выход", this, &QWidget::close);

    auto* editMenu = menuBar()->addMenu("Правка");
    editMenu->addAction("Отменить");
    editMenu->addAction("Повторить");
    menuBar()->addMenu("Вид");
    menuBar()->addMenu("Инструменты");
    menuBar()->addMenu("Справка");
}

void MainWindow::createToolBar()
{
    auto* toolBar = addToolBar("Основные действия");
    toolBar->setMovable(false);
    toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    toolBar->addAction(style()->standardIcon(QStyle::SP_FileIcon), "Новый файл");
    toolBar->addAction(style()->standardIcon(QStyle::SP_DialogSaveButton), "Сохранить");
    toolBar->addSeparator();
    toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowBack), "Отменить");
    toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowForward), "Повторить");
}

} // namespace Presentation
