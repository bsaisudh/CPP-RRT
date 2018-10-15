/*
 * @file ObstacleTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author: Bala Murali Manoghar Sai Sudhakar
 *
 */

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>

#include "../include/Obstacle.h"
#include "../include/Square.h"
#include "../include/Circle.h"

/**
 * @brief Square class test fixture
 */
struct SquareTest : public testing::Test {
  Square *sq;
  void SetUp() {
    sq = new Square;
    std::stringstream sin;
    std::stringstream sout;
    sin.str("");
    sout.str("");
    sin << "2 2 2 ";
    sq->setBoundary(sin, sout);
    sin.str("");
    sout.str("");
  }
  void TearDown() {
    delete sq;
  }
};

/**
 * @brief Testing square initialization
 */
TEST(SquareClass, Initialization) {
  //Assert
  Square square;
  //Act
  std::stringstream sin;
  std::stringstream sout;
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  square.setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  square.dispBoundary(sout);
//  Test
  ASSERT_STREQ(sout.str().c_str(), "StartX:2 StartY :2 Side: 2\n");
}

/**
 * @brief Testing if point is inside square obstacle or not
 */
TEST_F(SquareTest , insideOutsideObstacle) {
  ASSERT_EQ(sq->inObstacle(10,10),false);
  ASSERT_EQ(sq->inObstacle(3,3),true);
}


/**
 * @brief Square class test fixture
 */
struct CircleTest : public testing::Test {
  Circle *cir;
  void SetUp() {
    cir = new Circle;
    std::stringstream sin;
    std::stringstream sout;
    sin.str("");
    sout.str("");
    sin << "2 2 2 ";
    cir->setBoundary(sin, sout);
    sin.str("");
    sout.str("");
  }
  void TearDown() {
    delete cir;
  }
};

/**
 * @brief Testing circle initialization
 */
TEST(CircleClass, Initialization) {
  //Assert
  Circle circle;
  //Act
  std::stringstream sin;
  std::stringstream sout;
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  circle.setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  circle.dispBoundary(sout);
//  Test
  ASSERT_STREQ(sout.str().c_str(), "Center X :2 Center Y :2 Radius :2\n");
}

/**
 * @brief Testing if point is inside square obstacle or not
 */
TEST_F(CircleTest , insideOutsideObstacle) {
  ASSERT_EQ(cir->inObstacle(10,10),false);
  ASSERT_EQ(cir->inObstacle(3,3),true);
}

