/*
 * @file PathDisplay.h
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief PathDisplay Class functions
 */

#ifndef INCLUDE_PATHDISPLAY_H_
#define INCLUDE_PATHDISPLAY_H_

#include <vector>
#include <memory>

#include "../include/InputMap.h"

/**
 * @brief Class to display path along with arena to user.
 */
class PathDisplay {
 public:
  // !< InputMap shared pointer
  std::shared_ptr<InputMap> iMap;
  /**
   * @brief Constructor to initialize all variables
   * @param None
   * @return None
   */
  PathDisplay();
  /**
   * @brief Updates the input map object
   * @param Shared pointer to input map object
   * @return None
   */
  void updateInputMap(std::shared_ptr<InputMap> _iMap);
  /**
   * @brief Displays path and robot arena to user
   * @param Input and output stream references
   * @return None
   */
  void displayPath(std::ostream &out, std::vector<point> &path);
  /**
   * @brief Destructor to free up space once object goes out of scope
   * @param None
   * @return None
   */
  virtual ~PathDisplay();
};

#endif /* INCLUDE_PATHDISPLAY_H_ */
