/*
 * PathDisplay.h
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#ifndef APP_PATHDISPLAY_H_
#define APP_PATHDISPLAY_H_

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

#endif /* APP_PATHDISPLAY_H_ */
