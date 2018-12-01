/*
 * @file MockTestSquare.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @brief mock test for square class
 */

/*
 * MIT License
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>
#include <iostream>
#include <string>

#include "../include/Square.h"

using ::testing::Return;
using ::testing::_;

/**
 * @brief Mock class for Square class
 */
class MockSq : public Square {
 public:
    MOCK_METHOD2(setBoundary, void(std::istream &in, std::ostream &out));
    MOCK_METHOD1(dispBoundary, void(std::ostream &out));
    MOCK_METHOD2(inObstacle, bool(int xCoord, int yCoord));
    MOCK_METHOD1(fillObstacle, void(std::vector<point> &obMap));
};

/**
 * @brief Testing the setBoundary function mock
 */
TEST(SquareMock,setboundary){
  MockSq Sq;
  std::stringstream sout;
  std::stringstream sin;
  EXPECT_CALL(Sq, setBoundary(_,_))
      .Times(2);
  sin.str("");
  sout.str("");
  sin << "5 5 2 ";
  Sq.setBoundary(sin, sout);
  sin.str("");
  sout.str("");
  sin << "5 5 2 ";
  Sq.setBoundary(sin, sout);
}

/**
 * @brief Testing the inObstacle function mock
 */
TEST(SquareMock,inobstacle){
  MockSq Sq;
  EXPECT_CALL(Sq, inObstacle(_,_))
      .Times(2)
      .WillOnce(Return(true))
      .WillOnce(Return(false));
  EXPECT_EQ(true, Sq.inObstacle(5, 10));
  EXPECT_EQ(false, Sq.inObstacle(20, 10));
}
