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
  bool isGoal();
  void sampleFromCs();
  void addToTree();
  void computeNewPoint();
  bool updateSampleSpace();
  std::vector<point> buildPath();
 public:
  InputMap Map;
  std::vector<point> Tree;
  RRT();
  std::vector<point> computePath();
  virtual ~RRT();
};

#endif /* APP_RRT_H_ */
