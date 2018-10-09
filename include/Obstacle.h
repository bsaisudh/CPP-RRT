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

/**
 * @brief Obstacle class
 *
 */
class Obstacle {
 private:

 public:
  Obstacle();
  virtual void setBoundary() = 0;
  virtual void dispBoundary() = 0;
  virtual bool inObstacle(int xCoord, int yCoord) = 0;
  virtual ~Obstacle();
};

#endif /* OBSTACLE_H_ */
