/*
 * RobotWorkspace.h
 *  Copyright : Akshay
 *  Created on: Oct 6, 2018
 *      Author: root
 */

#ifndef INCLUDE_ROBOTWORKSPACE_H_
#define INCLUDE_ROBOTWORKSPACE_H_

class RobotWorkspace {
 private:
  int maxX, maxY;
 public:
  RobotWorkspace();
  virtual ~RobotWorkspace();
  void setBoundary(int xValue, int yValue);
  bool inWorkspace(int xCoor, int yCoor);
};

#endif /* INCLUDE_ROBOTWORKSPACE_H_ */
