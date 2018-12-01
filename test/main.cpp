/*
 * @file Main.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Main test class
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(throw_on_failure) = true;
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
