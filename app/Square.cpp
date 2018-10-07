/*
 * Square.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: bala
 */

#include "Square.h"
#include <iostream>

Square::Square() {
  startx = 0;
  starty = 0;
  side = 0;
  // TODO Auto-generated constructor stub

}

void Square::setBoundary(){
  std::cout << "enter 3 nos" << std::endl;
  std::cin >> startx >> starty >> side;
}

void Square::dispBoundary(){
  std::cout << "1:" << startx << " 2 :" << starty << " 3: " << side;
}

Square::~Square() {
  // TODO Auto-generated destructor stub
}

