/*
 * @file ObstacleTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay Rajaraman
 * @brief Demo for RRT Algorithm
 */

/*! \mainpage RRT algorithm implemented in C++ using oops concepts
 *
 * \section Overview
 *
 *Path planning for a point robot using Rapidly Exploring Random Trees (RRT)
 *on a known 2D space.
 *The algorithm returns coordinate points in the path,
 *which when interfaced with a simple position control
 *system can be used to drive a robot in the planned path.
 *Path RRTs are kinodynamic planners that can be used to
 *calculate the trajectory of a robot in real time
 *Given that the algorithm uses incremental motions,
 *it can be used in Collision detection.
 *The RRT algorithm can be used to produce good guesses
 *for variational optimization techniques.
 *
 * \section RRT ALGORITHM
 * 1.Sample a random point from the configuration space.
 * 2.Obtain a point on the tree closest to the sampled point,
 *    in the direction of the point at a unit distance.
 * 3.Verify if this point is in contact with any obstacle.
 * 4.If the new point is not in contact with or within any obstacles
 *    then add this point to the tree.
 * 5.If the new point is in contact with or within any obstacles,
 *    then add the point closest to the tree that is just outside the obstacle to the tree.
 * 6.The points added to the tree are removed from the sampling space.
 * 7.This is recursively performed till the point within unit distance
 *    of the goal point is reached.
 *
 * \section Project Specifics
 * Programming Language - C++
 * Build Platform – Make, GCC Compiler
 * Source code control - GIT and GitHub
 * Build testing – Travis CI
 * Test coverage - Coveralls
 *
 * \section Agile Process
 * [Sheet Link](https://docs.google.com/spreadsheets/d/1cJVLNv9pZ2T4a17OsMPn_WnxRS6tAkfYJKaMcSRo6MA/edit?usp=sharing)
 *
 * \section Class Diagram
 * \image html ..\UML\Revised\classDescriptions.png
 */


#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <sstream>

#include "../include/InputMap.h"
#include "../include/RobotWorkspace.h"
#include "../include/Obstacle.h"
#include "../include/Square.h"
#include "../include/Circle.h"
#include "../include/PathDisplay.h"
#include "../include/RRT.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Demo function to perform RRT path planning algorithm
 */
int main() {
  cout << "***********************************************\n"
       "*--------------RRT PATH PLANNING--------------*\n"
       "***********************************************\n"
       "\n\n"
       "Do you want to run demo with pre defined map [y/n]: ";
  char decision;
  std::cin >> decision;
  cout << "\n\n\n\n";
  if (!(decision == 'N' || decision == 'n')) {
    // Pre defined input map Section
    std::stringstream sout;
    std::stringstream sin;
    std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);
    // Set arena boundary
    sin.str("");
    sout.str("");
    sin << "10 10 ";
    _ws->setBoundary(sin, sout);
    // Set Start Point
    sin.str("");
    sout.str("");
    sin << "1 1 ";
    _ws->setStart(sin, sout);
    // Set Goal Point
    sin.str("");
    sout.str("");
    sin << "9 9 ";
    _ws->setGoal(sin, sout);
    // Set obstacles
    vector<std::shared_ptr<Obstacle>> ob;
    ob.emplace_back(new Square);
    sin.str("");
    sout.str("");
    sin << "5 5 2 ";
    ob[0]->setBoundary(sin, sout);
    // Add obstacles and workspace to input map and compute configuration space
    std::shared_ptr<InputMap> im(new InputMap);
    im->addObstacle(ob);
    im->setWorkspace(std::move(_ws));
    im->computeConfigSpace();
    // Create RRT Algorithm instance and send input map
    // Get computed path using RRT algorithm
    std::shared_ptr<RRT> rrt(new RRT);
    rrt->Map = std::move(im);
    std::vector<point> path = rrt->buildPath();
    // Create Display object and display path with map
    PathDisplay pathDisp;
    pathDisp.updateInputMap(std::move(rrt->Map));
    pathDisp.displayPath(std::cout, path);

  } else {
    // Custom map input section
    // Get input map form user
    std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);
    // Get arena boundary from user and display workspace
    _ws->setBoundary(cin, cout);
    _ws->setStart(cin, cout);
    _ws->setGoal(cin, cout);
    _ws->dispWorkspace(cout);
    cout << "Enter number of obstacles : ";
    // Get Obstacles from user
    int noOb;
    cin >> noOb;
    vector<std::shared_ptr<Obstacle>> ob;
    for (int i = 0; i < noOb; i++) {
      int obType;
      cout << "Enter type: \n 1. Square \n 2. Circle\n";
      cin >> obType;
      switch (obType) {
        case 1:
          ob.emplace_back(new Square);
          ob[i]->setBoundary(cin, cout);
          break;
        case 2:
          ob.emplace_back(new Circle);
          ob[i]->setBoundary(cin, cout);
          break;
        default:
          cout << "By default square obstacle is considered\n";
          ob.emplace_back(new Square);
          ob[i]->setBoundary(cin, cout);
          break;
      }
    }
    // Display obstacle boundaries
    for (const auto& i : ob) {
      i->dispBoundary(cout);
    }
    // Create and update input map from inputs obtained form user
    std::shared_ptr<InputMap> im(new InputMap);
    im->addObstacle(ob);
    im->setWorkspace(std::move(_ws));
    im->computeConfigSpace();
    // Find path usingRRT algorithm
    std::shared_ptr<RRT> rrt(new RRT);
    rrt->Map = std::move(im);
    std::vector<point> path = rrt->buildPath();
    // Display Path
    PathDisplay pathDisp;
    pathDisp.updateInputMap(std::move(rrt->Map));
    pathDisp.displayPath(std::cout, path);
  }
  cout << "\n\n\n\n";
  return 0;
}
