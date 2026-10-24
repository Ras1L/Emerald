#pragma once

#include <QAbstractTextDocumentLayout>

namespace Presentation
{

class MarkdownDocumentLayout final : public QAbstractTextDocumentLayout
{
	Q_OBJECT

public:
	explicit MarkdownDocumentLayout(QTextDocument *document);
	~MarkdownDocumentLayout() override;

	void draw(QPainter *painter, const PaintContext &context) override;
	int hitTest(const QPointF &point,
				Qt::HitTestAccuracy accuracy) const override;
	int pageCount() const override;
	QSizeF documentSize() const override;
	QRectF frameBoundingRect(QTextFrame *frame) const override;
	QRectF blockBoundingRect(const QTextBlock &block) const override;

protected:
	void documentChanged(int from, int charsRemoved, int charsAdded) override;
};

} // namespace Presentation
