#include "Application/markdowneditorsession.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Application::MarkdownEditorSession session;
    if (!session.createSession()) {
        return -1;
    }
    session.showSession();

    return QApplication::exec();
}
