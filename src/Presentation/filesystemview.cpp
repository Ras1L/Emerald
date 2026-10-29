#include "Presentation/filesystemview.h"

namespace Presentation
{

FileSystemView::FileSystemView(QWidget* parent)
    : QTreeView(parent)
{
    setHeaderHidden(true);
    setAnimated(true);
    setUniformRowHeights(true);
    setFrameShape(QFrame::NoFrame);
}

} // namespace Presentation
