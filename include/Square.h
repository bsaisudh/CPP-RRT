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
  int startx;
  int starty;
  int side;

 public:
  Square();
  void setBoundary();
  void dispBoundary();
  virtual ~Square();
};

#endif /* SQUARE_H_ */
