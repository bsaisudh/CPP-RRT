
/*
 * @file Square.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Square Class functions
 */

#ifndef INCLUDE_SQUARE_H_
#define INCLUDE_SQUARE_H_

#include <iostream>
#include <vector>

#include "Obstacle.h"

class Square : public Obstacle {
 private:
  int startX;
  int startY;
  int side;

 public:
  Square();
  void setBoundary(std::istream &in, std::ostream &out);
  void dispBoundary(std::ostream &out);
  bool inObstacle(int xCoord, int yCoord);
  void fillObstacle(std::vector<point> &obMap);
  virtual ~Square();
};

#endif /* INCLUDE_SQUARE_H_ */
