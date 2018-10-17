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

class PathDisplay {
 public:
  std::shared_ptr<InputMap> iMap;
  PathDisplay();
  void updateInputMap(std::shared_ptr<InputMap> _iMap);
  void displayPath(std::ostream &out, std::vector<point> &path);
  virtual ~PathDisplay();
};

#endif /* INCLUDE_PATHDISPLAY_H_ */
