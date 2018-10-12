/*
 * InputMap.h
 *
 *  Created on: Oct 7, 2018
 *      Author: bala
 */

#ifndef INPUTMAP_H_
#define INPUTMAP_H_

#include <vector>
#include <memory>

#include "Obstacle.h"
#include "RobotWorkspace.h"

class InputMap {
 private:
  std::vector<std::unique_ptr<Obstacle>> ob;
  std::unique_ptr<RobotWorkspace> ws;
 public:
  InputMap();
  void setWorkspace(const std::unique_ptr<RobotWorkspace> ws_);
  void addObstacle(const std::vector<std::unique_ptr<Obstacle>> &ob_);
  void deriveConfigSpace();
  virtual ~InputMap();
};

#endif /* INPUTMAP_H_ */
