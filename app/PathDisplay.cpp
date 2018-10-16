/*
 * PathDisplay.cpp
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */

#include <vector>
#include <iostream>

#include "../include/PathDisplay.h"

PathDisplay::PathDisplay() {
  // TODO Auto-generated constructor stub

}

void PathDisplay::updateInputMap(std::shared_ptr<InputMap> _iMap) {
  iMap = std::move(_iMap);
}

void PathDisplay::displayPath(std::ostream &out) {
  char map[iMap->ws->maxX + 2][iMap->ws->maxY + 2];

  for (int i = 0; i < iMap->ws->maxX + 2; i++) {
    for (int j = 0; j < iMap->ws->maxY + 2; j++) {
      map[i][j] = ' ';
    }
  }

  for (int i = 0; i < iMap->ws->maxX + 2; i++) {
    map[i][0] = '+';
    map[i][iMap->ws->maxY + 1] = '+';
  }
  for (int j = 0; j < iMap->ws->maxY + 2; j++) {
    map[0][j] = '+';
    map[iMap->ws->maxX + 1][j] = '+';
  }

  std::vector<point> obMap;
  obMap.clear();
  for (auto &i : iMap->ob) {
    i->fillObstacle(obMap);
  }
  for (auto &i : obMap) {
    map[i.x + 1][i.y + 1] = 'X';
  }
  map[iMap->ws->startX + 1][iMap->ws->startX + 1] = 'S';
  map[iMap->ws->goalX + 1][iMap->ws->goalY + 1] = 'E';
  out << std::endl;
  for (int i = 0; i < iMap->ws->maxX + 2; i++) {
    for (int j = 0; j < iMap->ws->maxY + 2; j++) {
      out << map[i][j] << " ";
    }
    out << std::endl;
  }
}

PathDisplay::~PathDisplay() {
// TODO Auto-generated destructor stub
}

