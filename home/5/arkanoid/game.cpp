#include <QPainter>
#include <QColor>
#include <QDebug>

#include "game.h"

Game::Game() {
    radius = 50;
    srand(time(NULL));
    size = QSize(600, 600);
    for (int i = 0; i < NOB; i++) {
        int x, y;
        bool flag = false;
        do {
            x = rand() % (size.width() - 2 * radius) + radius;
            y = rand() % (size.height() - 2 * radius) + radius;
            flag = false;
            for (int j = 0; j < i; j++) {
                if ((position[j] - QVector2D(x, y)).length() < (2 * radius)) {
                    flag = true;
                    break;
                }
            }
        } while (flag == true);

        position[i] = QVector2D(x, y);
        velocity[i] = QVector2D(rand() % 300 / 10, rand() % 300 / 10);
        gravity[i] = QVector2D(0.0, 0.0);
   }
    tau = 0.05;
    texture_ball = new QPixmap("pictures/ball.png");

}

void Game::step() {
    QVector2D normal[] = {   QVector2D(1, 0),
                             QVector2D(0, -1),
                             QVector2D(-1, 0),
                             QVector2D(0, 1) }; 
    for (int i = 0; i < NOB; i++) {
        QVector2D border[] = {   QVector2D(radius, radius),
                                 QVector2D(radius, size.height() - radius),
                                 QVector2D(size.width() - radius, size.height() - radius),
                                 QVector2D(size.width() - radius, radius) };
        for (int j = 0; j < 4; j++) {
            qreal normal_factor = QVector2D::dotProduct(position[i] - border[j], normal[j]);
            if (normal_factor < 0) {
                position[i] = position[i] - 2 * normal_factor * normal[j];
                velocity[i] = velocity[i] - 2 * QVector2D::dotProduct(velocity[i], normal[j]) * normal[j];
            }
        }

        for (int j = 0; j < NOB; j++) {
            if (i == j)
                continue;
            if ((position[i] - position[j]).length() <= (2 * radius)) {
                qDebug() << "till i collapse";
                QVector2D velocity1new = QVector2D::dotProduct(velocity[i] - velocity[j], position[i] - position[j])
                        * (position[i] - position[j]);
                velocity1new /= (position[i] - position[j]).lengthSquared();
                QVector2D velocity2new = QVector2D::dotProduct(velocity[j] - velocity[i], position[j] - position[i])
                        * (position[j] - position[i]);
                velocity2new /= (position[j] - position[i]).lengthSquared();
                velocity[i] -= velocity1new;
                velocity[j] -= velocity2new;
            }        
        }
        position[i] = position[i] + tau * velocity[i];
        velocity[i] = velocity[i] + tau * gravity[i];
    }
}

void Game::draw(QPixmap *pixmap) {
    pixmap->fill(Qt::white);
    QPainter painter(pixmap);
    for (int i = 0; i < NOB; i++) {
    painter.drawPixmap( position[i].x() - radius,
                        position[i].y() - radius,
                        *texture_ball);
    }
}

Game::~Game() {
  delete texture_ball;
}
