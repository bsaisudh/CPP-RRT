/*
 * @file RRT.h
 * @Copyright MIT license
 * Copyright (c) 2018 Akshay Rajaraman, Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman, Bala Murali Manoghar
 * @brief RRT algorithm class
 */


#ifndef INCLUDE_RRT_H_
#define INCLUDE_RRT_H_

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include "InputMap.h"

/**
 * @brief Class finds path
 *
 * This class finds path from start point to end point
 * using RRT algorithm
 */

class RRT {
 public:
  // !< Shared pointer to input map class
  std::shared_ptr<InputMap> Map;
  // !<Start point of robot in [x,y] format
  int startPoint[2];
  // !<Goal point of robot in [x,y] format
  int goalPoint[2];
  // !<Sampled point in [x,y] format
  int sampledPoint[2];
  // !<New point in [x,y] format
  int newPoint[2];
  // !<Index of parent point in tree
  int parentPointIndex;
  // !<Vector containing details of sampled points
  std::vector<std::array<int, 4>> Tree;
  /**
   * @brief Checks if a point is goal point of robot
   * @param None
   * @return True or False depending on the result
   */
  bool isGoal();
  /**
   * @brief Find a random unvisited sample point from configuration space
   * @param None
   * @return None
   */
  void sampleFromCs();
  /**
   * @brief Add point details to tree
   * @param None
   * @return None
   */
  void addToTree();
  /**
   * @brief Find a new [point nearest to random chosen point
   * @param None
   * @return Integer representing index if the point iin tree
   */
  int computeNewPoint();
  /**
   * @brief Update sample space to remove the visited point
   * @param None
   * @return True or False depending on whether there is more points to visit or not
   */
  bool updateSampleSpace();
  /**
   * @brief Compute and build path form start to goal point
   * @param None
   * @return Vector containing points on path
   */
  std::vector<point> buildPath();
  /**
   * @brief Constructor to initialize all variables
   * @param None
   * @return None
   */
  RRT();
  /**
   * @brief Gets arena boundary from user and stores the values
   * @param Input and output stream references
   * @return None
   */
  virtual ~RRT();
};

#endif /* INCLUDE_RRT_H_ */
