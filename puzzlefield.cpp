#include "puzzlefield.h"
#include<QVector>
#include<QDebug>
PuzzleField::PuzzleField(QSize s, QPixmap newImage)
{
    fieldSize =s;
    int cellSize = 50;
    pixmap = newImage.scaled(cellSize*fieldSize.width(),cellSize*fieldSize.height());
    setup();
}

void PuzzleField::setup(){
    QGraphicsScene::clear();
    QVector<PuzzlePiece::ConnectorPosition> prev(fieldSize.width(),PuzzlePiece::None);
    PuzzlePiece::ConnectorPosition storedWest;


    QVector<QPoint> coordinates;
    for(int i=0;i<fieldSize.height();i++)
        for(int j=0;j<fieldSize.width();j++){
            coordinates.push_back(QPoint(i,j));
        }
    for(int i=fieldSize.width()*fieldSize.height()-1;i>0;i--){
        int j = qrand()%i;
        qSwap(coordinates[i],coordinates[j]);
    }


    for(int row=0;row < fieldSize.height();row++)
    {   storedWest = PuzzlePiece::None;
        for(int col=0;col<fieldSize.width();col++){
            QVector<PuzzlePiece::ConnectorPosition> curr(4,PuzzlePiece::None); // N,E,S,W
              curr[0] = reverse(prev[col]);
              curr[1] = qrand() % 2 ? PuzzlePiece::In : PuzzlePiece::Out;
              curr[2] = qrand() % 2 ? PuzzlePiece::In : PuzzlePiece::Out;
              curr[3] = reverse(storedWest);
              if(col==fieldSize.width()-1)curr[1] = PuzzlePiece::None;
              if(row==fieldSize.height()-1){ curr[2] = PuzzlePiece::None;}

              PuzzlePiece *piece = new PuzzlePiece(curr[0], curr[1], curr[2], curr[3]);
              addItem(piece);
              piece->setFlag(QGraphicsItem::ItemIsMovable);
              piece->setPos(coordinates.takeFirst()*55);
             // piece->setPos(col*50,row*50);
              imgCut(piece,row,col);
              piece->setCoordinates(QPoint(col,row));
              piece->Parentscene(this);
               storedWest = curr[1];
               prev[col] = curr[2];
             }

    }

}

void PuzzleField::imgCut(PuzzlePiece *piece,int row,int col)
{
    QRect rect =  piece->boundingRect().toRect();
    int cellSize = 50;
    rect.translate(0.5*cellSize+col*cellSize, 0.5*cellSize+row*cellSize);
    QPixmap px = pixmap.copy(rect);
    piece->setPixmap(px);
}


PuzzlePiece::ConnectorPosition PuzzleField::reverse(PuzzlePiece::ConnectorPosition side)
{
    switch(side){
        case(PuzzlePiece::None): return PuzzlePiece::None;
        case(PuzzlePiece::In): return PuzzlePiece::Out;
        case(PuzzlePiece::Out): return PuzzlePiece::In;
    }
    return PuzzlePiece::None;
}


