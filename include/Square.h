/*
 * Square.h
 *
 *  Created on: Oct 6, 2018
 *      Author: bala
 */
#ifndef SQUARE_H_
#define SQUARE_H_

#include "Obstacle.h"

class Square : public Obstacle {
 private:
  int startX;
  int startY;
  int side;
  bool checkValidity();

 public:
  Square();
  void setBoundary();
  void dispBoundary();
  bool inObstacle(int xCoord, int yCoord);
  virtual ~Square();
};

#endif /* SQUARE_H_ */
