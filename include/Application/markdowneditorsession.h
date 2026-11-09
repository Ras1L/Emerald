#pragma once

#include <QObject>
#include <memory>

namespace Core         { class SourceTextDocument; }
namespace Presentation { class MainWindow; }

namespace Application
{

class MarkdownEditorSession : public QObject {
    Q_OBJECT

public:
	MarkdownEditorSession();
	~MarkdownEditorSession() override;

	bool createSession();
    void showSession();

private:
	Core::SourceTextDocument* m_sourceDocument = nullptr;
	Presentation::MainWindow* m_mainWindow 	   = nullptr;
};

} // namespace Application
