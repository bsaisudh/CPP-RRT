/*
 * @file InputMap.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief InputMap class implementation
 */

#include <iostream>

#include "../include/InputMap.h"

InputMap::InputMap() {
}

void InputMap::addObstacle(std::vector<std::shared_ptr<Obstacle>> &ob_) {
  // Move each point in the vector to vector inside input map class
  for (const auto &i : ob_) {
    ob.emplace_back(std::move(i));
  }
}

void InputMap::setWorkspace(std::shared_ptr<RobotWorkspace> ws_) {\
  ws = std::move(ws_);
}

void InputMap::computeConfigSpace() {
  // Clearing the previous values
  configSpace.clear();
  point point;
  // Traverse through all points in workspace and add to vector
  // if point is not inside any obstacle
  for (int i = 0; i < ws->getmaxX(); i++) {
    for (int j = 0; j < ws->getmaxY(); j++) {
      bool inobstacle = false;
      // Traverse through all obstacles to check if point is free
      for (auto &obiter : ob) {
        inobstacle |= obiter->inObstacle(i, j);
      }
      if (!inobstacle) {
        // Point is not inside obstacle
        point.x = i;
        point.y = j;
        configSpace.emplace_back(point);
      }
    }
  }
}

void InputMap::dispConfigSpace(std::ostream &out) {
  // Traverse through all points in congig space and display point
  for (auto &i : configSpace) {
    out << "(" << i.x << " , " << i.y << ")" << std::endl;
  }
}

InputMap::~InputMap() {
}

