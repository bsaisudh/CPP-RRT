/*
 * @file InputMapTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Testing InputMap class
 */

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <gmock/gmock.h>

#include "../include/InputMap.h"
#include "../include/RobotWorkspace.h"
#include "../include/Obstacle.h"
#include "../include/Square.h"
#include "../include/Circle.h"

/*
 class MockOb : public Obstacle{
 public:
 MOCK_METHOD2(setBoundary, void(std::istream &in, std::ostream &out));
 MOCK_METHOD1(dispBoundary, void(std::ostream &out));
 MOCK_METHOD2(inObstacle, bool(int xCoord, int yCoord));
 MOCK_METHOD1(fillObstacle, void(std::vector<point> &obMap));
 };

 TEST(MockTest, Test){
 // Arrange
 MockOb obs;
 std::stringstream sout;
 std::stringstream sin;
 std::vector<std::shared_ptr<Obstacle>> ob;

 // EXPECT_CALL(obs,inObstacle(2,2)).Times(1);
 sin.str("");
 sout.str("");
 sin << "2 2 1 ";
 //ob.emplace_back(new MockOb);
 //ob[0]->setBoundary(sin, sout);

 // Assert
 }
 */

/**
 * @brief Testing input map computation
 */
TEST(InputMapclass, ConfigSpaceCreation) {
  // Arrange
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
  sin.str("");
  sout.str("");
  im->dispConfigSpace(sout);
  std::string configSpaceStr = "(0 , 0)\n(0 , 1)\n(0 , 2)\n(0 , 3)\n(0 , 4)\n"
      "(0 , 5)\n(1 , 0)\n(1 , 1)\n(1 , 2)\n(1 , 3)\n(1 , 4)\n"
      "(1 , 5)\n(2 , 0)\n(2 , 1)\n(2 , 4)\n(2 , 5)\n(3 , 0)\n"
      "(3 , 1)\n(3 , 4)\n(3 , 5)\n(4 , 0)\n(4 , 1)\n(4 , 2)\n"
      "(4 , 3)\n(4 , 4)\n(4 , 5)\n(5 , 0)\n(5 , 1)\n(5 , 2)\n"
      "(5 , 3)\n(5 , 4)\n(5 , 5)\n";

  // Assert
  ASSERT_STREQ(sout.str().c_str(), configSpaceStr.c_str());
}

/**
 * @brief Testing input map Set Workspace
 */
TEST(InputMapclass, SetWorkspaceTest) {
  // Arrange
  std::stringstream sout;
  std::stringstream sin;
  std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);

  // Act
  // Add Workspace
  sin.str("");
  sout.str("");
  sin << "6 6 1 1 2 3 ";
  _ws->setBoundary(sin, sout);
  _ws->setStart(sin, sout);
  _ws->setGoal(sin, sout);
  // Add objects to input map
  std::shared_ptr<InputMap> im(new InputMap);
  im->setWorkspace(std::move(_ws));
  // Act
  sin.str("");
  sout.str("");
  im->ws->dispWorkspace(sout);
  std::string configSpaceStr = "Start point :1 , 1\n"
      "Goal point :2 , 3\n"
      "Workspace : ( 0 , 0 ) ( 6 , 6)\n";
  // Assert
  ASSERT_STREQ(sout.str().c_str(), configSpaceStr.c_str());
}

/**
 * @brief Testing obstacle
 */
TEST(InputMapclass, AddObstacleTest) {
  // Arrange
  std::stringstream sout;
  std::stringstream sin;
  std::vector<std::shared_ptr<Obstacle>> ob;

  // Act
  // Add Square
  sin.str("");
  sout.str("");
  sin << "2 2 1 ";
  ob.emplace_back(new Square);
  ob[0]->setBoundary(sin, sout);
  // Add objects to input map
  std::shared_ptr<InputMap> im(new InputMap);
  im->addObstacle(ob);

  // Act
  sin.str("");
  sout.str("");
  im->ob[0]->dispBoundary(sout);
  std::string configSpaceStr = "StartX:2 StartY :2 Side: 1\n";

  // Assert
  ASSERT_STREQ(sout.str().c_str(), configSpaceStr.c_str());
}
