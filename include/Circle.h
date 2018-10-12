/*
 * Circle.h
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#ifndef APP_CIRCLE_H_
#define APP_CIRCLE_H_

#include "Obstacle.h"

class Circle : public Obstacle {
 private:
  int center;
  int radius;
  bool checkValidity();

 public:
  Circle();
  void setBoundary();
  void dispBoundary();
  bool inObstacle(int xCoord, int yCoord);
  virtual ~Circle();
};

#endif /* APP_CIRCLE_H_ */
