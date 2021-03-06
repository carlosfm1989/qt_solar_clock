#include "orbitaltrack.h"


#define MAGIC_BOUNDING_BOX 8000000 //<---- Trick to keep all the circles rendered when scrolling.

ObritalTrack::ObritalTrack(double min, double max){

    this->min = min*2; //2x due to odd behavior of QPainterPath PointAtPercent vs drawing coordinate
    this->max = max*2;
}

void ObritalTrack::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                         QWidget *widget){
    QPen pen;
    pen.setColor(QColor(165,169,162));
    pen.setWidth(100);
    pen.setCapStyle(Qt::FlatCap);
    pen.setStyle(Qt::DotLine);
    painter->save();
    painter->setPen(pen);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter->setRenderHint(QPainter::HighQualityAntialiasing, true);
    painter->drawEllipse(this->scenePos(), min ,max);
    painter->restore();
}

QRectF ObritalTrack::boundingRect() const {
    return QRectF(-MAGIC_BOUNDING_BOX/2, -MAGIC_BOUNDING_BOX/2, MAGIC_BOUNDING_BOX, MAGIC_BOUNDING_BOX);
}

void ObritalTrack::advance(int step){
    if(!step)
        return;
    else{
       this->setPos(QPoint(0,0));
    }
}


QPainterPath ObritalTrack::shape() const{
    QPainterPath path;
    path.addEllipse(0,0,0,0);
    return path;
}
