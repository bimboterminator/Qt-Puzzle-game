#ifndef PUZZLEPIECE_H
#define PUZZLEPIECE_H

#include<QGraphicsPathItem>
#include<QPainterPath>
#include<QPainter>
#include<QSet>
#include<QPoint>
#include<QMessageBox>

class PuzzlePiece : public QGraphicsPathItem
{

public:
    enum ConnectorPosition { None, Out, In };
    enum Direction { North, East, South, West };
    PuzzlePiece(ConnectorPosition north, ConnectorPosition east,
                ConnectorPosition south, ConnectorPosition west);
    void setPixmap(QPixmap px);
    QPoint getPos();
    void setCoordinates(QPoint pos);
    void link(PuzzlePiece* mate, Direction side);
    void Parentscene(QGraphicsScene* scene);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
    QPoint  coordinates;
    int pieceSize;
    QPixmap pixmap;
    ConnectorPosition connect[4];
    PuzzlePiece* m_neighbours[4];
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void drawProfile(QPainterPath &pp);
    void checkNeighbors(QSet<QPoint> &checked);
    void findNeighbour(Direction dir);
    QGraphicsScene* field;
};

#endif // PUZZLEPIECE_H
