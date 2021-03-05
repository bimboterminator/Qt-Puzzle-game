#include "puzzlesizewidget.h"
PuzzleSizeWidget::PuzzleSizeWidget(QWidget *parent)
{
    size = QSize(5,6);
    minimum = QSize(2,2);
    maximum = QSize(8,8);
}

void PuzzleSizeWidget::setValue(const QSize &s)
{
    if (size == s || size.height()<minimum.height() || size.height()>maximum.height()
            || (size.width() < minimum.width()) || (size.width()> maximum.width()))
        return;
    QSize old = size;
    size = s;
    emit valueChanged(s);
    if (old.width() != s.width())
        emit horizontalValueChanged(s.width());
    if (old.width() != s.height())
        emit verticalValueChanged(s.height());
    update();
}

void PuzzleSizeWidget::setMin(const QSize &s)
{
    if(minimum.height() == s.height() && (minimum.width()== s.width()))
        return;
    minimum = s;
    if (size.height() <minimum.height())
        size.setHeight(minimum.height());
    if (size.width() < minimum.width())
        size.setWidth(minimum.width());
}

void PuzzleSizeWidget::setMax(const QSize &s)
{
    if(maximum.height() == s.height() && (maximum.width()== s.width()))
        return;
    maximum = s;
    if (size.height() > maximum.height())
        size.setHeight(maximum.height());
    if (size.width() > maximum.width())
        size.setWidth(maximum.width());
}

void PuzzleSizeWidget::setPixmap(QString fileName)
{
    if(!fileName.isNull())
        pixmap.load(fileName);
   else
        return;
}

void PuzzleSizeWidget::mousePresEvent(QMouseEvent *event)
{
   if( (event->pos().x() < (maximum.width()*cellSize().width())) && event->pos().y()<maximum.height()*cellSize().height()){
       cursor_pos = event->pos();
       cellAt(cursor_pos);
   }
}

void PuzzleSizeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if( (event->pos().x() < (maximum.width()*cellSize().width())) && event->pos().y()<maximum.height()*cellSize().height()){
        cursor_pos = event->pos();
        cellAt(cursor_pos);
    }
}

void PuzzleSizeWidget::renderValue(QPainter *painter)
{
    QSize cell_size = cellSize();
    QSize sz(cell_size.width()*value().width(),cell_size.height()*value().height());

    if(!pixmap.isNull()){
        painter->drawPixmap(0,0,pixmap.scaled(sz));
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->drawRect(0,0,sz.width(),sz.height());
    }
}

void PuzzleSizeWidget::renderGrid(QPainter *painter)
{
    QSize cell_size = cellSize();
    painter->setBrush(Qt::NoBrush);
    for(int i=0;i< maximum.width();i++)
        for(int j=0;j< maximum.height();j++){
            painter->drawRect(i*cell_size.width(),j*cell_size.height(),
                              cell_size.width(),cell_size.height());
        }
}

void PuzzleSizeWidget::cellAt(QPoint p)
{
    int cellX = p.x()/cellSize().width();
    int cellY = p.y()/cellSize().height();

    QSize new_value;

    if(cellX < minimum.width() || cellY < minimum.height())
        new_value = minimum;
    else
        new_value = QSize(cellX+1,cellY+1);
    setValue(new_value);
}
QSize PuzzleSizeWidget::sizeHint() const{
    return QSize(400,400);
}

void PuzzleSizeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    renderValue(&painter);
    renderGrid(&painter);
}

QSize PuzzleSizeWidget::cellSize() const
{
    int w =width();
    int h = height();
    int mw = maximum.width();
    int mh = maximum.height();
    int extent = qMin(w/mw,h/mh);
    return QSize(extent,extent).expandedTo(QApplication::globalStrut()).expandedTo(QSize(4,4));
}

