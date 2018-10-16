///*
// * @file InputMapTest.cpp
// * @Copyright MIT license
// * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
// * @author: Bala Murali Manoghar Sai Sudhakar
// * @brief Testing InputMap class
// */
//
// #include <gtest/gtest.h>
// #include <gmock/gmock.h>
// #include <sstream>
// #include <iostream>
// #include <string>
// #include <vector>
//
// #include "../include/InputMap.h"
// #include "../include/RobotWorkspace.h"
// #include "../include/Obstacle.h"
// #include "../include/Square.h"
// #include "../include/Circle.h"
//
// using ::testing::AtLeast;
// using ::testing::Return;
//
//
// class MockRobotWorkspace : public RobotWorkspace {
// public:
//  MOCK_METHOD0(getmaxX, int());
//  MOCK_METHOD0(getmaxY, int());
//
////  virtual ~RobotWorkspace();
////  void setBoundary(std::istream &in , std::ostream &out);
////  bool inWorkspace(int xCoor, int yCoor);
////  void setStart(std::istream &in , std::ostream &out);
////  void setGoal(std::istream &in , std::ostream &out);
////  bool isGoal(int xCoor, int yCoor);
////  bool isStart(int xCoor, int yCoor);
////  void dispWorkslace(std::ostream &out);
////  int getmaxX();
////  int getmaxY();
//};
//
//
// TEST(InputMapTest,initialization) {
//  // Arrange
//  MockRobotWorkspace mockRws;
//  InputMap im(mockRws);
//  EXPECT_CALL(mockRws, getmaxX()).Times(50).WillRepeatedly(Return(10));
//  EXPECT_CALL(mockRws, getmaxY()).Times(50).WillRepeatedly(Return(10));
//
//  std::vector<std::shared_ptr<Obstacle>> ob;
//  std::stringstream sout;
//  std::stringstream sin;
//  sin.str("");
//  sout.str("");
//  // Add Square 1
//  ob.emplace_back(new Square);
//  sin << "1 1 9";
//  ob[1]->setBoundary(sin, sout);
//
//  // Act
//  im.computeConfigSpace();
//  sin.str("");
//  sout.str("");
//  im.dispConfigSpace(sout);
//  // Assert
//  ASSERT_STREQ(sout.str().c_str(), "test");
//
//}
//
