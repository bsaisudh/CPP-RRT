/*
 * @file InputMap.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief InputMap Class functions
 */

#ifndef INCLUDE_INPUTMAP_H_
#define INCLUDE_INPUTMAP_H_

#include <vector>
#include <memory>

#include "Obstacle.h"
#include "RobotWorkspace.h"

/**
 * @brief Class holds map properties
 *
 * Map properties like obstacles, start point,
 * goal point are stored here
 */
class InputMap {
 public:
  // !<Vector of obstacles
  std::vector<std::shared_ptr<Obstacle>> ob;
  // !<Workspace shared pointer
  std::shared_ptr<RobotWorkspace> ws;
  // !<Configuration space vector of point
  std::vector<point> configSpace;
  /**
   * @brief Constructor to initialize all variables
   * @param None
   * @return None
   */
  InputMap();
  /**
   * @brief Gets workspace parameters from user
   * @param shared pointer to workspace objec
   * @return None
   */
  void setWorkspace(std::shared_ptr<RobotWorkspace> ws_);
  /**
   * @brief Adds all obstacles to inputmap object
   * @param Vector of obstacles
   * @return None
   */
  void addObstacle(std::vector<std::shared_ptr<Obstacle>> &ob_);
  /**
   * @brief Compute free spaces in workspace
   * @param None
   * @return None
   */
  void computeConfigSpace();
  /**
   * @brief Displays configuration points to user
   * @param Output stream reference
   * @return None
   */
  void dispConfigSpace(std::ostream &out);
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~InputMap();
};

#endif /* INCLUDE_INPUTMAP_H_ */
