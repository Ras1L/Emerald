#pragma once

#include <QObject>

namespace Core         { class MarkdownDocument; }
namespace Presentation { class MainWindow; }

namespace Application
{

class MarkdownEditorSession : public QObject {
    Q_OBJECT

public:
	MarkdownEditorSession();

	bool createSession();
    void showSession();

private:
	Core::MarkdownDocument*   m_markdownDocument = nullptr;
	Presentation::MainWindow* m_mainWindow = nullptr;
};

} // namespace Application
