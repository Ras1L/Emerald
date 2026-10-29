#pragma once

#include <QMainWindow>

namespace Presentation
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    /** Creates the application's top-level menu. */
    void createMenuBar();

    /** Creates the standard editing toolbar. */
    void createToolBar();
};

} // namespace Presentation