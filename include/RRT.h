/*
 * RRT.h
 *  Copyright Akshay Rajaraman, Bala Sai Sudhakar
 *      Author: bala
 */

#ifndef INCLUDE_RRT_H_
#define INCLUDE_RRT_H_

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include "InputMap.h"

class RRT {
 public:
  std::shared_ptr<InputMap> Map;
  int startPoint[2];
  int goalPoint[2];
  int sampledPoint[2];
  int newPoint[2];
  std::vector<std::array<int, 4>> Tree;
  bool isGoal();
  void sampleFromCs();
  void addToTree();
  int computeNewPoint();
  bool updateSampleSpace();
  std::vector<point> buildPath();
  RRT();
  virtual ~RRT();
};

#endif /* INCLUDE_RRT_H_ */
