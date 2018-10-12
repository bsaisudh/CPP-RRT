/*
 * InputMap.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: bala
 */

#include "../include/InputMap.h"

InputMap::InputMap() {
  // TODO Auto-generated constructor stub

}

void InputMap::getObstacle(const std::vector<std::unique_ptr<Obstacle>> &ob_) {
  for ( const auto &i : ob_) {
    ob.emplace_back(std::move(i));
  }
}

void InputMap::getWorkspace(const std::unique_ptr<RobotWorkspace> ws_) {
  ws = std::move(ws_);
}

InputMap::~InputMap() {
  // TODO Auto-generated destructor stub
}

