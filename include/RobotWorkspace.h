/*
 * @file RobotWorkspace.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief RobotWorkspace Class functions
 */

#ifndef INCLUDE_ROBOTWORKSPACE_H_
#define INCLUDE_ROBOTWORKSPACE_H_

#include <iostream>

/**
 * @brief Class holds arena properties
 *
 * Map properties like start point,
 * goal point are stored here
 */
class RobotWorkspace {
 public:
  // !<Total arena maximum length and width
  int maxX, maxY;
  // !<Start point of robot
  int startX, startY;
  // !<Goal point of robot
  int goalX, goalY;
  /**
   * @brief Constructor to initialize all variables
   * @param None
   * @return None
   */
  RobotWorkspace();
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~RobotWorkspace();
  /**
   * @brief Gets arena boundary from user and stores the values
   * @param Input and output stream references
   * @return None
   */
  void setBoundary(std::istream &in, std::ostream &out);
  /**
   * @brief Checks if a point is inside robot workspace
   * @param X and Y co-ordinate of point to be checked
   * @return True or False depending on the result
   */
  bool inWorkspace(int xCoor, int yCoor);
  /**
   * @brief Gets start point form user and stores the values
   * @param Input and output stream references
   * @return None
   */
  void setStart(std::istream &in, std::ostream &out);
  /**
   * @brief Gets goal point form user and stores the values
   * @param Input and output stream references
   * @return None
   */
  void setGoal(std::istream &in, std::ostream &out);
  /**
   * @brief Checks if a point is the goal point of robot
   * @param X and Y co-ordinate of point to be checked
   * @return True or False depending on the result
   */
  bool isGoal(int xCoor, int yCoor);
  /**
   * @brief Checks if a point is start point of robot
   * @param X and Y co-ordinate of point to be checked
   * @return True or False depending on the result
   */
  bool isStart(int xCoor, int yCoor);
  /**
   * @brief Displays the workspace co-ordinates to user
   * @param Output stream reference
   * @return None
   */
  void dispWorkspace(std::ostream &out);
  /**
   * @brief Get max x co-ordinate of robot workspace
   * @param None
   * @return Max value of workspace as integer
   */
  int getmaxX();
  /**
   * @brief Get max Y co-ordinate of robot workspace
   * @param None
   * @return Max value of workspace as integer
   */
  int getmaxY();
};

#endif /* INCLUDE_ROBOTWORKSPACE_H_ */
