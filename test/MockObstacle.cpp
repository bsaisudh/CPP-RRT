/*
 * @file ObstacleTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief testing obstacle and its derived class
 */
#include <vector>
#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Obstacle.h"


using ::testing::_;
using ::testing::AtLeast;

class MockObstacle : public Obstacle {
 public:
  MOCK_METHOD2(setBoundary, void(std::istream &in , std::ostream &out));
  MOCK_METHOD2(inObstacle, bool(int xCoord, int yCoord));
  MOCK_METHOD1(dispBoundary, void(std::ostream &out));
  MOCK_METHOD1(fillObstacle, void(std::vector<point> &obMap));
};

TEST(MockObstacleTest, isInObstacle) {
  MockObstacle obstacle;
  std::vector<point> obMap;
  EXPECT_CALL(obstacle, inObstacle(_, _)).Times(0);
}

