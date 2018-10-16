/*
 * RRT.cpp
 *  Copyright Akshay Rajaraman and Bala Sai Sudhakar
 *  Created on: Oct 12, 2018
 *      Author: bala
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
  std::srand(std::time(nullptr));
  int random_location = std::rand()/((RAND_MAX + 1u)/Map -> configSpace.size());
  sampledPoint[0] = Map -> configSpace.at(random_location).x;
  sampledPoint[1] = Map -> configSpace.at(random_location).y;
}

void RRT::addToTree() {
    int parentPointIndex = computeNewPoint();
    point point;
    point.x = newPoint[0];
    point.y = newPoint[1];
    for (int iter = 0; iter < Map -> configSpace.size(); iter++) {
      if (Map -> configSpace.at(iter).x == point.x &&
          Map -> configSpace.at(iter).y == point.y) {
        int test = Tree.size();
        Tree.push_back({{newPoint[0], newPoint[1],
                static_cast<int>(Tree.size())+1,
                Tree.at(parentPointIndex)[2]}});
      }
    }
}

int RRT::computeNewPoint() {
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
    int availableMovements[8][2] = {{Tree.at(index)[1], Tree.at(index)[2]+1},
        {Tree.at(index)[1]+1, Tree.at(index)[2]+1},
        {Tree.at(index)[1]+1, Tree.at(index)[2]},
        {Tree.at(index)[1]+1, Tree.at(index)[2]-1},
        {Tree.at(index)[1], Tree.at(index)[2]-1},
        {Tree.at(index)[1]-1, Tree.at(index)[2]-1},
        {Tree.at(index)[1]-1, Tree.at(index)[2]},
        {Tree.at(index)[1]-1, Tree.at(index)[2]+1}};
    std::vector<double> distanceFromNewPoints;
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
      return index;
}

bool RRT::updateSampleSpace() {
  point erasePoint;
  erasePoint.x = sampledPoint[0];
  erasePoint.y = sampledPoint[1];
  for (int iter = 0; iter < Map -> configSpace.size(); iter++) {
        if (Map -> configSpace.at(iter).x == erasePoint.x &&
            Map -> configSpace.at(iter).y == erasePoint.y) {
          Map ->  configSpace.erase(Map -> configSpace.begin()+iter);
        }
      }
  if (Map -> configSpace.size() == 1) {
    return true;
  } else {
    return false;
  }
}

std::vector<point> RRT::buildPath() {
  startPoint[0] = Map -> ws -> startX;
  startPoint[1] = Map -> ws -> startY;
  goalPoint[0] = Map -> ws -> goalX;
  goalPoint[1] = Map -> ws -> goalY;
  Tree.push_back({{startPoint[0], startPoint[1], 1, 0}});
  while (!isGoal()) {
    sampleFromCs();
    addToTree();
    computeNewPoint();
    bool isNotReachable = updateSampleSpace();
    if (isNotReachable) {
        break;
      }
  }
  std::vector<point> path;
  int newIndex = Tree.size() - 1;
  point parentPoint;
  while (newIndex != 0) {
    parentPoint.x = Tree.at(newIndex)[0];
    parentPoint.y = Tree.at(newIndex)[1];
    path.push_back(parentPoint);
    newIndex = Tree.at(newIndex)[3];
    std::cout << Tree.at(newIndex)[0];
    std::cout << Tree.at(newIndex)[1];
    std::cout << Tree.at(newIndex)[2];
    std::cout << Tree.at(newIndex)[3];
    int x;
    std::cin >> x;
    std::cout << newIndex;
  }
  return path;
}

RRT::~RRT() {
}


