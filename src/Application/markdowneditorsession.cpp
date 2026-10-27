#include "Application/markdowneditorsession.h"

#include "Core/markdowndocument.h"
#include "Presentation/markdowneditor.h"
#include "Presentation/mainwindow.h"

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

	auto* markdownEditor = new Presentation::MarkdownEditor(m_mainWindow);
	markdownEditor->setDocument(m_markdownDocument);

    m_mainWindow->show();
}

} // namespace Application
