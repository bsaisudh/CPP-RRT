/*
 * Circle.h
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#ifndef APP_CIRCLE_H_
#define APP_CIRCLE_H_

#include <iostream>

#include "Obstacle.h"

class Circle : public Obstacle {
 private:
  int centerX;
  int centerY;
  int radius;
  bool checkValidity();

 public:
  Circle();
  void setBoundary(std::istream &in , std::ostream &out);
  void dispBoundary(std::ostream &out);
  bool inObstacle(int xCoord, int yCoord);
  void fillObstacle(std::vector<point> &obMap);
  virtual ~Circle();
};

#endif /* APP_CIRCLE_H_ */
