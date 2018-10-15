/*
 * RobotWorkspace.cpp
 *  Copyright : Akshay
 *  Created on: Oct 6, 2018
 *      Author: root
 */

#include "../include/RobotWorkspace.h"

using std::cout;
using std::cin;
using std::endl;

RobotWorkspace::RobotWorkspace()
    : maxX(0),
      maxY(0),
      startX(0),
      startY(0),
      goalX(0),
      goalY(0){
}

RobotWorkspace::~RobotWorkspace() {
}

void RobotWorkspace::setBoundary(std::istream &in , std::ostream &out) {
  out << "Enter map max X dimension : ";
  in >> maxX;
  out << "Enter map max y dimension : ";
  in >> maxY;
}

bool RobotWorkspace::inWorkspace(int xCoor, int yCoor) {
  if (xCoor < maxX && xCoor > 0 && yCoor < maxY && yCoor > 0) {
    return true;
  } else {
    return false;
  }
}

void RobotWorkspace::setStart(std::istream &in , std::ostream &out) {
  out << "Enter start X coordinate : ";
  in >> startX;
  out << "Enter start Y coordinate : ";
  in >> startY;
}

void RobotWorkspace::setGoal(std::istream &in , std::ostream &out) {
  out << "Enter goal X coordinate : ";
  in >> goalX;
  out << "Enter goal Y coordinate : ";
  in >> goalY;
}

bool RobotWorkspace::isGoal(int xCoor, int yCoor) {
  return (xCoor == goalX && yCoor == goalY);
}

bool RobotWorkspace::isStart(int xCoor, int yCoor) {
  return (xCoor == startX && yCoor == startY);
}

void RobotWorkspace::dispWorkspace(std::ostream &out) {
  out << "Start point :" << startX << " , " << startY << endl;
  out << "Goal point :" << goalX << " , " << goalY << endl;
  out << "Workspace : ( 0 , 0 ) ( " << maxX << " , " << maxY << ")" << endl;
}

int RobotWorkspace::getmaxX() {
  return maxX;
}

int RobotWorkspace::getmaxY() {
  return maxY;
}
