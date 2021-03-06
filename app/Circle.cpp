/*
 * @file Circle.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Circle class implementation
 */

#include "../include/Circle.h"

Circle::Circle()
    : centerX(0),
      centerY(0),
      radius(0) {
}

void Circle::setBoundary(std::istream &in, std::ostream &out) {
  out << "Enter Center point :";
  in >> centerX;
  out << "Enter Center point :";
  in >> centerY;
  out << "Enter Radius:";
  in >> radius;
}

void Circle::dispBoundary(std::ostream &out) {
  out << "Center X :" << centerX << " Center Y :" << centerY << " Radius :"
      << radius << std::endl;
}

bool Circle::inObstacle(int coordX, int coordY) {
  int dist = 0;
  // Calculate distance using two point formula
  // \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$
  dist = ((centerX - coordX) * (centerX - coordX))
      + ((centerY - coordY) * (centerY - coordY));
  // return if calculated distance is less than radius of circle
  return dist <= radius * radius;
}

void Circle::fillObstacle(std::vector<point> &obMap) {
  point p;
  // Traverse through points treating circle as square side
  //length is equal to diameter
  for (int i = (centerX - radius); i < (centerX + radius); i++) {
    for (int j = (centerY - radius); j < (centerY + radius); j++) {
      if (inObstacle(i, j)) {
        // add point of the point is inside circle
        p.x = i;
        p.y = j;
        obMap.emplace_back(p);
      }
    }
  }
}

Circle::~Circle() {
}

