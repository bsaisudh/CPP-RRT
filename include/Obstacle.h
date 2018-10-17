/*
 * @file Obstracle.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Obstacle class which is a abstract class for all obstacles
 */

#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include <iostream>
#include <vector>

/**
 * @brief Structure to hold x and y co-odinates of point.
 */
struct point {
  int x, y;
};

/**
 * @brief Obstacle obstacle class that serves as parent for all types of obstacles.
 */
class Obstacle {
 public:
  /**
   * @brief Constructor to initialize all variables for obstacle class
   * @param None
   * @return None
   */
  Obstacle();
  /**
   * @brief Virtual function that gets boundary of obstacle form user and updates the object
   * @param Input and output stream
   * @return None
   */
  virtual void setBoundary(std::istream &in, std::ostream &out) = 0;
  /**
   * @brief Virtual function to display the obstacle boundary points to user that has given
   * @param Output stream
   * @return input stream
   */
  virtual void dispBoundary(std::ostream &out) = 0;
  /**
   * @brief Finds all points in obstacle
   * @param Vector to hold all points of obstacle
   * @return None
   */
  virtual bool inObstacle(int xCoord, int yCoord) = 0;
  /**
   * @brief Virtual function to find all points in obstacle
   * @param Vector to hold all points of obstacle
   * @return None
   */
  virtual void fillObstacle(std::vector<point> &obMap) = 0;
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~Obstacle();
};

#endif /* OBSTACLE_H_ */
