/*
 * @file Circle.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Circle class functions
 */

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <iostream>
#include <vector>

#include "Obstacle.h"

/**
 * @brief Circle class that holds functions of circular obstacle.
 */
class Circle : public Obstacle {
 private:
  int centerX;    // !<X co-ordinate of center point
  int centerY;    // !<Y co-ordinate of center point
  int radius;     // !<Radius of circle

 public:
  /**
   * @brief Constructor to initialize all variables for obstacle class
   * @param None
   * @return None
   */
  Circle();
  /**
   * @brief Gets boundary of circle obstacle form user and updates the object
   * @param Input and output stream
   * @return None
   */
  void setBoundary(std::istream &in, std::ostream &out);
  /**
   * @brief Display the circle obstacle boundary points to user that has given
   * @param Output stream
   * @return input stream
   */
  void dispBoundary(std::ostream &out);
  /**
   * @brief Checks if the point is inside the circle obstacle
   * @param X and y coordinates for the point to be checked
   * @return True if the point is inside obstacle else false
   */
  bool inObstacle(int xCoord, int yCoord);
  /**
   * @brief Finds all points in circle obstacle
   * @param Vector to hold all points of obstacle
   * @return None
   */
  void fillObstacle(std::vector<point> &obMap);
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~Circle();
};

#endif  // INCLUDE_CIRCLE_H_
