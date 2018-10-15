/*
 * RobotWorkspace.h
 *  Copyright : Akshay
 *  Created on: Oct 6, 2018
 *      Author: root
 */

#ifndef INCLUDE_ROBOTWORKSPACE_H_
#define INCLUDE_ROBOTWORKSPACE_H_

#include <iostream>

class RobotWorkspace {
 private:
  int maxX, maxY;
  int startX,startY;
  int goalX ,goalY;
  bool checkValidity();
 public:
  RobotWorkspace();
  virtual ~RobotWorkspace();
  void setBoundary(std::istream &in , std::ostream &out);
  bool inWorkspace(int xCoor, int yCoor);
  void setStart(std::istream &in , std::ostream &out);
  void setGoal(std::istream &in , std::ostream &out);
  bool isGoal(int xCoor, int yCoor);
  bool isStart(int xCoor, int yCoor);
  void dispWorkspace(std::ostream &out);
  int getmaxX();
  int getmaxY();
};

#endif /* INCLUDE_ROBOTWORKSPACE_H_ */
