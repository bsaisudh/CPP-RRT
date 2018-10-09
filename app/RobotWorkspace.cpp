/*
 * RobotWorkspace.cpp
 *  Copyright : Akshay
 *  Created on: Oct 6, 2018
 *      Author: root
 */

#include "../include/RobotWorkspace.h"

#include <stdexcept>
RobotWorkspace::RobotWorkspace()
    : maxX(0),
      maxY(0) {
}

RobotWorkspace::~RobotWorkspace() {
}

void RobotWorkspace::setBoundary(int xValue, int yValue) {
  if (xValue > 0 && yValue > 0) {
    maxX = xValue;
    maxY = yValue;
  } else {
    throw std::invalid_argument("received negative workspace dimensions");
  }
}
bool RobotWorkspace::inWorkspace(int xCoor, int yCoor) {
  if (xCoor < maxX && xCoor > 0 && yCoor < maxY && yCoor > 0) {
    return 1;
  } else {
    return 0;
  }
}
