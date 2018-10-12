/*
 * RRT.h
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#ifndef APP_RRT_H_
#define APP_RRT_H_

#include <vector>

#include "InputMap.h"

class RRT {
 private:
  InputMap Map;
  int sampledPoint[2];
  int newPoint[2];
  std::vector<int[2]> Tree;

  bool isGoal();
  void sampleFromCs();
  void addToTree();
  void computeNewPoint();
  bool updateSampleSpace();
  std::vector<int[2]> buildPath();

 public:
  RRT();
  std::vector<int[2]> computePath();
  virtual ~RRT();
};

#endif /* APP_RRT_H_ */
