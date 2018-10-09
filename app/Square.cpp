/*
 * Square.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: bala
 */

#include "Square.h"
#include <iostream>

Square::Square()
    : startX(0),
      startY(0),
      side(0) {
}

void Square::setBoundary() {
  std::cout << "Enter StartX :";
  std::cin >> startX;
  std::cout << "Enter StartY :";
  std::cin >> startY;
  std::cout << "Enter Side :";
  std::cin >> side;
}

void Square::dispBoundary() {
  std::cout << "StartX:" << startX << " StartY :" << startY << " Side: " << side
            << std::endl;
}

bool Square::inObstacle(int xCoord, int yCoord) {
  if (xCoord >= startX && xCoord <= startX + side && yCoord >= startY
      && yCoord <= startY + side) {
    return true;
  } else {
    return false;
  }
}

Square::~Square() {
  // TODO Auto-generated destructor stub
}

