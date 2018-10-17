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

class InputMap {
 public:
  std::vector<std::shared_ptr<Obstacle>> ob;
  std::shared_ptr<RobotWorkspace> ws;
  std::vector<point> configSpace;

  InputMap();
  void setWorkspace(std::shared_ptr<RobotWorkspace> ws_);
  void addObstacle(std::vector<std::shared_ptr<Obstacle>> &ob_);
  void computeConfigSpace();
  void dispConfigSpace(std::ostream &out);
  virtual ~InputMap();
};

#endif /* INCLUDE_INPUTMAP_H_ */
