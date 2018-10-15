/*
 * InputMap.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: bala
 */

#include <iostream>

#include "../include/InputMap.h"

InputMap::InputMap() {
  // TODO Auto-generated constructor stub

}

InputMap::InputMap(RobotWorkspace &rws)
    : ws(&rws) {

}

void InputMap::addObstacle(std::vector<std::shared_ptr<Obstacle>> &ob_) {
  for (const auto &i : ob_) {
    ob.emplace_back(std::move(i));
  }
}

void InputMap::setWorkspace(std::shared_ptr<RobotWorkspace> ws_) {
  ws = std::move(ws_);
}

void InputMap::computeConfigSpace() {
  configSpace.clear();
  point point;
  for (int i = 0; i < ws->getmaxX(); i++) {
    for (int j = 0; j < ws->getmaxY(); j++) {
      bool inobstacle = false;
      for (auto &obiter : ob) {
        inobstacle |= obiter->inObstacle(i, j);
      }
      if (!inobstacle) {
        point.x = i;
        point.y = j;
        configSpace.emplace_back(point);
      }
    }
  }
}

void InputMap::dispConfigSpace(std::ostream &out){
  for(auto &i : configSpace){
    out << "(" << i.x << " , " << i.y << ")" << std::endl;
  }
}

InputMap::~InputMap() {
  // TODO Auto-generated destructor stub
}

