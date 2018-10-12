/*
 * PathDisplay.h
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#ifndef APP_PATHDISPLAY_H_
#define APP_PATHDISPLAY_H_

#include <vector>

class PathDisplay {
 private:
  std::vector<int[2]> path;

 public:
  PathDisplay();
  void displayPath();
  virtual ~PathDisplay();
};

#endif /* APP_PATHDISPLAY_H_ */
