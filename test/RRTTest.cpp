/*
 * RRTtest.cpp
 *  Copyright Akshay Rajaraman, Bala Sai Sudhakar
 *  Created on: Oct 16, 2018
 *      Author: root
 */

#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include <utility>
#include <vector>

#include "../include/InputMap.h"
#include "../include/RRT.h"
#include "../include/Square.h"

TEST(RRTClass, isStartInTree) {
  std::stringstream sout;
  std::stringstream sin;
  std::vector<std::shared_ptr<Obstacle>> ob;
  std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);

  // Act
  // Add Workspace
  sin.str("");
  sout.str("");
  sin << "6 6 1 1 2 3 ";
  _ws->setBoundary(sin, sout);
  _ws->setStart(sin, sout);
  _ws->setGoal(sin, sout);
  // Add Square
  sin.str("");
  sout.str("");
  sin << "2 2 1 ";
  ob.emplace_back(new Square);
  ob[0]->setBoundary(sin, sout);
  // Add objects to input map
  std::shared_ptr<InputMap> im(new InputMap);
  im->addObstacle(ob);
  im->setWorkspace(std::move(_ws));

  // Act
  im->computeConfigSpace();
  std::shared_ptr<RRT> rrt(new RRT);
  rrt->Map = std::move(im);
  std::vector<point> path = rrt->buildPath();
  point expectedFirstElement;
  expectedFirstElement.x = 1;
  expectedFirstElement.y = 1;
  ASSERT_EQ(path.at(0).x, expectedFirstElement.x);
  ASSERT_EQ(path.at(0).y, expectedFirstElement.y);
}

TEST(RRTClass, isGoalInTree) {
  std::stringstream sout;
  std::stringstream sin;
  std::vector<std::shared_ptr<Obstacle>> ob;
  std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);

  // Act
  // Add Workspace
  sin.str("");
  sout.str("");
  sin << "3 3 1 1 2 2 ";
  _ws->setBoundary(sin, sout);
  _ws->setStart(sin, sout);
  _ws->setGoal(sin, sout);
  // Add Square
  sin.str("");
  sout.str("");
  sin << "2 2 1 ";
  ob.emplace_back(new Square);
  ob[0]->setBoundary(sin, sout);
  // Add objects to input map
  std::shared_ptr<InputMap> im(new InputMap);
  im->addObstacle(ob);
  im->setWorkspace(std::move(_ws));

  // Act
  im->computeConfigSpace();
  std::shared_ptr<RRT> rrt(new RRT);
  rrt->Map = std::move(im);
  std::vector<point> path = rrt->buildPath();
  point expectedFirstElement;
  expectedFirstElement.x = 2;
  expectedFirstElement.y = 2;
  ASSERT_EQ(path.at(path.size()).x, expectedFirstElement.x);
  ASSERT_EQ(path.at(path.size()).y, expectedFirstElement.y);
}
