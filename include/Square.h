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

/**
 * @brief Square class that holds functions of Square obstacle.
 */
class Square : public Obstacle {
 private:
  int startX;   // !<X co-ordinate of start point
  int startY;   // !<Y co-ordinate of start point
  int side;     // !<Side length

 public:
  /**
   * @brief Constructor to initialize all variables for obstacle class
   * @param None
   * @return None
   */
  Square();
  /**
   * @brief Gets boundary of square obstacle form user and updates the object
   * @param Input and output stream
   * @return None
   */
  virtual void setBoundary(std::istream &in, std::ostream &out);
  /**
   * @brief Display the square obstacle boundary points to user that has given
   * @param Output stream
   * @return input stream
   */
  virtual void dispBoundary(std::ostream &out);
  /**
   * @brief Checks if the point is inside the circle obstacle
   * @param X and y coordinates for the point to be checked
   * @return True if the point is inside obstacle else false
   */
  virtual bool inObstacle(int xCoord, int yCoord);
  /**
   * @brief Finds all points in circle obstacle
   * @param Vector to hold all points of obstacle
   * @return None
   */
  virtual void fillObstacle(std::vector<point> &obMap);
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~Square();
};

#endif /* INCLUDE_SQUARE_H_ */
