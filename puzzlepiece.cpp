#include "puzzlepiece.h"
#include <QPainter>
#include<QGraphicsScene>
#include<QDebug>
PuzzlePiece::PuzzlePiece(ConnectorPosition north, ConnectorPosition east,
                            ConnectorPosition south, ConnectorPosition west){

       pieceSize = 50;
       connect[0] = north;
       connect[1] = east;
       connect[2] = south;
       connect[3] = west;
       m_neighbours[0] = nullptr; //N
       m_neighbours[1] = nullptr;//E
       m_neighbours[2] = nullptr;//S
       m_neighbours[3] = nullptr;//W
       QPainterPath tr;
       drawProfile(tr);
       setPath(tr);
   }

 void PuzzlePiece::drawProfile(QPainterPath &trace){
    trace.moveTo(-pieceSize / 2, -pieceSize / 2);
    if(connect[0] == None){
           trace.lineTo(pieceSize / 2, -pieceSize / 2);
    }
    else if(connect[0] == Out){
            trace.lineTo(-pieceSize / 16, -pieceSize / 2);
            trace.arcTo(-pieceSize / 8, -pieceSize / 2 -pieceSize / 8,
                     pieceSize / 8, pieceSize / 8, 270, -90.0); //первая дуга поворот на 90
            trace.arcTo(-pieceSize / 8, -pieceSize / 2 -pieceSize / 8 -pieceSize / 16,
                     pieceSize / 4, pieceSize / 4, 180, -180.0); // основная поворот на 180
            trace.arcTo(0, -pieceSize / 2 -pieceSize / 8,
                     pieceSize / 8, pieceSize / 8, 0, -90.0);
            trace.lineTo(pieceSize / 2, -pieceSize / 2); // зверщающая поворот на 90
    }
    else if(connect[0] == In){
            trace.lineTo(-pieceSize / 16, -pieceSize / 2);
            trace.arcTo(-pieceSize / 8, -pieceSize / 2,
                     pieceSize / 8, pieceSize / 8, 90, 90.0);
            trace.arcTo(-pieceSize / 8, -pieceSize / 2 -pieceSize / 16,
                     pieceSize / 4, pieceSize / 4, 180, 180.0);
            trace.arcTo(0, -pieceSize / 2,
                     pieceSize / 8, pieceSize / 8, 0, 90.0);
            trace.lineTo(pieceSize / 2, -pieceSize / 2);
    }
    if(connect[1] == None){
           trace.lineTo(pieceSize / 2, pieceSize / 2);
    }
    else if(connect[1] == Out){
        trace.lineTo(pieceSize / 2 , -pieceSize / 16);
        trace.arcTo(pieceSize / 2, -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 180, -90.0);
        trace.arcTo(pieceSize / 2 -pieceSize / 16, -pieceSize / 8,
                 pieceSize / 4, pieceSize / 4, 90, -180.0);
        trace.arcTo(pieceSize / 2, 0,
                 pieceSize / 8, pieceSize / 8, 270, -90.0);
        trace.lineTo(pieceSize / 2, pieceSize / 2);
    }
    else if(connect[1] == In){
        trace.lineTo(pieceSize / 2 , -pieceSize / 16);
        trace.arcTo(pieceSize / 2 -pieceSize / 8, -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 0, 90.0);
        trace.arcTo(pieceSize / 2 -pieceSize / 8 -pieceSize / 16, -pieceSize / 8,
                 pieceSize / 4, pieceSize / 4, 90, 180.0);
        trace.arcTo(pieceSize / 2 -pieceSize / 8, 0,
                 pieceSize / 8, pieceSize / 8, 270, 90.0);
        trace.lineTo(pieceSize / 2, pieceSize / 2);
    }

    if(connect[2] == None){
           trace.lineTo(-pieceSize / 2, pieceSize / 2);
    }
    else if(connect[2] == Out){
        trace.lineTo(pieceSize / 16, pieceSize / 2);
        trace.arcTo(0, pieceSize / 2,
                 pieceSize / 8, pieceSize / 8, 90, -90.0);
        trace.arcTo(-pieceSize / 8, pieceSize / 2 -pieceSize / 16,
                 pieceSize / 4, pieceSize / 4, 0, -180.0);
        trace.arcTo(-pieceSize / 8, pieceSize / 2,
                 pieceSize / 8, pieceSize / 8, 180, -90.0);
        trace.lineTo(-pieceSize / 2, pieceSize / 2);
    }
    else if(connect[2] == In){
        trace.lineTo(pieceSize / 16, pieceSize / 2);
        trace.arcTo(0, pieceSize / 2 -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 270, 90.0);
        trace.arcTo(-pieceSize / 8, pieceSize / 2 -pieceSize / 8 -pieceSize / 16,
                 pieceSize / 4, pieceSize / 4, 0, 180.0);
        trace.arcTo(-pieceSize / 8, pieceSize / 2 -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 180, 90.0);
        trace.lineTo(-pieceSize / 2, pieceSize / 2);
    }

    if(connect[3] == None){
           trace.lineTo(-pieceSize / 2, -pieceSize / 2);
    }
    else if(connect[3] == Out){
        trace.lineTo(-pieceSize / 2 , pieceSize / 16);
        trace.arcTo(-pieceSize / 2 -pieceSize / 8, 0,
                 pieceSize / 8, pieceSize / 8, 0, -90.0);
        trace.arcTo(-pieceSize / 2 -pieceSize / 8 -pieceSize / 16, -pieceSize / 8,
                 pieceSize / 4, pieceSize / 4, 270, -180.0);
        trace.arcTo(-pieceSize / 2 -pieceSize / 8, -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 90, -90.0);
        trace.lineTo(-pieceSize / 2, -pieceSize / 2);
    }
    else if(connect[3] == In){
        trace.lineTo(-pieceSize / 2 , pieceSize / 16);
        trace.arcTo(-pieceSize / 2, 0,
                 pieceSize / 8, pieceSize / 8, 180, 90.0);
        trace.arcTo(-pieceSize / 2 -pieceSize / 16, -pieceSize / 8,
                 pieceSize / 4, pieceSize / 4, 270, 180.0);
        trace.arcTo(-pieceSize / 2, -pieceSize / 8,
                 pieceSize / 8, pieceSize / 8, 90, 90);
        trace.lineTo(-pieceSize / 2, -pieceSize / 2);
    }

 }

 void PuzzlePiece::checkNeighbors(QSet<QPoint> &checked)
 {
    if(checked.contains(getPos())) return;
    checked.insert(getPos()); // запомнить посещенный элемент
    findNeighbour(North);     	// найти N соседа
    findNeighbour(East);      	// найти E соседа
    findNeighbour(South);     	// найти S соседа
    findNeighbour(West);      	// найти W соседа

    // рекурсивные вызовы:
    if(m_neighbours[North])
        m_neighbours[North]->checkNeighbors(checked);
    if(m_neighbours[East])
        m_neighbours[East]->checkNeighbors(checked);
    if(m_neighbours[South])
        m_neighbours[South]->checkNeighbors(checked);
    if(m_neighbours[West])
        m_neighbours[West]->checkNeighbors(checked);
 }

 void PuzzlePiece::findNeighbour(PuzzlePiece::Direction dir)
 {
     if(m_neighbours[dir]) return;
     QPoint correctPos(getPos().x(),getPos().y());
     switch(dir){
        case(North):{
         QGraphicsItem* item = field->itemAt(pos().x(),pos().y()-55,QTransform());
         if(item){
             PuzzlePiece* piece = dynamic_cast<PuzzlePiece*>(item);
             if(piece->getPos().x()==correctPos.x() && piece->getPos().y()-correctPos.y() == -1){
                  piece->setPos(pos().x(),pos().y()-50);link(piece,North);}
         }
         break;}
        case(East):{
         QGraphicsItem* item = field->itemAt(pos().x()+55,pos().y(),QTransform());
         if(item){
             PuzzlePiece* piece = dynamic_cast<PuzzlePiece*>(item);
             if(piece->getPos().x()-correctPos.x()==1 && piece->getPos().y()==correctPos.y()){
                  piece->setPos(pos().x()+50,pos().y());link(piece,East);}
         }
             break;
        }
     case(South):{
      QGraphicsItem* item = field->itemAt(pos().x(),pos().y()+55,QTransform());
      if(item){
          PuzzlePiece* piece = dynamic_cast<PuzzlePiece*>(item);
          if(piece->getPos().x()==correctPos.x() && piece->getPos().y()-correctPos.y()==1){
               piece->setPos(pos().x(),pos().y()+50);link(piece,South);}
      }
          break;
     }
     case(West):{
      QGraphicsItem* item = field->itemAt(pos().x()-55,pos().y(),QTransform());
      if(item){
          PuzzlePiece* piece = dynamic_cast<PuzzlePiece*>(item);
          if(piece->getPos().x()-correctPos.x()== -1 && piece->getPos().y()==correctPos.y()){
              piece->setPos(pos().x()-50,pos().y()); link(piece,West);}
      }
          break;
     }


     }

 }

 void PuzzlePiece::setPixmap(QPixmap px)
 {
     pixmap = px;
     update();
 }

 QPoint PuzzlePiece::getPos()
 {
     return coordinates;
 }

 void PuzzlePiece::setCoordinates(QPoint pos)
 {
     coordinates = pos;
 }

 void PuzzlePiece::link(PuzzlePiece *mate, PuzzlePiece::Direction side)
 {
     this->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
     mate->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
     if (side == North){
         m_neighbours[0] = mate;
         mate->m_neighbours[2] = this;
     }
     if (side == East){
         m_neighbours[1] = mate;
         mate->m_neighbours[3] = this;
     }
     if (side == South){
         m_neighbours[2] = mate;
         mate->m_neighbours[0] = this;
     }
     if (side == West){
         m_neighbours[3] = mate;
         mate->m_neighbours[1] = this;
     }
 }

 void PuzzlePiece::Parentscene(QGraphicsScene *scene)
 {
     field = scene;

 }
 inline uint qHash (const QPoint & key)
 {
     return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
 }
 void PuzzlePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
     QSet<QPoint> check;
     checkNeighbors(check);
     if(check.count() == field->items().count()) {
         QMessageBox::information(0, "Puzzle Completed",
                  "Congratulations! You have completed the puzzle!",
                  QMessageBox::Ok);
     }
     check.clear();
     QGraphicsPathItem::mouseReleaseEvent(event);
 }
 QVariant PuzzlePiece::itemChange(GraphicsItemChange change, const QVariant &value)
 {
     if (change == ItemPositionHasChanged) {
         // value is the new position.
         QPointF newPos = value.toPointF();
         if(m_neighbours[0]) m_neighbours[0]->setPos(newPos.x(),newPos.y()-50);
         if(m_neighbours[1]) m_neighbours[1]->setPos(newPos.x()+50,newPos.y());
         if(m_neighbours[2]) m_neighbours[2]->setPos(newPos.x(),newPos.y()+50);
         if(m_neighbours[3]) m_neighbours[3]->setPos(newPos.x()-50,newPos.y());
         }

     return QGraphicsItem::itemChange(change, value);
 }

 void PuzzlePiece::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    painter->setPen(QPen(Qt::black, 3));
    painter->drawPath(path());
    painter->setClipPath(path());
    QRect rect = boundingRect().toRect();
    painter->drawPixmap(rect.x(), rect.y(), pixmap);
    Q_UNUSED(option);
    Q_UNUSED(widget);
 }



