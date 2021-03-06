#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <stdint.h>
#include "orbitaltrack.h"



class CelestialBody: public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    CelestialBody(QString bodyName, qreal size, qreal orbitalVelocity, QString trajectoryFilePath, QColor color);
    ~CelestialBody();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void vLoadTrajectory(QString filePath);
    ObritalTrack* getTrjectory();

public slots:
    void setMovementScale(int scale);

protected:
    void advance(int step) override;

private:
    int distanceScale = 1500; //150millionkm = 1au
    qreal kmToMKM = .001;
    qreal movementScale = 30000.0;
    int simStepScale = 100;

    qreal orbitalVelocity;
    std::vector<double> distanceMeasurements;
    QPainterPath obritalTrajectory;
    ObritalTrack *track;
    QPainterPath testtraj;
    qreal pathPercentComplete;
    QPolygonF pathPoly;
    QString bodyName;
    qreal bodySize;
    QColor bodyColor;

};








#endif // CELESTIALBODY_H
