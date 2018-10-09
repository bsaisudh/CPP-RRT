/*
 * Input.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: bala
 */

#include "Input.h"

Input::Input() {
  // TODO Auto-generated constructor stub

}

void Input::getObstacle(const std::vector<std::unique_ptr<Obstacle>> &ob_) {
  for ( const auto &i : ob_) {
    ob.emplace_back(std::move(i));
  }
}

void Input::getWorkspace(const std::unique_ptr<RobotWorkspace> ws_) {
  ws = std::move(ws_);
}

Input::~Input() {
  // TODO Auto-generated destructor stub
}

