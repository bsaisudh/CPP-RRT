/**
 * @file, @brief, , @copyright
 * @file Obstracle.h
 * @brief Obstacle  class declaration.
 * @author BalaMuraliManoghar
 * @copyright 2018 BalaMuraliManoghar
 *
 * Obstacle class declaration.
 */
#ifndef INCLUDE_OBSTACLE_H_
#define INCLUDE_OBSTACLE_H_

#include <iostream>
  struct point{
      int x, y;
  };
/**
 * @brief Obstacle class
 *
 */
class Obstacle {
 public:
  Obstacle();
  virtual void setBoundary(std::istream &in , std::ostream &out) = 0;
  virtual void dispBoundary(std::ostream &out) = 0;
  virtual bool inObstacle(int xCoord, int yCoord) = 0;
  virtual ~Obstacle();
};

#endif /* INCLUDE_OBSTACLE_H_ */
