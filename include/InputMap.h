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

 public:
  std::vector<std::shared_ptr<Obstacle>> ob;
  std::shared_ptr<RobotWorkspace> ws;
  std::vector<point> configSpace;

  InputMap();
  InputMap(RobotWorkspace &rws);
  void setWorkspace(std::shared_ptr<RobotWorkspace> ws_);
  void addObstacle(std::vector<std::shared_ptr<Obstacle>> &ob_);
  void computeConfigSpace();
  void dispConfigSpace(std::ostream &out);
  virtual ~InputMap();
};

#endif /* INPUTMAP_H_ */
