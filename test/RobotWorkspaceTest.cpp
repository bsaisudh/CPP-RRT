/*
 * @file RobotWorkspaceTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author: Bala Murali Manoghar Sai Sudhakar
 * @brief Testing RobotWorksapce class
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

/**
 * @brief RobotWorkspace class test fixture
 */
struct RobotWorkspaceTest : public testing::Test {
  RobotWorkspace *ws;
  void SetUp() {
    ws = new RobotWorkspace;
    std::stringstream sout;
    std::stringstream sin;
    sin.str("");
    sout.str("");
    sin << "10 10 9 9 2 2 ";
    ws->setBoundary(sin, sout);
    ws->setGoal(sin, sout);
    ws->setStart(sin, sout);
    sin.str("");
    sout.str("");
  }
  void TearDown() {
    delete ws;
  }
};

/**
 * @brief Testing RobotWorkspace initialization
 */
TEST(RobotWorkSpaceClass, Initialization) {
  // Assert
  RobotWorkspace robotWs;
  std::stringstream sout;
  std::stringstream sin;
  // Act
  sin.str("");
  sout.str("");
  sin << "10 10 9 9 2 2 ";
  robotWs.setBoundary(sin, sout);
  robotWs.setGoal(sin, sout);
  robotWs.setStart(sin, sout);
  sin.str("");
  sout.str("");
  robotWs.dispWorkspace(sout);
  // Test
  ASSERT_STREQ(
      sout.str().c_str(),
      "Start point :2 , 2\nGoal point :9 , 9\nWorkspace : ( 0 , 0 ) ( 10 , 10)\n");
}

/**
 * @brief Testing if point is inside square obstacle or not
 */

TEST_F(RobotWorkspaceTest , ComputeAndGetMethods) {
  ASSERT_EQ(ws->inWorkspace(5,5), true);
  ASSERT_EQ(ws->inWorkspace(115,115), false);
  ASSERT_EQ(ws->isGoal(9,9), true);
  ASSERT_EQ(ws->isGoal(7,7), false);
  ASSERT_EQ(ws->isStart(2,2), true);
  ASSERT_EQ(ws->isStart(3,3), false);
  ASSERT_EQ(ws->getmaxX(), 10);
  ASSERT_EQ(ws->getmaxY(), 10);
}
