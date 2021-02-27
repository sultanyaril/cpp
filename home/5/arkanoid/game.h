#ifndef _GAME_H
#define _GAME_H

#include <QVector2D>
#include <QSize>
#include <QPixmap>
#define NOB 3 // number of balls
class Game {
  QSize size;
  QVector2D position[NOB];
  QVector2D velocity[NOB];
  QVector2D gravity[NOB];
  double tau;
  int radius;
  QPixmap *texture_ball;
  friend class MainWindow;

public:
  Game();
  ~Game();
  void step();
  void draw(QPixmap *pixmap);
};

#endif
