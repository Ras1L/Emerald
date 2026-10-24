#include "Presentation/markdowndocumentlayout.h"

namespace Presentation
{

MarkdownDocumentLayout::MarkdownDocumentLayout(QTextDocument *document)
	: QAbstractTextDocumentLayout(document)
{
}

MarkdownDocumentLayout::~MarkdownDocumentLayout()
{
}

void MarkdownDocumentLayout::draw(QPainter *painter, const PaintContext &context)
{
}

int MarkdownDocumentLayout::hitTest(const QPointF &point, Qt::HitTestAccuracy accuracy) const
{
	return -1;
}

int MarkdownDocumentLayout::pageCount() const
{
	return 1;
}

QSizeF MarkdownDocumentLayout::documentSize() const
{
	return {};
}

QRectF MarkdownDocumentLayout::frameBoundingRect(QTextFrame *frame) const
{
	return {};
}

QRectF MarkdownDocumentLayout::blockBoundingRect(const QTextBlock &block) const
{
	return {};
}

void MarkdownDocumentLayout::documentChanged(int from, int charsRemoved, int charsAdded)
{
}

} // namespace Presentation
