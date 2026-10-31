#include "Application/markdowneditorsession.h"

#include "Core/markdowndocument.h"
#include "Infrastructure/filesystemmodel.h"
#include "Presentation/actionpanel.h"
#include "Presentation/filesystemview.h"
#include "Presentation/markdowneditor.h"
#include "Presentation/mainwindow.h"

#include <QDir>
#include <QLineEdit>
#include <QSplitter>
#include <QVBoxLayout>

namespace Application {

MarkdownEditorSession::MarkdownEditorSession() = default;

MarkdownEditorSession::~MarkdownEditorSession() = default;

bool MarkdownEditorSession::createSession()
{
	m_markdownDocument = new Core::MarkdownDocument("# Hello, Markdown Editor!", this);
	m_mainWindow = new Presentation::MainWindow();

	auto* splitter = new QSplitter(Qt::Horizontal, m_mainWindow);
	auto* fileSystemPanel = new QWidget(splitter);
	auto* fileSystemLayout = new QVBoxLayout(fileSystemPanel);
	auto* actionPanel = new Presentation::ActionPanel(fileSystemPanel);
	auto* fileSystemModel = new Infrastructure::FileSystemModel(m_mainWindow);
	auto* fileSystemView = new Presentation::FileSystemView(fileSystemPanel);

	const auto rootPath = QDir::currentPath();
	fileSystemModel->setRootPath(rootPath);
	fileSystemView->setModel(fileSystemModel);
	fileSystemView->setRootIndex(fileSystemModel->index(rootPath));
	fileSystemView->setColumnWidth(0, 200);

	connect(actionPanel->filterEdit(), &QLineEdit::textChanged,
	        fileSystemModel, [fileSystemModel](const QString& text) {
	            fileSystemModel->setNameFilters(text.isEmpty()
                                                ? QStringList{"*"}
                                                : QStringList{"*" + text + "*"});
	            fileSystemModel->setNameFilterDisables(false);
	        });
	fileSystemLayout->setContentsMargins(0, 0, 0, 0);
	fileSystemLayout->setSpacing(0);
	fileSystemLayout->addWidget(actionPanel);
	fileSystemLayout->addWidget(fileSystemView);

	auto* markdownEditor = new Presentation::MarkdownEditor(splitter);
	markdownEditor->setDocument(m_markdownDocument);
	splitter->addWidget(fileSystemPanel);
	splitter->addWidget(markdownEditor);
	splitter->setSizes({320, 1088});
	m_mainWindow->setCentralWidget(splitter);
	return true;
}

void MarkdownEditorSession::showSession()
{
	m_mainWindow->show();
}

} // namespace Application
