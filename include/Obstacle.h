/**
 * @file, @brief, , @copyright
 * @file Obstracle.h
 * @brief Obstacle  class declaration.
 * @author BalaMuraliManoghar
 * @copyright 2018 BalaMuraliManoghar
 *
 * Obstacle class declaration.
 */
#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include <iostream>

/**
 * @brief Obstacle class
 *
 */
class Obstacle {
 private:

 public:
  Obstacle();
  virtual void setBoundary(std::istream &in , std::ostream &out) = 0;
  virtual void dispBoundary(std::ostream &out) = 0;
  virtual bool inObstacle(int xCoord, int yCoord) = 0;
  virtual ~Obstacle();
};

#endif /* OBSTACLE_H_ */
