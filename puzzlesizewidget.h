#ifndef PUZZLESIZEWIDGET_H
#define PUZZLESIZEWIDGET_H

#include <QFrame>
#include <QObject>
#include<QFrame>
#include<QPainter>
#include<QApplication>
#include<QSize>
#include<QPaintEvent>
#include <QPoint>
#include <QMouseEvent>
class PuzzleSizeWidget : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QSize value READ value WRITE setValue)

public:
    PuzzleSizeWidget(QWidget *parent=0);
    QSize sizeHint() const;
    QSize value() const
    {
        return size;
    }
    void paintEvent(QPaintEvent *event);
    QSize cellSize() const;
public slots:
    void setValue(const QSize &s);
    void setMin(const QSize &s);
    void setMax(const QSize &s);
    void setPixmap(QString fileName);
    void mousePresEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
signals:
    void valueChanged(const QSize&);
    void horizontalValueChanged(int);
    void verticalValueChanged(int);

private:
    QSize size;
    QSize minimum;
    QSize maximum;
    QPixmap pixmap;
    QPoint cursor_pos;

    void renderValue(QPainter *painter);
    void renderGrid(QPainter *painter);
    void cellAt(QPoint p );
};

#endif // PUZZLESIZEWIDGET_H
