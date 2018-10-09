/*
 * Input.h
 *
 *  Created on: Oct 7, 2018
 *      Author: bala
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <vector>
#include <memory>

#include "Obstacle.h"
#include "RobotWorkspace.h"

class Input {
 private:
  std::vector<std::unique_ptr<Obstacle>> ob;
  std::unique_ptr<RobotWorkspace> ws;
 public:
  Input();
  void getWorkspace(const std::unique_ptr<RobotWorkspace> ws_);
  void getObstacle(const std::vector<std::unique_ptr<Obstacle>> &ob_);
  virtual ~Input();
};

#endif /* INPUT_H_ */
