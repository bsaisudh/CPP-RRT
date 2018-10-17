/*
 * @file RobotWorkspace.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief RobotWorkspace Class functions
 */

#ifndef INCLUDE_ROBOTWORKSPACE_H_
#define INCLUDE_ROBOTWORKSPACE_H_

#include <iostream>

class RobotWorkspace {
 public:
  RobotWorkspace();
  int maxX, maxY;
  int startX, startY;
  int goalX, goalY;

  virtual ~RobotWorkspace();
  void setBoundary(std::istream &in, std::ostream &out);
  bool inWorkspace(int xCoor, int yCoor);
  void setStart(std::istream &in, std::ostream &out);
  void setGoal(std::istream &in, std::ostream &out);
  bool isGoal(int xCoor, int yCoor);
  bool isStart(int xCoor, int yCoor);
  void dispWorkspace(std::ostream &out);
  int getmaxX();
  int getmaxY();
};

#endif /* INCLUDE_ROBOTWORKSPACE_H_ */
