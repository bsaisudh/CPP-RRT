/*
 * @file ObstacleTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author: Bala Murali Manoghar Sai Sudhakar
 * @brief testing obstacle and its derived class
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
    std::stringstream sout;
    std::stringstream sin;
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
  // Assert
  Square square;
  std::stringstream sout;
  std::stringstream sin;
  // Act
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  square.setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  square.dispBoundary(sout);
  // Test
  ASSERT_STREQ(sout.str().c_str(), "StartX:2 StartY :2 Side: 2\n");
}

/**
 * @brief Testing if point is inside square obstacle or not
 */
TEST_F(SquareTest , insideOutsideObstacle) {
  ASSERT_EQ(sq->inObstacle(10, 10), false);
  ASSERT_EQ(sq->inObstacle(3, 3), true);
}

/**
 * @brief Circle class test fixture
 */
struct CircleTest : public testing::Test {
  Circle *cir;
  void SetUp() {
    cir = new Circle;
    std::stringstream sout;
    std::stringstream sin;
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
  // Assert
  Circle circle;
  std::stringstream sout;
  std::stringstream sin;
  // Act
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  circle.setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  circle.dispBoundary(sout);
  // Test
  ASSERT_STREQ(sout.str().c_str(), "Center X :2 Center Y :2 Radius :2\n");
}

/**
 * @brief Testing if point is inside circle obstacle or not
 */
TEST_F(CircleTest , insideOutsideObstacle) {
  ASSERT_EQ(cir->inObstacle(10, 10), false);
  ASSERT_EQ(cir->inObstacle(3, 3), true);
}

/**
 * @brief Obstacle Circle class test fixture for overriding
 */
struct ObstacleCircleTest : public testing::Test {
  Obstacle *ob_cir;
  void SetUp() {
    ob_cir = new Circle;
    std::stringstream sout;
    std::stringstream sin;
    sin.str("");
    sout.str("");
    sin << "2 2 2 ";
    ob_cir->setBoundary(sin, sout);
    sin.str("");
    sout.str("");
  }
  void TearDown() {
    delete ob_cir;
  }
};

/**
 * @brief Testing circle initialization fir overriding
 */
TEST(ObstacleCircleClass, Initialization) {
  // Assert
  Obstacle *ob_circle(new Circle);
  std::stringstream sout;
  std::stringstream sin;
  // Act
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  ob_circle->setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  ob_circle->dispBoundary(sout);
  // Test
  ASSERT_STREQ(sout.str().c_str(), "Center X :2 Center Y :2 Radius :2\n");
}

/**
 * @brief Testing if point is inside circle obstacle or not through overriding
 */
TEST_F(ObstacleCircleTest , insideOutsideObstacle) {
  ASSERT_EQ(ob_cir->inObstacle(10, 10), false);
  ASSERT_EQ(ob_cir->inObstacle(3, 3), true);
}

/**
 * @brief Obstacle square class test fixture for overriding
 */
struct ObstacleSquareTest : public testing::Test {
  Obstacle *ob_sq;
  void SetUp() {
    ob_sq = new Square;
    std::stringstream sout;
    std::stringstream sin;
    sin.str("");
    sout.str("");
    sin << "2 2 2 ";
    ob_sq->setBoundary(sin, sout);
    sin.str("");
    sout.str("");
  }
  void TearDown() {
    delete ob_sq;
  }
};

/**
 * @brief Testing square class initialization for overriding
 */
TEST(ObstaclesquareClass, Initialization) {
  // Assert
  Obstacle *ob_square(new Square);
  std::stringstream sout;
  std::stringstream sin;
  // Act
  sin.str("");
  sout.str("");
  sin << "2 2 2 ";
  ob_square->setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  ob_square->dispBoundary(sout);
  // Test
  ASSERT_STREQ(sout.str().c_str(), "StartX:2 StartY :2 Side: 2\n");
}

/**
 * @brief Testing if point is inside circle obstacle or not through overriding
 */
TEST_F(ObstacleSquareTest , insideOutsideObstacle) {
  ASSERT_EQ(ob_sq->inObstacle(10, 10), false);
  ASSERT_EQ(ob_sq->inObstacle(3, 3), true);
}

