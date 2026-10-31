#include "Application/markdowneditorsession.h"

#include "Core/markdowndocument.h"
#include "Infrastructure/filesystemmodel.h"
#include "Presentation/editorworkspace.h"
#include "Presentation/markdowneditor.h"
#include "Presentation/mainwindow.h"
#include "Presentation/navigationworkspace.h"

#include <QDir>
#include <QSplitter>

namespace Application
{

MarkdownEditorSession::MarkdownEditorSession() = default;

MarkdownEditorSession::~MarkdownEditorSession() = default;

bool MarkdownEditorSession::createSession()
{
	m_markdownDocument = new Core::MarkdownDocument("# Hello, Markdown Editor!", this);
	m_mainWindow = new Presentation::MainWindow();

	auto* splitter = new QSplitter(Qt::Horizontal, m_mainWindow);

	auto* fileSystemModel = new Infrastructure::FileSystemModel(m_mainWindow);
	auto* navigationWorkspace =
	    new Presentation::NavigationWorkspace(fileSystemModel, splitter);
	const auto rootPath = QDir::currentPath();
	navigationWorkspace->setRootPath(rootPath);

	auto* editorWorkspace = new Presentation::EditorWorkspace(splitter);
	editorWorkspace->editor()->setDocument(m_markdownDocument);

	splitter->addWidget(navigationWorkspace);
	splitter->addWidget(editorWorkspace);
	splitter->setSizes({320, 1088});
	m_mainWindow->setCentralWidget(splitter);
	
	return true;
}

void MarkdownEditorSession::showSession()
{
	m_mainWindow->show();
}

} // namespace Application
