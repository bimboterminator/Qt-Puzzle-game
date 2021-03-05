#ifndef PUZZLEFIELD_H
#define PUZZLEFIELD_H

#include <QGraphicsScene>
#include"puzzlepiece.h"
#include<QPixmap>

class PuzzleField : public QGraphicsScene
{
    Q_OBJECT
public:
    PuzzleField(QSize s, QPixmap newImage);
private:
    QSize fieldSize;
    QPixmap pixmap;
    void setup();
    void imgCut(PuzzlePiece* piece,int row,int col);
    PuzzlePiece::ConnectorPosition reverse(PuzzlePiece::ConnectorPosition side);
};

#endif // PUZZLEFIELD_H
