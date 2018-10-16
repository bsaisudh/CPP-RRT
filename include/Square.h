/*
 * Square.h
 *
 *  Created on: Oct 6, 2018
 *      Author: bala
 */
#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>

#include "Obstacle.h"

class Square : public Obstacle {
 private:
  int startX;
  int startY;
  int side;
  bool checkValidity();

 public:
  Square();
  void setBoundary(std::istream &in , std::ostream &out);
  void dispBoundary(std::ostream &out);
  bool inObstacle(int xCoord, int yCoord);
  void fillObstacle(std::vector<point> &obMap);
  virtual ~Square();
};

#endif /* SQUARE_H_ */
