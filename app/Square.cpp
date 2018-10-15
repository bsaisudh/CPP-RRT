/*
 * Square.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: bala
 */

#include "Square.h"

Square::Square()
    : startX(0),
      startY(0),
      side(0) {
}

bool Square::checkValidity() {
  return true;
}

void Square::setBoundary(std::istream &in , std::ostream &out) {
  out << "Enter StartX :";
  in >> startX;
  out << "Enter StartY :";
  in >> startY;
  out << "Enter Side :";
  in >> side;
}

void Square::dispBoundary(std::ostream &out) {
  out << "StartX:" << startX << " StartY :" << startY << " Side: " << side
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

