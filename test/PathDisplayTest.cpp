/*
 * @file PathDisplayTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author: Bala Murali Manoghar Sai Sudhakar
 * @brief testing path display class
 */

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>
#include <memory>

#include "../include/InputMap.h"
#include "../include/RobotWorkspace.h"
#include "../include/Obstacle.h"
#include "../include/Square.h"
#include "../include/Circle.h"
#include "../include/PathDisplay.h"

/**
 * @brief Path Display
 */
TEST(PathDisplayClass, ConfigSpaceCreation) {
  // Arrange
  std::stringstream sout;
  std::stringstream sin;
  std::vector<std::shared_ptr<Obstacle>> ob;
  std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);
  std::shared_ptr<InputMap> im(new InputMap);
  PathDisplay pathDisp;
  std::vector<point> path;
  point point;


  // Act
  // Add Workspace
  sin.str("");
  sout.str("");
  sin << "6 6 1 1 2 3 ";
  _ws->setBoundary(sin, sout);
  _ws->setStart(sin, sout);
  _ws->setGoal(sin, sout);
  point.x = 2;
  point.y = 3;
  path.emplace_back(point);
  // Add Square
  sin.str("");
  sout.str("");
  sin << "2 2 1 ";
  ob.emplace_back(new Square);
  ob[0]->setBoundary(sin, sout);
  // Add objects to input map
  im->addObstacle(ob);
  im->setWorkspace(std::move(_ws));
  // Send map object to path display
  pathDisp.updateInputMap(std::move(im));
  // Get Path Output
  sin.str("");
  sout.str("");
  pathDisp.displayPath(sout,path);
  std::string configSpaceStr = "\n+ + + + + + + + \n"
      "+             + \n"
      "+   S         + \n"
      "+     X E     + \n"
      "+             + \n"
      "+             + \n"
      "+             + \n"
      "+ + + + + + + + \n";

  // Assert
  ASSERT_STREQ(sout.str().c_str(), configSpaceStr.c_str());

}
