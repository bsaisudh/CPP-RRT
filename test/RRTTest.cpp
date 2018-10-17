/*
 * @file RRT.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Akshay Rajaraman, Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman, Bala Murali Manoghar
 * @brief RRT unit test implementation class
 */



#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include <utility>
#include <vector>

#include "../include/InputMap.h"
#include "../include/RRT.h"
#include "../include/Square.h"

// @brief to test if goal was reached by checking goal point in tree
TEST(RRTClass, isGoalInTree) {
  std::stringstream sout;
    std::stringstream sin;
    std::vector<std::shared_ptr<Obstacle>> ob;
    std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);

    // Act
    // Add Workspace
    sin.str("");
    sout.str("");
    sin << "10 10 1 1 9 5 ";
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
    rrt -> Map = std::move(im);
    std::vector<point> path = rrt -> buildPath();
    point expectedFirstElement;
    expectedFirstElement.x = 9;
    expectedFirstElement.y = 5;
    ASSERT_EQ(path.at(0).x, expectedFirstElement.x);
    ASSERT_EQ(path.at(0).y, expectedFirstElement.y);
}
