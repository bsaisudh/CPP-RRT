/*
 * @file RRT.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Akshay Rajaraman, Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman, Bala Murali Manoghar
 * @brief RRT algorithm implementation class
 */

#include "../include/RRT.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <utility>
#include <iostream>
RRT::RRT() {
}

bool RRT::isGoal() {
  if ((startPoint[0] == goalPoint[0] & startPoint[1] == goalPoint[1]) ||
      (newPoint[0] == goalPoint[0] && newPoint[1] == goalPoint[1])) {
    return 1;
  } else {
    return 0;
  }
}

void RRT::sampleFromCs() {
  // @brief seeding random sampler
  std::srand(std::time(nullptr));
  /* @brief obtaining the location of a random point
   * from the configuration space
   */
  int random_location = std::rand()/((RAND_MAX + 1u)/Map -> configSpace.size());
  sampledPoint[0] = Map -> configSpace.at(random_location).x;
  sampledPoint[1] = Map -> configSpace.at(random_location).y;
}

void RRT::addToTree() {
    parentPointIndex = computeNewPoint();
    int test = Tree.size();
    // @brief adding new point to Tree
    Tree.push_back({{newPoint[0], newPoint[1],
                test,
                parentPointIndex}});
}

int RRT::computeNewPoint() {
    /* @brief Locating the index of the closest point on the Tree from the
     sampled point*/
    std::vector<double> distance;
    for (int i = 0; i < Tree.size(); i++) {
      distance.push_back(std::pow(std::pow(Tree.at(i)[0]-sampledPoint[0], 2)+
          std::pow(Tree.at(i)[1]-sampledPoint[1], 2), 0.5));
    }
    int index = 0;
    double n = distance.at(0);
    for (int i = 1; i < distance.size(); ++i) {
      if (distance.at(i) < n) {
         n = distance.at(i);
         index = i;
      }
    }
    /* @brief Determining the possible movements from the
      point on the tree through 8 point connectivity*/
    int availableMovements[8][2] = {{Tree.at(index)[0], Tree.at(index)[1]+1},
        {Tree.at(index)[0]+1, Tree.at(index)[1]+1},
        {Tree.at(index)[0]+1, Tree.at(index)[1]},
        {Tree.at(index)[0]+1, Tree.at(index)[1]-1},
        {Tree.at(index)[0], Tree.at(index)[1]-1},
        {Tree.at(index)[0]-1, Tree.at(index)[1]-1},
        {Tree.at(index)[0]-1, Tree.at(index)[1]},
        {Tree.at(index)[0]-1, Tree.at(index)[1]+1}};
    std::vector<double> distanceFromNewPoints;
    // @brief obtaining index of closest point from 8 points
    for (int j = 0; j < 8; j++) {
      distanceFromNewPoints.push_back(std::pow(
          std::pow(availableMovements[j][0]-sampledPoint[0], 2)+
            std::pow(availableMovements[j][1]-sampledPoint[1], 2), 0.5));
      }
    int newPointIndex = 0;
      double newN = distanceFromNewPoints.at(0);
      for (int i = 1; i < distanceFromNewPoints.size(); ++i) {
        if (distanceFromNewPoints.at(i) < newN) {
           newN = distanceFromNewPoints.at(i);
           newPointIndex = i;
        }
      }
      newPoint[0] = availableMovements[newPointIndex][0];
      newPoint[1] = availableMovements[newPointIndex][1];
      // @brief returning parent point index
      return index;
}

bool RRT::updateSampleSpace() {
  // @brief removing used sample point from configuration space
  point erasePoint;
  erasePoint.x = sampledPoint[0];
  erasePoint.y = sampledPoint[1];
  for (int iter = 0; iter < Map -> configSpace.size(); iter++) {
        if (Map -> configSpace.at(iter).x == erasePoint.x &&
            Map -> configSpace.at(iter).y == erasePoint.y) {
          Map ->  configSpace.erase(Map -> configSpace.begin()+iter);
          break;
        }
      }
  if (Map -> configSpace.size() == 1) {
    return true;
  } else {
    return false;
  }
}

std::vector<point> RRT::buildPath() {
  // @brief Obtaining start and goal points from input map
  startPoint[0] = Map -> ws -> startX;
  startPoint[1] = Map -> ws -> startY;
  goalPoint[0] = Map -> ws -> goalX;
  goalPoint[1] = Map -> ws -> goalY;
  // @brief Adding start point to tree
  Tree.push_back({{startPoint[0], startPoint[1], 0, 0}});
  while (!isGoal()) {
    sampleFromCs();
    addToTree();
    bool isNotReachable = updateSampleSpace();
    if (isNotReachable) {
        break;
      }
  }
  Tree.push_back({{goalPoint[0], goalPoint[1],
                  static_cast<int>(Tree.size()),
                  parentPointIndex}});
  std::vector<point> path;
  int newIndex = Tree.size() - 1;
  point parentPoint;
  // @brief obtain path coordinates
  while (newIndex > 0) {
    parentPoint.x = Tree.at(newIndex)[0];
    parentPoint.y = Tree.at(newIndex)[1];
    path.push_back(parentPoint);
    newIndex = Tree.at(newIndex)[3];
  }
  parentPoint.x = Tree.at(0)[0];
  parentPoint.y = Tree.at(0)[1];
  path.push_back(parentPoint);
  return path;
}

RRT::~RRT() {
}
