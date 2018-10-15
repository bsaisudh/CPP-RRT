/*
 * Circle.cpp
 *
 *  Created on: Oct 12, 2018
 *      Author: bala
 */



#include "../include/Circle.h"

Circle::Circle()
    : centerX(0),
      centerY(0),
      radius(0) {
  // TODO Auto-generated constructor stub

}

bool Circle::checkValidity() {
  return true;
}

void Circle::setBoundary(std::istream &in , std::ostream &out) {
  out << "Enter Center point :";
  in >> centerX;
  out << "Enter Center point :";
  in >> centerY;
  out << "Enter Radius:";
  in >> radius;
}

void Circle::dispBoundary(std::ostream &out) {
  out << "Center X :" << centerX
      << " Center Y :" << centerY
      << " Radius :" << radius
      << std::endl;
}

bool Circle::inObstacle(int coordX, int coordY) {
  int dist = 0;
  dist = ((centerX - coordX)*(centerX - coordX)) + ((centerY - coordY)*(centerY - coordY)) ;
  return dist <= radius*radius;
}

Circle::~Circle() {
// TODO Auto-generated destructor stub
}

