#include "Application/markdowneditorsession.h"

#include "Core/markdowndocument.h"
#include "Presentation/mainwindow.h"
#include <QTextEdit>

namespace Application {

MarkdownEditorSession::MarkdownEditorSession() = default;

bool MarkdownEditorSession::createSession()
{
	m_markdownDocument = new Core::MarkdownDocument("# Hello, Markdown Editor!", this);
	return true;
}

void MarkdownEditorSession::showSession()
{
	m_mainWindow = new Presentation::MainWindow();

    auto* pText = new QTextEdit(m_mainWindow);
    pText->setDocument(m_markdownDocument);

    m_mainWindow->show();
}

} // namespace Application
